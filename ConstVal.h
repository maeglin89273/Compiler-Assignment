#ifndef CONSTVAL_H
#define CONSTVAL_H

typedef union {
	int intVal;
	double realVal;
	char * strVal;
}  ConstVal;

#endif