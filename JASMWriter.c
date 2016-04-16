#include "JASMWriter.h"

typedef struct BlockLabelNode {
	int label1;
	int label2;
	struct BlockLabelNode * outer;
} BlockLabelNode;

void pushNewLabelBlock();
void popNewLabelBlock();

int lastWriteLabel;
FILE * jasmFile;
char * jasmFileName;
char * jasmClassName;
char writerEnabled;
int indentCounter;
int jumpLabelCounter;
BlockLabelNode * topBlock;

char doWriteReturn;

char * getClassName(const char * fileName);
FILE * createJASMFile(const char * className);
void redirectInput(const char * fileName);
void openBracket();
void closeBracket();
void indent();
void outdent();

void startWriteClass(const char * className);
void endWriteClass();

const char * mapTypeStr(int expType);
int getNewLabel();

void stackCondition(const char * conditionalCode);
void iVarPreXcr(const VarRow * var, int amt);
void iVarPosXcr(const VarRow * var, int amt);

void writeFuncArg(ArgNode * args);
void noIndentJPrint(const char * format, ...);
void noNewlineJPrint(const char * format, ...);
void catJPrint(const char * format, ...);
void printIndent();
void declareLabel(int labelNum);
void printLabelSpilter();

void prepareJASM(const char * fileName) {
	redirectInput(fileName);

	jasmClassName = getClassName(fileName);
	jasmFile = createJASMFile(jasmClassName);
	enableWriter(1);
	startWriteClass(jasmClassName);

}

void closeJASM(int parseResult) {
	if (parseResult != 0) {
		fclose(jasmFile);
		remove(jasmFileName);
		return;
	}

	endWriteClass();
	fflush(jasmFile);
	fclose(jasmFile);

	free(jasmFileName);
	free(jasmClassName);

}

void enableWriter(char enabled) {
	writerEnabled = enabled;
}

void redirectInput(const char * fileName) {
	freopen(fileName, "r", stdin);
}

char * getClassName(const char * fileName) {
	const char * dotPtr = strrchr(fileName, '.');
	const char * slashPtr = strrchr(fileName, '/');
	const char * classNameStartingPtr = slashPtr == NULL? fileName : (slashPtr + 1);
	int classNameLen = dotPtr - classNameStartingPtr;

	char * className = (char *)malloc(classNameLen * sizeof(char) + 1);
	strncpy(className, classNameStartingPtr, classNameLen);
	
	return className;
}

FILE * createJASMFile(const char * className) {
	jasmFileName = (char *)malloc(strlen(className) + 6);
	sprintf(jasmFileName, "%s.jasm", className);
	return fopen(jasmFileName, "w");
}
void openBracket() {
	jprint("{");
	indent();
}

void closeBracket() {
	outdent();
	jprint("}");
}


void indent() {
	indentCounter++;
}

void outdent() {
	indentCounter--;
}

void startWriteClass(const char * className) {
	jumpLabelCounter = indentCounter = 0;
	doWriteReturn = 0;
	topBlock = NULL;
	lastWriteLabel = 0;
	jprint("class %s ", className);
	openBracket();
}

void endWriteClass() {
	closeBracket();
}

void startWriteMainMethod() {
	jprint("method public static void main(java.lang.String[])");
	jprint("max_stack 15");
	jprint("max_locals 15");
	openBracket();
}

void endWriteMainMethod() {
	writeReturn();
	closeBracket();
}

void writeReturn() {
	jprint("return");
}

void writeIReturn() {
	jprint("ireturn");
}

void startWriteIf() {
	pushNewLabelBlock();
	topBlock->label1 = getNewLabel();
	
	jprint("ifeq L%d", topBlock->label1);
}

void startWriteElse() {
	topBlock->label2 = getNewLabel();
	jprint("goto L%d", topBlock->label2);
	declareLabel(topBlock->label1);
}

void endWriteIf() {
	declareLabel(topBlock->label1);
	popNewLabelBlock();
}

void endWriteElse() {
	declareLabel(topBlock->label2);
	popNewLabelBlock();
}

void startWriteWhile() {
	pushNewLabelBlock();
	topBlock->label1 = getNewLabel();
	declareLabel(topBlock->label1);
}
void writeWhileEval() {
	topBlock->label2 = getNewLabel();
	jprint("ifeq L%d", topBlock->label2);
}
void endWriteWhile() {
	jprint("goto L%d", topBlock->label1);
	declareLabel(topBlock->label2);
	popNewLabelBlock();
}

void pushNewLabelBlock() {
	if (topBlock) {
		BlockLabelNode * newTopBlock = (BlockLabelNode * )malloc(sizeof(BlockLabelNode));
		newTopBlock->outer = topBlock;
		topBlock = newTopBlock;
	} else {
		topBlock = (BlockLabelNode * )malloc(sizeof(BlockLabelNode));
	}
}

void popNewLabelBlock() {
	if (topBlock) {
		BlockLabelNode * tmp = topBlock;
		topBlock = topBlock->outer;
		free(tmp);
	}
}

void startWriteFunction(VarRow * funcVar) {
	FuncInfo info = funcVar->content.funcVal;
	doWriteReturn = info.retType == VOID_T? 1 : 0;
	noNewlineJPrint("method public static %s %s", doWriteReturn? "void": "int", funcVar->id);
	writeFuncArg(info.args);
	
	
	jprint("max_stack 15");
	jprint("max_locals 15");
	openBracket();
}

void endWriteFunction() {
	if (doWriteReturn) {
		writeReturn();
		doWriteReturn = 0;
	}
	closeBracket();
}

void startPrint() {
	jprint("getstatic java.io.PrintStream java.lang.System.out");
	indent();
}

void endAsPrint(int expType) {
	outdent();
	jprint("invokevirtual void java.io.PrintStream.print(%s)", mapTypeStr(expType));
}

void endAsPrintln(int expType) {
	outdent();
	jprint("invokevirtual void java.io.PrintStream.println(%s)", mapTypeStr(expType));
}

const char * mapTypeStr(int expType) {
	switch(expType) {
		case INT_T:
			return "int";
		case BOOL_T:
			return "boolean";
		case STR_T:
			return "java.lang.String";
	}

	return NULL;
}

void globalIVarDeclarationNotInit(const char * varName) {
	jprint("field static int %s", varName);
}

void globalIVarDeclaration(const char * varName, int value) {
	jprint("field static int %s = %d", varName, value);
}

void iVarStore(const VarRow * var) {
	if (var->isGlobal) {
		jprint("putstatic int %s.%s", jasmClassName, var->id);
	} else {
		jprint("istore %d", var->num);
	}
}

void iVarLoad(const VarRow * var) {
	if (var->isGlobal) {
		jprint("getstatic int %s.%s", jasmClassName, var->id);
	} else {
		jprint("iload %d", var->num);
	}
}

void iVarPosIncr(const VarRow * var) {
	iVarPosXcr(var, 1);
}

void iVarPreIncr(const VarRow * var) {
	iVarPreXcr(var, 1);
}

void iVarPosDecr(const VarRow * var) {
	iVarPosXcr(var, -1);
}

void iVarPreDecr(const VarRow * var) {
	iVarPreXcr(var, -1);
}

void iVarPosXcr(const VarRow * var, int amt) {
	iVarLoad(var);
	// if (var->isGlobal) {
		jprint("dup");
		iConstPush(amt);
		stackAdd();
		iVarStore(var);
	// } else {
	// 	jprint("iinc %d, %d", var->num, amt);
	// }
}

void iVarPreXcr(const VarRow * var, int amt) {
	// if (var->isGlobal) {
		iVarLoad(var);
		iConstPush(amt);
		stackAdd();
		iVarStore(var);
	// } else {
	// 	jprint("iinc %d, %d", var->num, amt);
	// }
	iVarLoad(var);
}

void iConstPush(int constant) {
	if (constant == 1) {
		pushTrue();
	} else if (constant == 0) {
		pushFalse();
	} else {
		jprint("sipush %d", constant);
	}
}

void strConstPush(const char * constant) {
	jprint("ldc \"%s\"", constant);
}

void stackPop() {
	jprint("pop");
}

void stackNot() {
	pushTrue();
	jprint("ixor");
}

void stackAnd() {
	jprint("iand");
}

void stackOr() {
	jprint("ior");
}

void stackLess() {
	stackCondition("iflt");
}
void stackLessEq() {
	stackCondition("ifle");

}
void stackGreat() {
	stackCondition("ifgt");
}
void stackGreatEq() {
	stackCondition("ifge");
}
void stackEq() {
	stackCondition("ifeq");
}
void stackNotEq() {
	stackCondition("ifne");
}

void stackNeg() {
	jprint("ineg");
}
void stackAdd() {
	jprint("iadd");
}
void stackSub() {
	jprint("isub");
}
void stackMul() {
	jprint("imul");
}
void stackDiv() {
	jprint("idiv");
}
void stackRem() {
	jprint("irem");
}

void stackFuncInvok(const VarRow * funcVar) {
	noNewlineJPrint("invokestatic int %s.%s", jasmClassName, funcVar->id);
	writeFuncArg(funcVar->content.funcVal.args);
	
}

void writeFuncArg(ArgNode * args) {
	catJPrint("(");
	if (args) {
		catJPrint("int");
		for (args = args->next; args; args = args->next) {
			catJPrint(", int");
		}
	}
	noIndentJPrint(")");
}

int getNewLabel() {
	return jumpLabelCounter++;
}

void stackCondition(const char * conditionalCode) {
	stackSub();
	int labelTrue = getNewLabel();
	jprint("%s L%d", conditionalCode, labelTrue);
	pushFalse();
	int labelSkipTrue = getNewLabel();
	jprint("goto L%d", labelSkipTrue);

	declareLabel(labelTrue);
	pushTrue();

	declareLabel(labelSkipTrue);
}

void pushFalse() {
	jprint("iconst_0");
}

void pushTrue() {
	jprint("iconst_1");
}

void jnewline() {
	noIndentJPrint("");
}

void jprint(const char * format, ...) {
	if (!writerEnabled) {
		return;
	}

	va_list argList;
	va_start(argList, format);
	printIndent();
	vfprintf(jasmFile, format, argList);
	fprintf(jasmFile, "\n");
	va_end(argList);

	lastWriteLabel = 0;
}

void noIndentJPrint(const char * format, ...) {
	if (!writerEnabled) {
		return;
	}
	
	va_list argList;
	va_start(argList, format);
	vfprintf(jasmFile, format, argList);
	fprintf(jasmFile, "\n");
	va_end(argList);

	lastWriteLabel = 0;
}

void noNewlineJPrint(const char * format, ...) {
	if (!writerEnabled) {
		return;
	}
	
	va_list argList;
	va_start(argList, format);
	printIndent();
	vfprintf(jasmFile, format, argList);
	va_end(argList);

	lastWriteLabel = 0;
}

void catJPrint(const char * format, ...) {
	if (!writerEnabled) {
		return;
	}
	
	va_list argList;
	va_start(argList, format);
	vfprintf(jasmFile, format, argList);
	va_end(argList);

	lastWriteLabel = 0;
}

void printIndent() {
	int i = 0;
	for (;i < indentCounter; i++) {
		fprintf(jasmFile, "\t");
	}
}

void declareLabel(int labelNum) {
	if (lastWriteLabel) {
		printLabelSpilter();
	}
	noIndentJPrint("L%d:", labelNum);
	lastWriteLabel = 1;
}

void printLabelSpilter() {
	jprint("/*java assembly is not allow consecutive labels*/");
	indent();
	jprint("nop");
	outdent();
	jprint("/*so i add this line to split it, do no operation*/");
}