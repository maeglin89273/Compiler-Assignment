#include "ExpInfo.h"
#include "SymbolTable.h"
#include <stdlib.h>

char isBothConst(ExpInfo a, ExpInfo b) {
	return a.isConst && b.isConst;
}
char checkExpNumber(ExpInfo exp) {
	return checkNumber(exp.type);
}

char checkExpBool(ExpInfo exp) {
	return exp.type == BOOL_T;
}

char checkExpIntType(ExpInfo exp) {
	return exp.type == BOOL_T || exp.type == INT_T;
}

ExpInfo createConstExp(int type) {
	ExpInfo t;
	t.type = type;
	t.isConst = 1;
	return t;
}

int tolerateNumType(int typeA, int typeB) {
	if(typeA == DOUBLE_T || typeB == DOUBLE_T) {
		return DOUBLE_T;
	} else if(typeA == FLOAT_T || typeB == FLOAT_T) {
		return FLOAT_T;
	}

	return INT_T;
}