%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include "complier.h"
    #define TABNUM 3
    void yyerror(char *);
    extern int yylex();
    extern int yylineno;
    FILE *yyin;
    FILE *yyout;
    char *yytext;
    
    TreeNode* nTerminal(char *name, TreeNode *child);
    TreeNode* terminal(NodeType type, int value, char *name);
    void addBro(TreeNode *p, TreeNode *bro);
    void generate(TreeNode *p, int tab);
    void printNode(TreeNode *p, int tab);
    void freeNode(TreeNode *p);

%}

%union {
    int value; // integer value
    char name[30]; // name of variable
    TreeNode *nPtr; // node pointer
};
%token CONST VAR PROCEDURE RESERVEDBEGIN END ODD IF THEN CALL WHILE DO READ WRITE ASSIGN
%token<value> INTEGER
%token<name> ID
%token ERROR
%left LEQ GEQ '=' '#' '>' '<'
%left '+' '-'
%left '*' '/' 

%type<nPtr> program subprogram subprogram_part1 subprogram_part2 subprogram_part3
%type<nPtr> const_declare const_declare_part1 const_define var_declare var_declare_part1
%type<nPtr> procedure_declare procedure_header statement assign complex complex_part1 condition
%type<nPtr> expression expression_part1 sign item item_part1 factor addsub muldiv cmp
%type<nPtr> condition_statment call loop read read_part1 write write_part1

%%
program_start:
    program {
        generate($1, 0);
        freeNode($1);
    }
    ;
program:
    subprogram '.' { 
        $$ = nTerminal("program", $1);
        addBro($1, terminal(typeOpr, '.', ""));
    }
    ;
subprogram:
    subprogram_part1 subprogram_part2 subprogram_part3 statement {
        $$ = nTerminal("subprogram", $1);
        addBro($1, $2);
        addBro($2, $3);
        addBro($3, $4);
    }
    ;
subprogram_part1: { $$ = nTerminal("", NULL); }
    | const_declare {
        $$ = nTerminal("subprogram_part1", $1);
    }
    ;
subprogram_part2: { $$ = nTerminal("", NULL); }
    | var_declare { 
        $$ = nTerminal("subprogram_part2", $1);
    }
    ;
subprogram_part3: { $$ = nTerminal("", NULL); }
    | procedure_declare { 
        $$ = nTerminal("subprogram_part3", $1);
    }
    ;
const_declare:
    CONST const_define const_declare_part1 ';' {
        TreeNode *p = terminal(typeReserve, CONST, "");
        $$ = nTerminal("const_declare", p);
        addBro(p, $2);
        addBro($2, $3);
        addBro($3, terminal(typeOpr, ';', ""));
    }
    ;
const_declare_part1: { $$ = nTerminal("", NULL); }
    | ',' const_define const_declare_part1 { 
        TreeNode *p = terminal(typeOpr, ',', "");
        $$ = nTerminal("const_declare_part1", p);
        addBro(p, $2);
        addBro($2, $3);
    }
    ;
const_define:
    ID '=' INTEGER { 
        TreeNode *p1, *p2;
        p1 = terminal(typeId, 0, $1);
        p2 = terminal(typeOpr, '=', "");
        $$ = nTerminal("const_declare", p1);
        addBro(p1, p2);
        addBro(p2, terminal(typeCon, $3, ""));
    }
    ;
var_declare:
    VAR ID var_declare_part1 ';' { 
        TreeNode *pVar, *pId;
        pVar = terminal(typeReserve, VAR, "");
        pId = terminal(typeId, 0, $2);
        $$ = nTerminal("var_declare", pVar);
        addBro(pVar, pId);
        addBro(pId, $3);
        addBro($3, terminal(typeOpr, ';', ""));
    }
    ;
var_declare_part1: { $$ = nTerminal("", NULL); }
    | ',' ID var_declare_part1 { 
        TreeNode *p1, *pId;
        p1 = terminal(typeOpr, ',', "");
        pId = terminal(typeId, 0, $2);
        $$ = nTerminal("var_declare_part1", p1);
        addBro(p1, pId);
        addBro(pId, $3);
    }
    ;
procedure_declare:
    procedure_header subprogram ';' {
        $$ = nTerminal("procedure_declare", $1);
        addBro($1, $2);
        addBro($2, terminal(typeOpr, ';', ""));
    }
    | procedure_header subprogram ';' procedure_declare {
        TreeNode *p = terminal(typeOpr, ';', "");
        $$ = nTerminal("procedure_declare", $1);
        addBro($1, $2);
        addBro($2, p);
        addBro(p, $4);
    }
    ;
procedure_header:
    PROCEDURE ID ';' { 
        TreeNode *p1, *p2, *p3;
        p1 = terminal(typeReserve, PROCEDURE, "");
        p2 = terminal(typeId, 0, $2);
        p3 = terminal(typeOpr, ';', "");
        $$ = nTerminal("procedure_header", p1);
        addBro(p1, p2);
        addBro(p2, p3);
    }
    ;
statement: { $$ = nTerminal("", NULL); }
    | assign {
        $$ = nTerminal("statement", $1);
    }
    | condition_statment {
        $$ = nTerminal("statement", $1);
    }
    | loop {
        $$ = nTerminal("statement", $1);
    }
    | call {
        $$ = nTerminal("statement", $1);
    }
    | read {
        $$ = nTerminal("statement", $1);
    }
    | write {
        $$ = nTerminal("statement", $1);
    }
    | complex {
        $$ = nTerminal("statement", $1);
    }
    ;
assign:
    ID ASSIGN expression {
        TreeNode *p1, *p2;
        p1 = terminal(typeId, 0, $1);
        p2 = terminal(typeReserve, ASSIGN, "");
        $$ = nTerminal("assign", p1);
        addBro(p1, p2);
        addBro(p2, $3);
    }
    ;
complex:
    RESERVEDBEGIN statement complex_part1 END {
        TreeNode *p = terminal(typeReserve, RESERVEDBEGIN, "");
        $$ = nTerminal("complex", p);
        addBro(p, $2);
        addBro($2, $3);
        addBro($3, terminal(typeReserve, END, ""));
    }
    ;
complex_part1: { $$ = nTerminal("", NULL); }
    | ';' statement complex_part1 {
        TreeNode *p = terminal(typeOpr, ';', "");
        $$ = nTerminal("complex_part1", p);
        addBro(p, $2);
        addBro($2, $3);
    }
    ;
condition:
    expression cmp expression {
        $$ = nTerminal("condition", $1);
        addBro($1, $2);
        addBro($2, $3);
    }
    | ODD expression {
        TreeNode *p = terminal(typeReserve, ODD, "");
        $$ = nTerminal("condition", p);
        addBro(p, $2);
    }
    ;
expression:
    sign item expression_part1 {
        $$ = nTerminal("expression", $1);
        addBro($1, $2);
        addBro($2, $3);
    }
    ;
expression_part1: { $$ = nTerminal("", NULL); }
    | addsub item expression_part1 {
        $$ = nTerminal("expression_part1", $1);
        addBro($1, $2);
        addBro($2, $3);
    }
    ;
sign: { $$ = nTerminal("", NULL); }
    | '+' {
        $$ = nTerminal("sign", terminal(typeOpr, '+', ""));
    }
    | '-' {
        $$ = nTerminal("sign", terminal(typeOpr, '-', ""));
    }
    ;
item:
    factor item_part1 {
        $$ = nTerminal("item", $1);
        addBro($1, $2);
    }
    ;
item_part1: { $$ = nTerminal("", NULL); }
    | muldiv factor item_part1 {
        $$ = nTerminal("item_part1", $1);
        addBro($1, $2);
        addBro($2, $3);
    }
    ;
factor:
    ID {
        $$ = nTerminal("factor", terminal(typeId, 0, $1));
    }
    | INTEGER {
        $$ = nTerminal("factor", terminal(typeCon, $1, ""));
    }
    | '(' expression ')' {
        TreeNode *p = terminal(typeOpr, '(', "");
        $$ = nTerminal("factor", p);
        addBro(p, $2);
        addBro($2, terminal(typeOpr, ')', ""));
    }
    ;
addsub:
    '+' {
        $$ = terminal(typeOpr, '+', "");
    }
    | '-' {
        $$ = terminal(typeOpr, '-', "");
    }
    ;
muldiv:
    '*' {
        $$ = terminal(typeOpr, '*', "");
    }
    | '/' {
        $$ = terminal(typeOpr, '/', "");
    }
    ;
cmp:
    '=' {
        $$ = terminal(typeOpr, '=', "");
    }
    | '#' {
        $$ = terminal(typeOpr, '#', "");
    }
    | '<' {
        $$ = terminal(typeOpr, '<', "");
    }
    | LEQ {
        $$ = terminal(typeOpr, LEQ, "");
    }
    | '>' {
        $$ = terminal(typeOpr, '>', "");
    }
    | GEQ {
        $$ = terminal(typeOpr, GEQ, "");
    }
    ;
condition_statment:
    IF condition THEN statement {
        TreeNode *p1, *p3;
        p1 = terminal(typeReserve, IF, "");
        p3 = terminal(typeReserve, THEN, "");
        $$ = nTerminal("condition_statment", p1);
        addBro(p1, $2);
        addBro($2, p3);
        addBro(p3, $4);
    }
    ;
call:
    CALL ID {
        TreeNode *p = terminal(typeReserve, CALL, "");
        $$ = nTerminal("call", p);
        addBro(p, terminal(typeId, 0, $2));
    }
    ;
loop:
    WHILE condition DO statement {
        TreeNode *p1, *p3;
        p1 = terminal(typeReserve, WHILE, "");
        p3 = terminal(typeReserve, DO, "");
        $$ = nTerminal("loop", p1);
        addBro(p1, $2);
        addBro($2, p3);
        addBro(p3, $4);
    }
    ;
read:
    READ '(' ID read_part1 ')' {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(typeReserve, READ, "");
        p2 = terminal(typeOpr, '(', "");
        p3 = terminal(typeId, 0, $3);
        $$ = nTerminal("read", p1);
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, $4);
        addBro($4, terminal(typeOpr, ')', ""));
    }
    ;
read_part1: { $$ = nTerminal("", NULL); }
    | ',' ID read_part1 {
        TreeNode *p1, *p2;
        p1 = terminal(typeOpr, ',', "");
        p2 = terminal(typeId, 0, $2);
        $$ = nTerminal("read_part1", p1);
        addBro(p1, p2);
        addBro(p2, $3);
    }
    ;
write:
    WRITE '(' expression write_part1 ')' {
        TreeNode *p1, *p2;
        p1 = terminal(typeReserve, WRITE, "");
        p2 = terminal(typeOpr, '(', "");
        $$ = nTerminal("write", p1);
        addBro(p1, p2);
        addBro(p2, $3);
        addBro($3, $4);
        addBro($4, terminal(typeOpr, ')', ""));
    }
    ;
write_part1: { $$ = nTerminal("", NULL); }
    | ',' expression write_part1 {
        TreeNode *p = terminal(typeOpr, ',', "");
        $$ = nTerminal("write_part1", p);
        addBro(p, $2);
        addBro($2, $3);
    }
    ;

%%
void yyerror(char *s)
{
    fprintf(stderr, "line:%d %s near '%s'", yylineno, s, yytext);
}

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
    yyout = fopen(argv[2], "w");
    yyparse();
    fclose(yyin);
    fclose(yyout);
    return 0;
}

TreeNode* nTerminal(char *name, TreeNode *child)
{
    TreeNode *p;
    if((p = (TreeNode *)malloc(sizeof(TreeNode))) == NULL)
        return NULL;
    p->isTerminal = 0;
    strcpy(p->ntnode.name, name);
    p->child = child;
    p->bro = NULL;
    return p;
}

TreeNode* terminal(NodeType type, int value, char *name)
{
    TreeNode *p;
    if((p = (TreeNode *)malloc(sizeof(TreeNode))) == NULL)
        return NULL;
    p->isTerminal = 1;
    p->tnode.type = type;
    p->tnode.value = value;
    strcpy(p->tnode.name, name);
    p->child = NULL;
    p->bro = NULL;
    return p;
}

void addBro(TreeNode *p, TreeNode *bro)
{
    p->bro = bro;
}

void freeNode(TreeNode *p)
{
    if(p == NULL)
        return ;
    TreeNode *pChild, *pBro;
    pChild = p->child;
    freeNode(pChild);
    if(pChild != NULL)
        for(pBro = pChild->bro; pBro != NULL; pBro = pBro->bro)
            freeNode(pBro);
    free(p);
}

void generate(TreeNode *p, int tab)
{
    if(p == NULL)
        return ;
    TreeNode *pChild, *pBro;
    printNode(p, tab);
    pChild = p->child;
    generate(pChild, tab + 1);
    if(pChild != NULL)
        for(pBro = pChild->bro; pBro != NULL; pBro = pBro->bro)
            generate(pBro, tab + 1);
}

void printNode(TreeNode *p, int tab)
{
    int i = 0;
    if(p->isTerminal == 1)
    {
        while(tab != 0 && i++ < TABNUM * (tab - 1))
            fprintf(yyout, " ");
        if(tab != 0)
            fprintf(yyout, "|__");
        TNode tnode = p->tnode;
        switch(tnode.type)
        {
            case typeCon:
                fprintf(yyout, "INT: %d\n", tnode.value);
            break;
            case typeId:
                fprintf(yyout, "ID: %s\n", tnode.name);
            break;
            case typeOpr:
                switch(tnode.value)
                {
                    case LEQ: fprintf(yyout, "OPER: LEQ\n"); break;
                    case GEQ: fprintf(yyout, "OPER: GEQ\n"); break;
                    default : fprintf(yyout, "OPER: '%c'\n", tnode.value);
                }       
            break;
            case typeReserve:
                switch(tnode.value)
                {
                    case CONST: fprintf(yyout, "RESERVED: CONST\n"); break;
                    case VAR: fprintf(yyout, "RESERVED: VAR\n"); break;
                    case PROCEDURE: fprintf(yyout, "RESERVED: PROCEDURE\n"); break;
                    case RESERVEDBEGIN: fprintf(yyout, "RESERVED: BEGIN\n"); break;
                    case END: fprintf(yyout, "RESERVED: END\n"); break;
                    case ODD: fprintf(yyout, "RESERVED: ODD\n"); break;
                    case IF: fprintf(yyout, "RESERVED: IF\n"); break;
                    case THEN: fprintf(yyout, "RESERVED: THEN\n"); break;
                    case CALL: fprintf(yyout, "RESERVED: CALL\n"); break;
                    case WHILE: fprintf(yyout, "RESERVED: WHILE\n"); break;
                    case DO: fprintf(yyout, "RESERVED: DO\n"); break;
                    case READ: fprintf(yyout, "RESERVED: READ\n"); break;
                    case WRITE: fprintf(yyout, "RESERVED: WRITE\n"); break;
                    case ASSIGN: fprintf(yyout, "RESERVED: ASSIGN\n"); break;
                }
            break;
        }
    }
    else
    {
        NTNode ntnode = p->ntnode;
        if(strcmp(ntnode.name, "") != 0)
        {
            while(tab != 0 && i++ < TABNUM * (tab - 1))
                fprintf(yyout, " ");
            if(tab != 0)
                fprintf(yyout, "|__");
            fprintf(yyout, "%s\n", ntnode.name);
        }
    }
}

