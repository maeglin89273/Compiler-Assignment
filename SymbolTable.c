#include "SymbolTable.h"

#include <stdio.h>
#include <stdlib.h>

SymbolTable * symTable;

ScopeTable * createScopeTable(ScopeTable * lowerScope);
VarRow * createRow(int rowNum, char * id, int type, char isConst, char isInit, Content content);
ScopeTable * freeScopeTable(ScopeTable * table, char * isValidExitScope);
VarRow * freeRow(VarRow * row);
void printRowInfo(VarRow * row);
void clearContent(int type, Content content);

VarRow * scopeLookup(ScopeTable * scope, char * id);
VarRow * insertVarToScope(ScopeTable * scope, char * id, int type, char isConst, char isInit, Content content);

void enterBlock(ScopeTable * scope, int bType);
char leaveBlockOfScope(ScopeTable * scope);
ReturnRecord * createReturnRecord(int bType, ReturnRecord * lowerBlock);

void createSymbolTable() {
	symTable = (SymbolTable *)malloc(sizeof(SymbolTable));
	symTable->topScope = createScopeTable(NULL);
}

ScopeTable * createScopeTable(ScopeTable * lowerScope) {
	ScopeTable * table = (ScopeTable *)malloc(sizeof(ScopeTable));
	table->headRow = table->tailRow = NULL;
	table->lowerScope = lowerScope;
	table->retType = VOID_T;
	table->topRecord = NULL;

	enterBlock(table, BASE_BLOCK);
	return table;
}

VarRow * createRow(int rowNum, char * id, int type, char isConst, char isInit, Content content) {

	VarRow * row = (VarRow*)malloc(sizeof(VarRow));
	row->next = NULL;
	row->num = rowNum;
	row->id = id;
	row->type = type;
	row->isConst = isConst;
	row->isInit = isInit;
	row->isGlobal = isInGlobal();
	row->content = content;
	return row;
}

void freeSymbolTable() {
	// printf("Symbol Table:\n");
	ScopeTable * sub = symTable->topScope;
	int i = 0;
	for (;sub != NULL; i++) {
		sub = freeScopeTable(sub, NULL);
	}

	free(symTable);
}

char isInGlobal() {
	return symTable->topScope->lowerScope == NULL;
}

ScopeTable * freeScopeTable(ScopeTable * table, char * isValidExitScope) {
	printf("Scope Table:\nid: name typeId isConst constVal\n");
	ScopeTable * lowerScope = table->lowerScope;
	VarRow * row = table->headRow;

	char hasReturned = leaveBlockOfScope(table);
	if (isValidExitScope != NULL) {
		*isValidExitScope = hasReturned;
	}

	int i = 0;
	for (; row != NULL; i++) {
		row = freeRow(row);
	}

	free(table);
	return lowerScope;
}

VarRow * freeRow(VarRow * row) {
	printRowInfo(row);
	VarRow * nextRow = row->next;
	free(row->id);
	clearContent(row->type, row->content);
	free(row);
	return nextRow;
}

void printRowInfo(VarRow * row) {
	printf("%d: %4s %6d %7s ", row->num, row->id, row->type, row->isConst? "true": "false");
	if (row->isConst) {
		switch (row->type) {
			case INT_T:
				printf("%8d", row->content.intVal);
				break;
			case BOOL_T:
				printf("%8s", row->content.intVal? "true": "false");
				break;
			case FLOAT_T:
				printf("%8f", (float)row->content.realVal);
				break;
			case DOUBLE_T:
				printf("%8lf", row->content.realVal);
				break;
			case STR_T:
				printf("%8s", row->content.strVal);
				break;
		}
	} else {
		printf("%8s", "NaN");
	}
	printf("\n");
}

void clearContent(int type, Content content) {
	if (type == STR_T) {
		free(content.strVal);
	} else if (type == FUNC_T) {
		ArgNode * args = content.funcVal.args;
		ArgNode * tmp;
		for (;args != NULL;) {
			tmp = args;
			args = args->next;
			free(tmp);
		}
	}
}

void newScope(FuncInfo func) {
	symTable->topScope = createScopeTable(symTable->topScope);

	ArgNode * node = func.args;
	ExpInfo varAttr;
	for (;node != NULL; node = node->next) {
		varAttr.isConst = 0;
		varAttr.type = node->type;
		insertPrimitive(node->id, varAttr);	
	}
	symTable->topScope->retType = func.retType;
	
}

char dumpCurrentScope() {
	char isValidExitScope;
	symTable->topScope = freeScopeTable(symTable->topScope, &isValidExitScope);
	return isValidExitScope;
}

VarRow * lookup(char * id) {
	ScopeTable * scope = symTable->topScope;
	for (;scope != NULL; scope = scope->lowerScope) {
		VarRow * result = scopeLookup(scope, id);
		if (result) {
			free(id);
			return result;
		}
	}
	free(id);
	return NULL;
}

VarRow * scopeLookup(ScopeTable * scope, char * id) {
	VarRow * row = scope->headRow;
	for (; row != NULL; row = row->next) {
		if (strcmp(id, row->id) == 0) {
			return row;
		}
	}

	return NULL;
}
VarRow * insertNotInitPrimitive(char * id, int type) {
	Content empty;
	return insertVarToScope(symTable->topScope, id, type, 0, 0, empty);
}

VarRow * insertPrimitive(char * id, ExpInfo exp) {
	Content content;
	if (exp.isConst) {
		content = extractContent(exp);
	}
	
	return insertVarToScope(symTable->topScope, id, exp.type, exp.isConst, 1, content);
}

VarRow * insertFunc(char * id, FuncInfo funcVal) {
	Content content;
	content.funcVal = funcVal;

	return insertVarToScope(symTable->topScope, id, FUNC_T, 0, 1, content);
}

VarRow * insertArray(char * id, int arrType, int size) {
	Content content;
	ArrayInfo arrVal;
	arrVal.type = arrType;
	arrVal.size = size;
	content.arrVal = arrVal;

	return insertVarToScope(symTable->topScope, id, ARRAY_T, 0, 1, content);
}

VarRow * insertVarToScope(ScopeTable * scope, char * id, int type, char isConst, char isInit, Content content) {
	if (scopeLookup(scope, id)) {
		free(id);
		return NULL;
	}

	
	VarRow * newVar;
	if (scope->tailRow == NULL) {
		 newVar = createRow(0, id, type, isConst, isInit, content);
		scope->headRow = scope->tailRow = newVar;	
	} else {
		newVar = createRow(scope->tailRow->num + 1, id, type, isConst, isInit, content);
		scope->tailRow->next = newVar;
		scope->tailRow = newVar;
	}

	return newVar;
}

char setReturn(int type) {
	ScopeTable * scope = symTable->topScope;
	if (hasReturned(symTable) || !typeCompatible(scope->retType, type)) {
		return 0;
	}
	scope->topRecord->hasReturned = 1;
	return 1;
}

char hasReturned() {
	return symTable->topScope->topRecord->hasReturned;
}

void enterIfBlock() {
	enterBlock(symTable->topScope, IF_BLOCK);
}

void enterElseBlock() {
	enterBlock(symTable->topScope, ELSE_BLOCK);
}

void enterLoopBlock() {
	enterBlock(symTable->topScope, LOOP_BLOCK);
}
char leaveBlock() {
	return leaveBlockOfScope(symTable->topScope);
}

char leaveBlockOfScope(ScopeTable * scope) {

	ReturnRecord * currentBlock = scope->topRecord;
	ReturnRecord * lowerBlock = scope->topRecord->lowerBlock;
	
	switch(currentBlock->bType) {
		case IF_BLOCK:
			if (currentBlock->hasReturned) {
				lowerBlock->ifBlockRet = 1;
			}
			break;
		case ELSE_BLOCK:
			if (lowerBlock->ifBlockRet && currentBlock->hasReturned) {
				lowerBlock->hasReturned = 1;
				lowerBlock->ifBlockRet = 0;
			}
			break;

		// case LOOP_BLOCK:
		case BASE_BLOCK:
			if (scope->retType == VOID_T) {
				currentBlock->hasReturned = 1;
			}
	}
	char hasReturned = currentBlock->hasReturned;

	scope->topRecord = lowerBlock;
	free(currentBlock);

	return hasReturned;
}

void enterBlock(ScopeTable * scope, int bType) {
	if (scope->topRecord && bType != ELSE_BLOCK) {
		scope->topRecord->ifBlockRet = 0;
	}
	
	scope->topRecord = createReturnRecord(bType, scope->topRecord);
}

ReturnRecord * createReturnRecord(int bType, ReturnRecord * lowerBlock) {
	ReturnRecord * newRecord = (ReturnRecord *)malloc(sizeof(ReturnRecord));
	newRecord->hasReturned = 0;
	newRecord->bType = bType;
	newRecord->ifBlockRet = 0;
	newRecord->lowerBlock = lowerBlock;
	return newRecord;
}

char typeCompatible(int leftType, int rightType) {
	if (leftType == rightType) {
		return 1;
	}
	
	if (checkNumber(leftType) && checkNumber(rightType)) {
		if (leftType == FLOAT_T && rightType == DOUBLE_T) {
			return 0;
		}
		if (leftType == INT_T && rightType != INT_T) {
			return 0;
		}

		return 1;
	}

	return 0;
}

char checkNumber(int type) {
	return type == INT_T || type == DOUBLE_T || type == FLOAT_T;
}

ArgNode * catArgs(ArgNode * node, char * id, int type) {
	ArgNode * newNode = (ArgNode *)malloc(sizeof(ArgNode));
	newNode->id = id;
	newNode->type = type;
	newNode->next = NULL;
	if (node) {
		node->next = newNode;
	}

	return newNode;
}

Content extractContent(ExpInfo exp) {
	Content content;
	switch(exp.type) {
		case INT_T:
		case BOOL_T:
			content.intVal = exp.constVal.intVal;
			break;

		case FLOAT_T:
			content.realVal = exp.constVal.realVal;
			break;

		case DOUBLE_T:
			content.realVal = exp.constVal.realVal;
			break;
		case STR_T:
			content.strVal = exp.constVal.strVal;
			break;
	}

	return content;
}


ExpInfo primitiveVarExpMapping(const VarRow * var) {
	ExpInfo exp;
	exp.isConst = var->isConst;
	exp.type = var->type;
	if (exp.isConst) {
		switch(exp.type) {
			case INT_T:
				exp.constVal.intVal = var->content.intVal;
				break;

			case FLOAT_T:
				exp.constVal.realVal = var->content.realVal;
				break;

			case DOUBLE_T:
				exp.constVal.realVal = var->content.realVal;
				break;

			case STR_T:
				exp.constVal.strVal = var->content.strVal;
				break;

			case BOOL_T:
				 exp.constVal.intVal = var->content.intVal;
		}
	}
	
	return exp;
}