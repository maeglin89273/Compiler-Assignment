#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "ExpInfo.h"

#define INT_T 10
#define BOOL_T 11
#define FLOAT_T 12
#define DOUBLE_T 13
#define STR_T 14
#define ARRAY_T 15
#define FUNC_T 16
#define VOID_T 17

#define BASE_BLOCK 20
#define IF_BLOCK 21
#define ELSE_BLOCK 22
#define LOOP_BLOCK 23

typedef struct {
	int type;
	int size;
} ArrayInfo;

typedef struct ArgNode {
	int type;
	char * id;
	struct ArgNode * next;
} ArgNode;

typedef struct {
	ArgNode * args;
	ArgNode * lastArg;
	int retType;
} FuncInfo;

typedef union {
	int intVal;
	double realVal;
	char * strVal;
	FuncInfo funcVal;
	ArrayInfo arrVal;
} Content;

typedef struct VarRow {
	int num;
	char * id;
	int type;
	char isConst;
	char isInit;
	char isGlobal;	
	Content content;

	struct VarRow * next;
} VarRow;

typedef struct ReturnRecord {
	char hasReturned;
	int bType;
	char ifBlockRet;

	struct ReturnRecord * lowerBlock;
} ReturnRecord;

typedef struct ScopeTable {
	VarRow * headRow;
	VarRow * tailRow;
	int retType;
	ReturnRecord * topRecord;
	struct ScopeTable * lowerScope;
} ScopeTable;

typedef struct {
	ScopeTable * topScope;
} SymbolTable;

void createSymbolTable();
void freeSymbolTable();
char isInGlobal();
void newScope(FuncInfo func);
char dumpCurrentScope();

VarRow * lookup(char * id);
VarRow * insertNotInitPrimitive(char * id, int type);
VarRow * insertPrimitive(char * id, ExpInfo exp);
VarRow * insertFunc(char * id, FuncInfo funcVal);
VarRow * insertArray(char * id, int arrType, int size);

char setReturn(int type);
char hasReturned();
void enterIfBlock();
void enterElseBlock();
void enterLoopBlock();
char leaveBlock();

char typeCompatible(int leftType, int rightType);
char checkNumber(int type);
ArgNode * catArgs(ArgNode * node, char * id, int type);
Content extractContent(ExpInfo exp);
ExpInfo primitiveVarExpMapping(const VarRow * var);
#endif