#ifndef EXPINFO_H
#define EXPINFO_H

#include "ConstVal.h"
typedef struct {
	int type;
	char isConst;
	ConstVal constVal;
} ExpInfo;

char isBothConst(ExpInfo a, ExpInfo b);
char checkExpBool(ExpInfo exp);
char checkExpIntType(ExpInfo exp);
char checkExpNumber(ExpInfo exp);
ExpInfo createConstExp(int type);
ExpInfo convertNumType(ExpInfo exp, int RealNumType);
#endif