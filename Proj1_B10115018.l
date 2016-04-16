%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <math.h>
	#include "ExpInfo.h"
	#include "IdTypePair.h"
	#include "SymbolTable.h"
	#include "y.tab.h"

	#define MAX_LINE_BUFFER 256

	
	#define NIL -1

	char lineBuffer[MAX_LINE_BUFFER];
	char strBuffer[MAX_LINE_BUFFER];
	int lineCounter = 1;

	void newline();
	void prtLine(int lineNum, char * line);
	void clearLineBuffer();
	void catLine();
	void prtTok(char * token);
	char * handleIdfyTok(char * token);
	char * handleStrTok(char * token);
	void discardEscape(char * strVal);
	int handleIntTok(char * token);
	double handleRealTok(char * token);

	char * copyString(char * origin);
	
%}

%x STRING MULTI_COMMENT

/*The optional numeric signs should belong to unary operators.
Therefore, I didn't include them in the following regular expressions. */
integer [0-9]+
real_num [0-9]*\.[0-9]+([Ee][+-]?[0-9]+)? 
identifier [A-Za-z][A-Za-z0-9]*

%%
"," {prtTok(","); return COMMA;}
":"	{prtTok(":"); return COLON;}
";" {prtTok(";"); return SEMI;}

"(" {prtTok("("); return L_PARENT;}
")" {prtTok(")"); return R_PARENT;}
"[" {prtTok("["); return L_SQ_BKT;}
"]" {prtTok("]"); return R_SQ_BKT;}
"{" {prtTok("{");return L_BKT;}
"}" {prtTok("}"); return R_BKT;}

"+" {prtTok("+"); return PLUS;}
"-" {prtTok("-"); return MINUS;}
"*" {prtTok("*"); return MULTI;}
"/" {prtTok("/"); return DIV;}
"%" {prtTok("%"); return MOD;}
"++" {prtTok("++"); return INCR;}
"--" {prtTok("--"); return DECR;}

"<" {prtTok("<"); return LESS;}
"<=" {prtTok("<="); return LESS_EQ;}
"==" {prtTok("=="); return EQ;}
"!=" {prtTok("!="); return NOT_EQ;}
">" {prtTok(">"); return GREAT;}
">=" {prtTok(">="); return GREAT_EQ;}

"&&" {prtTok("&&"); return AND;}
"||" {prtTok("||"); return OR;}
"!" {prtTok("!"); return NOT;}

"=" {prtTok("="); return ASSIGN_OP;}

"+=" {prtTok("+="); return CMP_ADD;}
"-=" {prtTok("-="); return CMP_MINUS;}
"*=" {prtTok("*="); return CMP_MULTI;}
"/=" {prtTok("/="); return CMP_DIV;}

"->" {prtTok("->"); return RET_OP;}

break {prtTok("break"); return K_BREAK;}
case {prtTok("case"); return K_CASE;}
class {prtTok("class"); return K_CLASS;}
continue {prtTok("continue"); return K_CONTINUE;}
default {prtTok("default"); return K_DEFAULT;}
do {prtTok("do"); return K_DO;}
else {prtTok("else"); return K_ELSE;}
enum {prtTok("enum"); return K_ENUM;}
false {prtTok("false"); return K_FALSE;}
for {prtTok("for"); return K_FOR;}
func {prtTok("func"); return K_FUNC;}
if {prtTok("if"); return K_IF;}
import {prtTok("import"); return K_IMPORT;}
in {prtTok("in"); return K_IN;}
init {prtTok("init"); return K_INIT;}
let {prtTok("let"); return K_LET;}
nil {prtTok("nil"); return K_NIL;}
print {prtTok("print"); return K_PRINT;}
println {prtTok("println"); return K_PRINTLN;}
public {prtTok("public"); return K_PUBLIC;}
return {prtTok("return"); return K_RETURN;}
self {prtTok("self"); return K_SELF;}
static {prtTok("static"); return K_STATIC;}
struct {prtTok("struct"); return K_STRUCT;}
switch {prtTok("switch"); return K_SWITCH;}
true {prtTok("true"); return K_TRUE;}
var {prtTok("var"); return K_VAR;}
where {prtTok("where"); return K_WHERE;}
while {prtTok("while"); return K_WHILE;}
void {prtTok("void"); return K_VOID;}
read {prtTok("read"); return K_READ;}


String {prtTok("String"); return TYP_STR;}
Int {prtTok("Int"); return TYP_INT;}
Bool {prtTok("Bool"); return TYP_BOOL;}
Float {prtTok("Float"); return TYP_FLOAT;}
Double {prtTok("Double"); return TYP_DOUBLE;}

{identifier} {yylval.varId = handleIdfyTok("identifier"); return IDFY;}
{integer} {yylval.intVal = handleIntTok("integer"); return CONST_INT;}
{real_num} {yylval.realVal = handleRealTok("real"); return CONST_REAL;}

\" {
		catLine();
		BEGIN STRING;			
	}
<STRING>\" {	
				yylval.strVal = handleStrTok("string");
				BEGIN INITIAL;
				return CONST_STR;
			}
<STRING>[^"\n]* |
<STRING>\"\" {
				strncat(strBuffer, yytext, yyleng);
				catLine();
			}



[ \t]* {catLine();}
<INITIAL,MULTI_COMMENT>\n { 
		newline();
	}

<STRING>\n {
		strncat(strBuffer, yytext, yyleng);
		newline();
	}

"//".*[^\n] {catLine();}
"/*" {
		catLine();
		BEGIN MULTI_COMMENT;
	}
<MULTI_COMMENT>"*/" {
		catLine();
		BEGIN INITIAL;
	}
<MULTI_COMMENT>. {
		catLine();
	}

. {
	catLine();
	prtLine(lineCounter, lineBuffer);
	printf("\nbad character:’%s’\n",yytext);
	exit(-1);
}
%%

void newline() {
	catLine();
	prtLine(lineCounter, lineBuffer);
	clearLineBuffer();
	lineCounter++;
}

void prtLine(int lineNum, char * line) {
	printf("%d: %s", lineNum, line);
}

void clearLineBuffer() {
	lineBuffer[0] = '\0';
}

void catLine() {
	strncat(lineBuffer, yytext, yyleng);
}

void prtTok(char * token) {
	catLine();
	// printf("\t<%s>\n", token);
}

char * handleIdfyTok(char * token) {
	catLine();
	
	printf("\t<%s:%s>\n", token, yytext);
	char * idfy = copyString(yytext);
	return idfy;
}

char * handleStrTok(char * token) {
	catLine();

	discardEscape(strBuffer);
	printf("\t<%s:%s>\n", token, strBuffer);
	char * strVal = copyString(strBuffer);
	strBuffer[0] = '\0';

	return strVal;
}

void discardEscape(char * strVal) {
	char * escapePos;
	for(;escapePos = strchr(strVal, '\"'); strVal = escapePos + 1) {
		memmove(escapePos, escapePos + 1, strlen(escapePos));
	}
}

int handleIntTok(char * token) {
	catLine();
	int intVal = 0;
	sscanf(yytext, "%d", &intVal);
	printf("\t<%s:%d>\n", token, intVal);
	return intVal;
}

double handleRealTok(char * token) {
	catLine();
	double realVal = 0;
	sscanf(yytext, "%lf", &realVal);
	printf("\t<%s:%s(=%lf)>\n", token, yytext, realVal);
	return realVal;
}

char * copyString(char * origin) {
	char * copy = (char *)malloc(sizeof(char) * strlen(origin));
	strcpy(copy, origin);

	return copy;
}



int yywrap() {
	newline();
	printf("\n");
	return 1;
}

