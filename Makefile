parser: lex.yy.o y.o symbol.o exp.o jasm_help.o
	gcc -o parser lex.yy.o y.tab.o SymbolTable.o ExpInfo.o JASMWriter.o -ll -lm

lex.yy.o: y.o
	lex Proj1_B10115018.l
	gcc -c -g lex.yy.c

y.o:
	yacc -d Proj3_B10115018.y
	gcc -c -g y.tab.c

symbol.o:
	gcc -c -g SymbolTable.c

exp.o:
	gcc -c -g ExpInfo.c

jasm_help.o:
	gcc -c -g JASMWriter.c

clean:
	rm -f *.o lex.yy.c