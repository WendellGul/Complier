%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "compiler.h"
    #include "parser.tab.h"
    int yycolumn = 1;
    #define YY_USER_ACTION \
        yylloc.first_line = yylloc.last_line = yylineno; \
        yylloc.first_column = yycolumn; \
        yylloc.last_column = yycolumn + yyleng - 1; \
        yycolumn += yyleng;
%}

%option yylineno
%start COMMENT1

%%
"/*" { BEGIN COMMENT1; }
<COMMENT1>"*/" { BEGIN 0; }
<COMMENT1>[^*/]+ { /* do nothing */ }

"int"       { return KW_INT; }
"float"     { return KW_FLOAT; }
"char"      { return KW_CHAR; }
"struct"    { return KW_STRUCT; }
"return"    { return KW_RETURN; }
"if"        { return KW_IF; }
"else"      { return KW_ELSE; }
"while"     { return KW_WHILE; }
"continue"  { return KW_CONTINUE; }
"break"     { return KW_BREAK; }

"+" |
"-" |
"*" |
"/" |
"%"  { return yytext[0]; }

"||" { return TK_OR;    }
"&&" { return TK_AND;   }
"!"  { return yytext[0];}

"<=" { return TK_LEQ; }
">=" { return TK_GEQ; }
"==" { return TK_EQ;  }
"!=" { return TK_NEQ; }
"<"  { return yytext[0]; }
">"  { return yytext[0]; }

"="  { return yytext[0]; }

"[" |
"]" |
"{" |
"}" |
"(" |
")" |
"," |
"." |
";" { return yytext[0]; }

([0-9])+ { 
    yylval.iValue = atoi(yytext);
    return TK_CINT; 
}

([0-9])*[.]([0-9])+ {
    yylval.fValue = atof(yytext);
    return TK_CFLOAT;
}

\'.\' {
    yylval.cValue = yytext[1];
    return TK_CCHAR;
}

"\'\'" {
    yylval.cValue = '\0';
    return TK_CCHAR;
}

"\'\\n\'" {
    yylval.cValue = '\n';
    return TK_CCHAR;
}

"\'\\t\'" {
    yylval.cValue = '\t';
    return TK_CCHAR;
}

\"(.|\\n|\\t)+\" {
    yylval.sValue = (char *)malloc(sizeof(char) * (yyleng - 1));
    if(yylval.sValue == NULL)
        return ERROR;
    strcpy(yylval.sValue, yytext + 1);
    (yylval.sValue)[strlen(yylval.sValue) - 1] = '\0';
    return TK_CSTR;
}

"\"\"" {
    yylval.sValue = (char *)malloc(sizeof(char) * 2);
    if(yylval.sValue == NULL)
        return ERROR;
    strcpy(yylval.sValue, "");
    return TK_CSTR;
}

[A-Za-z]([A-Za-z0-9])* {
    strcpy(yylval.name, yytext);
    return TK_ID; 
}

[ \n\t]+ { /* do nothing */ }

. { printf("Error type A at line %d: Mysterious character \"%s\".", yylineno, yytext); return ERROR; }

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
