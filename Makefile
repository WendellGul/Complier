##
SRC = lex.yy.c parser.tab.c tree.c symbol.c semantics.c ir.c target.c
OUT = compiler
ifdef mode
	make_mode = $(mode)
else
	make_mode = normal
endif
$(OUT): $(SRC)
	gcc -o $(OUT) $(SRC)
	@echo Make Success!
lex.yy.c: lexer.l parser.tab.h
	flex lexer.l
parser.tab.c parser.tab.h: parser.y
ifeq ($(make_mode), debug)
	bison -d -t parser.y
else
	bison -d parser.y
endif
clean:
	rm lex.yy.c parser.tab.c parser.tab.h