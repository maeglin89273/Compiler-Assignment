#ifndef JASMWRITER_H
#define JASMWRITER_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "SymbolTable.h"


void prepareJASM(const char * fileName);
void closeJASM(int parseResult);
void enableWriter(char enabled);
void startWriteMainMethod();
void endWriteMainMethod();
void writeReturn();
void writeIReturn();

void startWriteIf();
void startWriteElse();
void endWriteIf();
void endWriteElse();

void startWriteWhile();
void writeWhileEval();
void endWriteWhile();

void startWriteFunction(VarRow * funcVar);
void endWriteFunction();
void startPrint();
void endAsPrint(int expType);
void endAsPrintln(int expType);

void globalIVarDeclarationNotInit(const char * varName);
void globalIVarDeclaration(const char * varName, int value);
void iVarStore(const VarRow * var);
void iVarLoad(const VarRow * var);
void iVarPosIncr(const VarRow * var);
void iVarPreIncr(const VarRow * var);
void iVarPosDecr(const VarRow * var);
void iVarPreDecr(const VarRow * var);

void iConstPush(int constant);
void strConstPush(const char * constant);

void stackPop();
void stackNot();
void stackAnd();
void stackOr();
void stackLess();
void stackLessEq();
void stackGreat();
void stackGreatEq();
void stackEq();
void stackNotEq();

void stackNeg();
void stackAdd();
void stackSub();
void stackMul();
void stackDiv();
void stackRem();

void stackFuncInvok(const VarRow * funcVar);

void pushFalse();
void pushTrue();

void jnewline();
void jprint(const char * format, ...);


#endif