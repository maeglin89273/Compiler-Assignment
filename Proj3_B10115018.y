%{
	
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <math.h>
	#include "ExpInfo.h"
	#include "IdTypePair.h"
	#include "SymbolTable.h"
	#include "JASMWriter.h"

	//shortcut macro for raising an error
	#define RAISE_ERROR(m) yyerror(m); YYERROR
	//check the variable name is clash or not
	#define CHECK_CLASH_ERROR(b) if(clashMsg(b)) YYERROR
	#define RAISE_CLASH_ERROR yyerror("variable name clash"); YYERROR
	

	char paramArgTypeMatch(ArgNode * argsA, ArgNode * argsB);

	char clashMsg(VarRow * varPtr);
		
	int tolerateNumType(int typeA, int typeB);

	ExpInfo biOptorMathWrap(ExpInfo leftOp, ExpInfo rightOp, int operator);
	ExpInfo doMath(ExpInfo a, ExpInfo b, ExpInfo c, int operator);
	void writeMathJASM(int operator);

	ExpInfo cmpWrap (ExpInfo leftOp, ExpInfo rightOp, int operator);
	ExpInfo doCompare(ExpInfo a, ExpInfo b, ExpInfo c, int operator);
	void writeCmpJASM(int operator);

	VarRow * varInsert(char * id, ExpInfo info);

	void prt(char * msg);
%}

%union {
	int intVal;
	double realVal;
	char * strVal;
	char * varId;
	VarRow * varPtr;
	IdTypePair itPair;
	FuncInfo funcVal;
	ExpInfo expInfo;
}

%token COMMA COLON SEMI
%token L_PARENT	R_PARENT L_SQ_BKT R_SQ_BKT L_BKT R_BKT

%nonassoc ASSIGN_OP CMP_ADD CMP_MINUS CMP_MULTI CMP_DIV

%token<varId> IDFY
%token<intVal> CONST_INT
%token<realVal> CONST_REAL
%token<strVal> CONST_STR

%left OR
%left AND
%nonassoc NOT
%nonassoc LESS LESS_EQ GREAT GREAT_EQ EQ NOT_EQ
%left PLUS MINUS 
%left MULTI DIV MOD
%nonassoc INCR DECR XCR
%nonassoc UMINUS

%token RET_OP
%token K_BREAK K_CASE K_CLASS K_CONTINUE K_DEFAULT K_DO K_ELSE K_ENUM K_FALSE K_FOR K_FUNC K_IF K_IMPORT K_IN K_INIT K_LET K_NIL K_PRINT K_PRINTLN K_PUBLIC K_RETURN K_SELF K_STATIC K_STRUCT K_SWITCH K_TRUE K_VAR K_WHERE K_WHILE K_VOID K_READ
%token TYP_STR TYP_INT TYP_BOOL TYP_FLOAT TYP_DOUBLE

%start swift

%type <expInfo>arr_elmt id_or_elmt_rref exp bool_exp cmp_exp num_exp func_invo val_func_invo const_exp int_exp xcr_exp
%type <itPair>id_type id_itype
%type <funcVal> args args_list params params_list
%type <intVal>pmt_type pmt_itype ret_type ret_itype
%type <varPtr> id_or_elmt_lref id_or_elmt_num_lrref
%%

swift: g_var_const_decls func_decls {startWriteMainMethod();} stmts {endWriteMainMethod();}
		;

func_content: var_const_decls stmts
		;

var_const_decls: var_const_decls var_const_decl
		| var_const_decl
		| empty
		;

var_const_decl: const_decl
		| l_var_decl
		;

g_var_const_decls: g_var_const_decls g_var_const_decl
		| g_var_const_decl
		| empty
		;

g_var_const_decl: const_decl
		| g_var_decl
		;

const_decl: K_LET id_itype ASSIGN_OP const_exp {
			if(typeCompatible($2.type, $4.type)) {

				ExpInfo info;
				info = convertNumType($4, $2.type);
				CHECK_CLASH_ERROR(insertPrimitive($2.id, info));
			} else {
				RAISE_ERROR("the types are not compatible");
			}
		}
		| K_LET IDFY ASSIGN_OP const_exp {
			enableWriter(1);
			CHECK_CLASH_ERROR(insertPrimitive($2, $4));
		}	
		;

g_var_decl: K_VAR id_itype ASSIGN_OP const_exp {
			if(typeCompatible($2.type, $4.type)) {
				ExpInfo info;
				info = convertNumType($4, $2.type);

				VarRow * insertResult = varInsert($2.id, info);
				if (!insertResult) {
					RAISE_ERROR("variable name clash");
				} else {
					globalIVarDeclaration($2.id, info.constVal.intVal);
				}
			} else {
				RAISE_ERROR("the types are not compatible");		
			}
		}
		| K_VAR IDFY ASSIGN_OP const_exp {
			VarRow * insertResult = varInsert($2, $4);
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			} else {
				globalIVarDeclaration($2, $4.constVal.intVal);
				
			}
		}
		| K_VAR id_itype L_SQ_BKT int_exp R_SQ_BKT {
			//notice the array size here, it may be changed in the future
			// CHECK_CLASH_ERROR(insertArray($2.id, $2.type, 0));
			RAISE_ERROR("sorry, arrays are not supported yet!");
		}
		| K_VAR id_itype {
			VarRow * insertResult = insertNotInitPrimitive($2.id, $2.type);
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			} else {
				globalIVarDeclarationNotInit($2.id);
			}
		}
		| K_VAR IDFY {
			VarRow * insertResult = insertNotInitPrimitive($2, INT_T);
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			} else {
				globalIVarDeclarationNotInit($2);
			}
		}
		;
		
l_var_decl: K_VAR id_itype ASSIGN_OP exp {
			if(typeCompatible($2.type, $4.type)) {
				ExpInfo info;
				info = convertNumType($4, $2.type);

				VarRow * insertResult = varInsert($2.id, info);
				if (!insertResult) {
					RAISE_ERROR("variable name clash");
				} else {
					iVarStore(insertResult);
				}

			} else {
				RAISE_ERROR("the types are not compatible");		
			}
		}
		| K_VAR IDFY ASSIGN_OP exp {
			VarRow * insertResult = varInsert($2, $4);
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			} else {
				iVarStore(insertResult);
			}
		}
		| K_VAR id_itype L_SQ_BKT int_exp R_SQ_BKT {
			//notice the array size here, it may be changed in the future
			// CHECK_CLASH_ERROR(insertArray($2.id, $2.type, 0));
			RAISE_ERROR("sorry, arrays are not supported yet!");
		}
		| K_VAR id_itype {
			VarRow * insertResult = insertNotInitPrimitive($2.id, $2.type);
			
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			}
		}
		| K_VAR IDFY {
			VarRow * insertResult = insertNotInitPrimitive($2, INT_T);
			
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			}
		}
		;

id_type: IDFY COLON pmt_type {
			$$.id = $1;
			$$.type = $3;
		}
		;
id_itype: IDFY COLON pmt_itype {
			$$.id = $1;
			$$.type = $3;
		}
		;

func_decls: func_decls func_decl
		| func_decl
		| empty
		;

func_decl: K_FUNC IDFY L_PARENT args R_PARENT RET_OP ret_itype {
			FuncInfo func = $4;
			func.retType = $7;
			VarRow * funcVar = insertFunc($2, func);
			if(funcVar) {
				startWriteFunction(funcVar);
				newScope(func);

			} else {
				RAISE_ERROR("function name clash");
			}
		} L_BKT func_content R_BKT {
			if (dumpCurrentScope()) {
				endWriteFunction();
			} else {
				RAISE_ERROR("The function has no proper return statement");
			}
		}
		;

args: args_list {
			$$ = $1;
		}
		| empty {
			$$.args = $$.lastArg = NULL;
		}
		;

args_list: args_list COMMA id_itype {
			$$ = $1;
			$$.lastArg = catArgs($$.lastArg, $3.id, $3.type);
		}
		| id_itype {
			$$.lastArg = $$.args = catArgs(NULL, $1.id, $1.type);	 
		}
		;

ret_type: K_VOID {$$ = VOID_T;}
		| pmt_type {$$ = $1;}
		;

ret_itype: K_VOID {$$ = VOID_T;}
		| pmt_itype {$$ = $1;}
		;

pmt_type: TYP_INT {$$ = INT_T;}
		| TYP_BOOL {$$ = BOOL_T;}
		| TYP_FLOAT {$$ = FLOAT_T;}
		| TYP_DOUBLE {$$ = DOUBLE_T;}
		| TYP_STR {$$ = STR_T;}
		;

pmt_itype: TYP_INT {$$ = INT_T;}
		| TYP_BOOL {$$ = BOOL_T;}
		;

stmts: stmts {
			// if there is a statement under a return, raise an error
			if(hasReturned()) {
				RAISE_ERROR("the following statements are unreachable");
			} else {
				jnewline();
			}
		} stmt
		| stmt
		| empty
		;

stmt: asgn_stmt
		| print_stmt
		| K_READ id_or_elmt_rref {
			RAISE_ERROR("not support read keyword yet");
		}
		| ret_stmt
		| if_else_stmt {endWriteElse();}
		| if_stmt {endWriteIf();}
		| while_stmt
		| func_invo {
			if ($1.type != K_VOID) {
				stackPop();
			}
		}
		;

asgn_stmt: id_or_elmt_lref ASSIGN_OP exp {
			if (typeCompatible($1->type, $3.type)) {
				iVarStore($1);
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
		| id_or_elmt_num_lrref CMP_ADD num_exp {			
			if (typeCompatible($1->type, $3.type)) {
				stackAdd();
				iVarStore($1);
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
		| id_or_elmt_num_lrref CMP_MINUS num_exp {			
			if (typeCompatible($1->type, $3.type)) {
				stackSub();
				iVarStore($1);
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
		| id_or_elmt_num_lrref CMP_MULTI num_exp {			
			if (typeCompatible($1->type, $3.type)) {
				stackMul();
				iVarStore($1);
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
		| id_or_elmt_num_lrref CMP_DIV num_exp {			
			if (typeCompatible($1->type, $3.type)) {
				stackDiv();
				iVarStore($1);
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
		| xcr_exp {
			stackPop();
		}
		;

// lvalue reference
id_or_elmt_lref: IDFY {
			VarRow * var = lookup($1);
			if (var) {
				if(var->isConst) {
					RAISE_ERROR("cannot assign to the constant variable");
				} else {			
					var->isInit = 1;
					$$ = var;
				}
			} else {
				RAISE_ERROR("cannot find the variable");
			}
		}
		| arr_elmt {
			// $$ = $1;
		}
		;
// rvalue reference
id_or_elmt_rref: IDFY {
			VarRow * var = lookup($1);
			if (var && var->isInit) {
				$$ = primitiveVarExpMapping(var);
				if ($$.isConst) {
					iConstPush($$.constVal.intVal);
				} else {
					iVarLoad(var);
				}
			} else {
				RAISE_ERROR("cannot find the variable or it is not init");
			}
		}
		| arr_elmt {
			// $$ = $1;
		}
		;

// the case that needs lvalue and rvalue, it's also a number
id_or_elmt_num_lrref: IDFY {	
			VarRow * var = lookup($1);
			if (var) {
				if(var->isConst) {
					RAISE_ERROR("cannot assign to the constant variable");

				} else if (!var->isInit) {
					RAISE_ERROR("the variable is not init");

				} else if (!checkNumber(var->type)) {
					RAISE_ERROR("variable is not a number");

				} else {
					$$ = var;
				}
			} else {
				RAISE_ERROR("cannot find the variable");
			}
		}
		| arr_elmt {
			// $$ = $1;
		}

		;

// refering an array element
arr_elmt: IDFY L_SQ_BKT int_exp R_SQ_BKT {
			/*VarRow * var = lookup($1);
			if (var) {
				$$.type = var->content.arrVal.type;
				$$.isConst = 0;
			} else {
				RAISE_ERROR("cannot find the variable");
			}*/
			RAISE_ERROR("sorry, arrays are not supported yet!");
		}
		;

print_stmt: K_PRINT {startPrint();} exp {endAsPrint($3.type);}
		| K_PRINTLN {startPrint();} exp {endAsPrintln($3.type);}
		;

ret_stmt: K_RETURN exp {
			if (setReturn($2.type)) {
				writeIReturn();
			} else {
				RAISE_ERROR("return type is not match");
			}
		}
		| K_RETURN {
			if (setReturn(VOID_T)) {
				writeReturn();
			} else {
				RAISE_ERROR("return type is not match");
			}
		}

		;
// collection of valid expressions
exp: bool_exp {$$ = $1;}
		| num_exp {$$ = $1;}
		| id_or_elmt_rref {$$ = $1;}
		| L_PARENT id_or_elmt_rref R_PARENT {$$ = $2;}
		| CONST_STR {
			$$ = createConstExp(STR_T);
			$$.constVal.strVal = $1;
			strConstPush($1);
		}
		| L_PARENT CONST_STR R_PARENT {
			$$ = createConstExp(STR_T);
			$$.constVal.strVal = $2;
			strConstPush($2);
		}
		| val_func_invo {$$ = $1;}
		| L_PARENT val_func_invo R_PARENT {$$ = $2;}
		;

// expression that yelid the boolean value
bool_exp: L_PARENT bool_exp R_PARENT {
			$$ = $2;
		}
		| NOT bool_exp {
			$$ = $2;

			if ($$.isConst) {
				$$.constVal.intVal = !$$.constVal.intVal;
			}
			stackNot();
		
		}
		| bool_exp AND bool_exp {
			$$.isConst = isBothConst($1, $3);
			$$.type = BOOL_T;

			if ($$.isConst) {
				$$.constVal.intVal = $1.constVal.intVal && $3.constVal.intVal;
			}
			stackAnd();
		
		}
		| bool_exp OR bool_exp {
			$$.isConst = isBothConst($1, $3);
			$$.type = BOOL_T;

			if ($$.isConst) {
				$$.constVal.intVal = $1.constVal.intVal || $3.constVal.intVal;
			}
			stackOr();
		
		}
		| cmp_exp {
			$$ = $1;
		}
		| id_or_elmt_rref {
			if (checkExpBool($1)) {
				$$ = $1;
			} else {
				RAISE_ERROR("expression is not a boolean");
			}
		}
		| K_TRUE {
			$$ = createConstExp(BOOL_T);
			$$.constVal.intVal = 1;
			pushTrue();
		}
		| K_FALSE {
			$$ = createConstExp(BOOL_T);
			$$.constVal.intVal = 0;
			pushFalse();
		}
		| val_func_invo {
			if (checkExpBool($1)) {
				$$ = $1;
			} else {
				RAISE_ERROR("expression is not a boolean");
			}
		}
		;

cmp_exp: num_exp LESS num_exp {
			$$ = cmpWrap($1, $3, LESS);
		}
		| num_exp LESS_EQ num_exp {
			$$ = cmpWrap($1, $3, LESS_EQ);
		}
		| num_exp GREAT num_exp {
			$$ = cmpWrap($1, $3, GREAT);
		}
		| num_exp GREAT_EQ num_exp {
			$$ = cmpWrap($1, $3, GREAT_EQ);
		}
		| num_exp EQ num_exp {
			$$ = cmpWrap($1, $3, EQ);
		}
		| num_exp NOT_EQ num_exp {
			$$ = cmpWrap($1, $3, NOT_EQ);
		}
		;
// expression that yelid the number value
num_exp:L_PARENT num_exp R_PARENT {
			$$ = $2;
		}
		| MINUS num_exp %prec UMINUS {
			$$ = $2;
			if ($$.isConst)	{
				if ($$.type == INT_T) {
					$$.constVal.intVal = -$$.constVal.intVal;
				} else {
					$$.constVal.realVal = -$$.constVal.realVal;
				}
			} else {
				stackNeg();
			}
		}
		| xcr_exp {$$ = $1;}
		| num_exp MULTI num_exp {
			$$ = biOptorMathWrap($1, $3, MULTI);
		}
		| num_exp DIV num_exp {
			$$ = biOptorMathWrap($1, $3, DIV);
		}
		| num_exp PLUS num_exp {
			$$ = biOptorMathWrap($1, $3, PLUS);
		}
		| num_exp MINUS num_exp {
			$$ = biOptorMathWrap($1, $3, MINUS);
		}
		| id_or_elmt_rref {
			if (checkExpNumber($1)) {
				$$ = $1;
			} else {
				RAISE_ERROR("expression is not a number");
			}
		}
		| CONST_INT {
			$$ = createConstExp(INT_T);
			$$.constVal.intVal = $1;
			iConstPush($1);
		}
		| CONST_REAL {
			// $$ = createConstExp(DOUBLE_T);
			// $$.constVal.realVal = $1;
			RAISE_ERROR("sorry, not support real number yet");
		}
		| val_func_invo {
			if (checkExpNumber($1)) {
				$$ = $1;
			} else {
				RAISE_ERROR("expression is not a number");
			}
		}
		;
xcr_exp: id_or_elmt_num_lrref INCR {
			$$ = primitiveVarExpMapping($1);
			iVarPosIncr($1);
		}
		| INCR id_or_elmt_num_lrref {
			$$ = primitiveVarExpMapping($2);
			iVarPreIncr($2);
		}
		| id_or_elmt_num_lrref DECR {
			$$ = primitiveVarExpMapping($1);
			iVarPosDecr($1);
		}
		| DECR id_or_elmt_num_lrref {
			$$ = primitiveVarExpMapping($2);
			iVarPreDecr($2);
		}
		;

func_invo: IDFY L_PARENT params R_PARENT {
			VarRow * funcVar = lookup($1);
			if (!funcVar) {
				RAISE_ERROR("cannot find function");
			} else if (funcVar->type != FUNC_T) {
				RAISE_ERROR("this variable is not a function");
			} else if (!paramArgTypeMatch(funcVar->content.funcVal.args, $3.args)) {
				RAISE_ERROR("the parameter types or length are not matched");
			}

			$$.type = funcVar->content.funcVal.retType;
			$$.isConst = 0;

			stackFuncInvok(funcVar);
			
		}
		;

val_func_invo: func_invo {
			if ($1.type == K_VOID) {
				RAISE_ERROR("void function cannot be a expression");
			} else {
				$$ = $1;
			}
		}
		;

params: params_list {
			$$ = $1;
		}
		| empty {
			$$.args = $$.lastArg = NULL;
		}
		;

params_list: params_list COMMA exp {
			$$ = $1;
			$$.lastArg = catArgs($$.lastArg, NULL, $3.type);
		}
		| exp {
			$$.lastArg = $$.args = catArgs(NULL, NULL, $1.type);
		}
		;

const_exp: {enableWriter(0);} exp {
			enableWriter(1);
			if (!$2.isConst) {
				RAISE_ERROR("not a const expression");
			} else {
				$$ = $2;
			}
		}
		;

int_exp: num_exp {
			if($1.type != INT_T) {
				RAISE_ERROR("not a int expression");
			} else {
				$$ = $1;
			}
		}
		;

if_else_stmt: if_stmt K_ELSE L_BKT {
			enterElseBlock();
			startWriteElse();
		}
		stmts R_BKT {
			leaveBlock();
		}
		;
if_stmt: K_IF L_PARENT bool_exp R_PARENT L_BKT {
			enterIfBlock();
			startWriteIf();
		}
		stmts R_BKT {
			leaveBlock();
		}
		;
while_stmt: K_WHILE {startWriteWhile();} L_PARENT bool_exp R_PARENT L_BKT {
			enterLoopBlock();
			writeWhileEval();
		} stmts R_BKT {
			leaveBlock();
			endWriteWhile();
		}
		;
		

empty: ;

%%

char clashMsg(VarRow * varPtr) {
	if (varPtr == NULL) {
		yyerror("variable name clash");
		return 1;
	}
	return 0;
}

char paramArgTypeMatch(ArgNode * argsA, ArgNode * argsB) {
	for (;argsA != NULL && argsB != NULL;) {
		if (!typeCompatible(argsA->type, argsB->type)) {
			return 0;
		}
		argsA = argsA->next;
		argsB = argsB->next;
	}

	if (argsA != argsB ) {
		return 0;
	}

	return 1;
}

ExpInfo convertNumType(ExpInfo exp, int numType) {	
	if (exp.type != numType) {
		if (numType != INT_T && exp.type == INT_T) {
			exp.constVal.realVal = exp.constVal.intVal;
		}
		exp.type = numType;	
	}
	
	return exp;
}

ExpInfo biOptorMathWrap(ExpInfo leftOp, ExpInfo rightOp, int operator) {
	ExpInfo output;
	output.isConst = isBothConst(leftOp, rightOp);
	output.type = tolerateNumType(leftOp.type, rightOp.type);

	if (output.isConst) {
		output = doMath(output, leftOp, rightOp, operator);
	}
	writeMathJASM(operator);

	return output;
}

ExpInfo doMath(ExpInfo a, ExpInfo b, ExpInfo c, int operator) {
	if (a.type == INT_T) {
		int op1 = b.constVal.intVal;
		int op2 = c.constVal.intVal;
		switch(operator) {
			case MULTI:
				a.constVal.intVal = op1 * op2;
				break;
			case DIV:
				a.constVal.intVal = op1 / op2;
				break;
			case MOD:
				a.constVal.intVal = op1 % op2;
				break;
			case PLUS:
				a.constVal.intVal = op1 + op2;
				break;
			case MINUS:
				a.constVal.intVal = op1 - op2;
		}
	} else {
		double op1 = b.type == INT_T? b.constVal.intVal: b.constVal.realVal;
		double op2 = c.type == INT_T? c.constVal.intVal: c.constVal.realVal;
		switch(operator) {
			case MULTI:
				a.constVal.realVal = op1 * op2;
				break;
			case DIV:
				a.constVal.realVal = op1 / op2;
				break;
			case MOD:
				a.constVal.realVal = fmod(op1, op2);
				break;
			case PLUS:
				a.constVal.realVal = op1 + op2;
				break;
			case MINUS:
				a.constVal.realVal = op1 - op2;
		}
	}

	return a;
}

void writeMathJASM(int operator) {
	switch(operator) {
		case MULTI:
			stackMul();
			break;
		case DIV:
			stackDiv();
			break;
		case MOD:
			stackRem();
			break;
		case PLUS:
			stackAdd();
			break;
		case MINUS:
			stackSub();
	}
}

ExpInfo cmpWrap(ExpInfo leftOp, ExpInfo rightOp, int operator) {
	ExpInfo output;
	output.isConst = isBothConst(leftOp, rightOp);
	output.type = BOOL_T;

	if (output.isConst) {
		output = doCompare(output, leftOp, rightOp, operator);
	}
	writeCmpJASM(operator);

	return output;
}

ExpInfo doCompare(ExpInfo a, ExpInfo b, ExpInfo c, int operator) {
	double op1 = b.type == INT_T? b.constVal.intVal: b.constVal.realVal;
	double op2 = c.type == INT_T? c.constVal.intVal: c.constVal.realVal;

	switch(operator) {
		case LESS:
			a.constVal.intVal = op1 < op2;
			break;
		case LESS_EQ:
			a.constVal.intVal = op1 <= op2;
			break;
		case GREAT:
			a.constVal.intVal = op1 > op2;
			break;
		case GREAT_EQ:
			a.constVal.intVal = op1 >= op2;
			break;
		case EQ:
			a.constVal.intVal = op1 == op2;
			break;
		case NOT_EQ:
			a.constVal.intVal = op1 != op2;
	}
	return a;
}

void writeCmpJASM(int operator) {
	switch(operator) {
		case LESS:
			stackLess();
			break;
		case LESS_EQ:
			stackLessEq();
			break;
		case GREAT:
			stackGreat();
			break;
		case GREAT_EQ:
			stackGreatEq();
			break;
		case EQ:
			stackEq();
			break;
		case NOT_EQ:
			stackNotEq();
	}
}

VarRow * varInsert(char * id, ExpInfo info) {
	char isExpConst = info.isConst;
	info.isConst = 0;
	VarRow * insertResult = insertPrimitive(id, info);
	
	return insertResult;
}


void prt(char * msg) {
	fprintf(stdout, "\t\t\t%s\n", msg);
}

yyerror(char * msg) {
	fprintf(stderr, "\nsyntax error: %s\n", msg);
}

main(int c, char * args[]) {
	
	prepareJASM(args[1]);
	createSymbolTable();
	int result = yyparse();
	freeSymbolTable();
	closeJASM(result);
	return result;
}
