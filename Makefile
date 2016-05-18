##
complier:lex.yy.c parser.tab.c
	gcc -o complier lex.yy.c parser.tab.c
	@echo Make Success!
lex.yy.c:lexer.l
	flex lexer.l
parser.tab.c:parser.y
	bison -d parser.y
clean:
	del lex.yy.c parser.tab.c parser.tab.h