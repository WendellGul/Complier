%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "complier.h"
    #include "parser.tab.h"
    int yylex();
    int yywrap();
    void yyerror(char *s);
%}

%option yylineno
%start COMMENT1 COMMENT2

%%
"(*" { BEGIN COMMENT1; }
<COMMENT1>"*)" { BEGIN 0; }
<COMMENT1>[^*/]+ { /* do nothing */ }

"{" { BEGIN COMMENT2; }
<COMMENT2>"}" { BEGIN 0; }
<COMMENT2>[^\}]+ { /* do nothing */ }

"const" { return CONST; }
"var" { return VAR; }
"procedure" { return PROCEDURE; }
"begin" { return RESERVEDBEGIN; }
"end" { return END; }
"odd" { return ODD; }
"if" { return IF; }
"then" { return THEN; }
"call" { return CALL; }
"while" {return WHILE; }
"do" { return DO; }
"read" { return READ; }
"write" { return WRITE; }

"+" |
"-" |
"*" |
"/" { return yytext[0]; }

"<=" { return LEQ; }
">=" { return GEQ; }
"<"  { return yytext[0]; }
">"  { return yytext[0]; }
"#"  { return yytext[0]; }
"="  { return yytext[0]; }

":=" { return ASSIGN; }

"(" |
")" |
"," |
"." |
";" { return yytext[0]; }

([0-9])+ { 
            yylval.value = atoi(yytext);
            return INTEGER; 
         }

[A-Za-z]([A-Za-z0-9])* {
                          strcpy(yylval.name, yytext);
                          return ID; 
                       }

[ \n\t]+ { /* do nothing */ }

. { return ERROR; }

%%

int yywrap()
{
    return 1;
}

/*
int main(int argc, char **argv)
{
    if(argc <= 2)
    {
        printf("Invalid input!\n");
        return 0;
    }
    if((yyin = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        return 0;
    }
    FILE *result = fopen(argv[2], "w");
    int re;
    while(re = yylex())
    {
        if(re == ERROR)
            fprintf(result, "ERR %-10s\n", yytext);
        else
            fprintf(result, "%-4d%-10s\n", re, yytext);
    }
    return 0;
}
*/
