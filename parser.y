%{
    #include "compiler.h"
    void yyerror(char *);
    extern int yylex();
    void setFileName(char *tar, char *src, char *postfix);
    FILE *treeFile = NULL;
    FILE *targetFile = NULL;
    TreeNode *syntaxTree = NULL;
    char message[100];
    ErrorType et = ERR_OTHER;
%}

%union {
    int iValue; // integer value
    char cValue; // char value
    float fValue; // float value
    char *sValue; // string value
    char name[30]; // name of variable
    TreeNode *nPtr; // node pointer
};

%token KW_INT KW_FLOAT KW_CHAR KW_STRUCT KW_RETURN KW_IF KW_ELSE KW_WHILE KW_CONTINUE KW_BREAK
%token<iValue> TK_CINT TK_CCHAR
%token<fValue> TK_CFLOAT
%token<sValue> TK_CSTR
%token<name> TK_ID
%token ERROR

/* 优先级和结合性 */
%nonassoc LOWER_THAN_ELSE
%nonassoc KW_ELSE
%right '='
%left TK_OR
%left TK_AND
%left TK_LEQ TK_GEQ TK_EQ TK_NEQ '>' '<'
%left '+' '-'
%left '*' '/' '%'
%right '!'
%left '(' ')' '.' '[' ']'

%type<nPtr> program extern_define_list extern_define extern_declare_list
%type<nPtr> specifier type struct_specifier option_tag
%type<nPtr> var_declare function_declare param_list param_declare
%type<nPtr> compound_statement statement_list statement
%type<nPtr> define_list define declare_list declare
%type<nPtr> expression relation_op args

%%
program_start:
    program {
        syntaxTree = $1;
    }
    ;
program:
    extern_define_list {
        $$ = nTerminal(Program, $1);
        $1->parent = $$;
    }
    ;
extern_define_list: { $$ = nTerminal(None, NULL);}
    | extern_define extern_define_list {
        $$ = nTerminal(ExtDefList, $1);
        $1->parent = $$;
        addBro($1, $2);
    }
    ;
extern_define:
    specifier extern_declare_list ';' {
        $$ = nTerminal(ExtDef, $1);
        $1->parent = $$;
        addBro($1, $2);
        addBro($2, terminal(_SEMI, ';', ""));    
    }
    | specifier ';' {
        $$ = nTerminal(ExtDef, $1);
        $1->parent = $$;
        addBro($1, terminal(_SEMI, ';', ""));
    }
    | specifier function_declare compound_statement {
        $$ = nTerminal(ExtDef, $1);
        $1->parent = $$;
        addBro($1, $2);
        addBro($2, $3);
    }
    | specifier error ';' {
        TreeNode *p2 = terminal(None, 0, "");
        $$ = nTerminal(ExtDef, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE1);
        m_error("something wrong with ExtDecList before \";\"", @2.last_line);
        setErrType(ERR_OTHER);
    }
    | error ';' {
        TreeNode *p1 = terminal(None, 0, "");
        $$ = nTerminal(ExtDef, p1);
        p1->parent = $$;
        addBro(p1, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE1);
        m_error("something wrong with Specifier before \";\"", @1.last_line);
        setErrType(ERR_OTHER);
    }
    ;
extern_declare_list:
    declare {
        $$ = nTerminal(ExtDecList, $1);
        $1->parent = $$;
    }
    | declare ',' extern_declare_list {
        TreeNode *p2 = terminal(_COMMA, ',', "");
        $$ = nTerminal(ExtDecList, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    ;
specifier:
    type {
        $$ = nTerminal(Specifier, $1);
        $1->parent = $$;
    }
    | struct_specifier {
        $$ = nTerminal(Specifier, $1);
        $1->parent = $$;
    }
    ;
type:
    KW_INT { 
        TreeNode *p1 = terminal(_INT, KW_INT, "");
        $$ = nTerminal(_TYPE, p1);
        p1->parent = $$;
    }
    | KW_FLOAT { 
        TreeNode *p1 = terminal(_FLOAT, KW_FLOAT, "");
        $$ = nTerminal(_TYPE, p1);
        p1->parent = $$; 
    }
    ;
struct_specifier:
    KW_STRUCT option_tag '{' define_list '}' {
        TreeNode *p1, *p3;
        p1 = terminal(_STRUCT, KW_STRUCT, "");
        p3 = terminal(_BEGIN, '{', "");
        $$ = nTerminal(StructSpecifier, p1);
        p1->parent = $$;
        addBro(p1, $2);
        addBro($2, p3);
        addBro(p3, $4);
        addBro($4, terminal(_END, '}', ""));
    }
    | KW_STRUCT TK_ID {
        // 语法树相关
        TreeNode *p1 = terminal(_STRUCT, KW_STRUCT, "");
        $$ = nTerminal(StructSpecifier, p1);
        p1->parent = $$;
        addBro(p1, terminal(_ID, 0, $2));
    }
    ;
option_tag: { $$ = nTerminal(None, NULL); }
    | TK_ID {
        TreeNode *p1 = terminal(_ID, 0, $1);
        $$ = nTerminal(OptTag, p1);
        p1->parent = $$;
    }
    ;
var_declare:
    TK_ID {
        TreeNode *p1 = terminal(_ID, 0, $1);
        $$ = nTerminal(VarDec, p1);
        p1->parent = $$;
    }
    | var_declare '[' TK_CINT ']' {
        TreeNode *p2, *p3;
        p2 = terminal(_LB, '[', "");
        p3 = terminal(_INT, $3, "");
        $$ = nTerminal(VarDec, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, p3);
        addBro(p3, terminal(_RB, ']', ""));
    }
    | var_declare '[' error ']' {
        TreeNode *p2, *p3;
        p2 = terminal(_LB, '[', "");
        p3 = terminal(None, 0, "");
        $$ = nTerminal(VarDec, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, p3);
        addBro(p3, terminal(_RB, ']', ""));
        setErrType(ERR_TYPE2);
        m_error("missing a integer between \"[]\"", @3.last_line);
        setErrType(ERR_OTHER);
    }
    ;
function_declare:
    TK_ID '(' param_list ')' {
        TreeNode *p1, *p2;
        p1 = terminal(_ID, 0, $1);
        p2 = terminal(_LP, '(', "");
        $$ = nTerminal(FuncDec, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, $3);
        addBro($3, terminal(_RP, ')', ""));
    }
    | TK_ID '(' ')' {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_ID, 0, $1);
        p2 = terminal(_LP, '(', "");
        p3 = terminal(_RP, ')', "");
        $$ = nTerminal(FuncDec, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
    }
    | TK_ID '(' error ')' {
        TreeNode *p1, *p2, *p3, *p4;
        p1 = terminal(_ID, 0, $1);
        p2 = terminal(_LP, '(', "");
        p3 = terminal(None, 0, "");
        p4 = terminal(_RP, ')', "");
        $$ = nTerminal(FuncDec, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, p4);
        setErrType(ERR_TYPE3);
        m_error("something wrong with VarList between \"()\"", @3.last_line);
        setErrType(ERR_OTHER);
    }
    | TK_ID error ')' {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_ID, 0, $1);
        p2 = terminal(None, 0, "");
        p3 = terminal(_RP, ')', "");
        $$ = nTerminal(FuncDec, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
        setErrType(ERR_TYPE3);
        m_error("missing \"(\"", @2.last_line);
        setErrType(ERR_OTHER);
    }
    ;
param_list:
    param_declare ',' param_list {
        TreeNode *p2 = terminal(_COMMA, ',', "");
        $$ = nTerminal(ParamList, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | param_declare {
        $$ = nTerminal(ParamList, $1);
        $1->parent = $$;
    }
    | error ',' param_list {
        TreeNode *p1, *p2;
        p1 = terminal(None, 0, "");
        p2 = terminal(_COMMA, ',', "");
        $$ = nTerminal(ParamList, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, $3);
        setErrType(ERR_TYPE4);
        m_error("something wrong with ParamDec", @1.last_line);
        setErrType(ERR_OTHER);
    }
    ;
param_declare:
    specifier var_declare {
        $$ = nTerminal(ParamDec, $1);
        $1->parent = $$;
        addBro($1, $2);
    }
    ;
compound_statement:
    '{' define_list statement_list '}' {
        TreeNode *p1 = terminal(_BEGIN, '{', "");
        $$ = nTerminal(CompSt, p1);
        p1->parent = $$;
        addBro(p1, $2);
        addBro($2, $3);
        addBro($3, terminal(_END, '}', ""));
    }
    | error '}' {
        TreeNode *p1, *p2;
        p1 = terminal(None, 0, "");
        p2 = terminal(_BEGIN, '}', "");
        $$ = nTerminal(CompSt, p1);
        p1->parent = $$;
        addBro(p1, p2);
        setErrType(ERR_TYPE5);
        m_error("missing \"{\"", @1.first_line);
        setErrType(ERR_OTHER);
    }
    ;
statement_list: { $$ = nTerminal(None, NULL); }
    | statement statement_list {
        $$ =  nTerminal(StmtList, $1);
        $1->parent = $$;
        addBro($1, $2);
    }
    ;
statement:
    expression ';' {
        $$ = nTerminal(Statement, $1);
        $1->parent = $$;
        addBro($1, terminal(_SEMI, ';', ""));
    }
    | error ';' {
        TreeNode *p1 = terminal(None, 0, "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE6);
        m_error("something wrong with expression before \";\"", @1.last_line);
        setErrType(ERR_OTHER);
    }
    | compound_statement {
        $$ = nTerminal(Statement, $1);
        $1->parent = $$;
    }
    | KW_RETURN expression ';' {
        TreeNode *p1 = terminal(_RETURN, KW_RETURN, "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, $2);
        addBro($2, terminal(_SEMI, ';', ""));
    }
    | KW_RETURN error ';' {
        TreeNode *p1, *p2;
        p1 = terminal(_RETURN, KW_RETURN, "");
        p2 = terminal(None, 0, "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE6);
        m_error("something wrong with expression before \";\"", @2.last_line);
        setErrType(ERR_OTHER);
    }
    | KW_IF '(' expression ')' statement %prec LOWER_THAN_ELSE {
        TreeNode *p1, *p2, *p4;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, $3);
        addBro($3, p4);
        addBro(p4, $5);
    }
    | KW_IF '(' error ')' statement %prec LOWER_THAN_ELSE {
        TreeNode *p1, *p2, *p3, *p4;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p3 = terminal(None, 0, "");
        p4 = terminal(_RP, ')', "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, p4);
        addBro(p4, $5);
        setErrType(ERR_TYPE6);
        m_error("something wrong with expression between \"()\"", @3.last_line);
        setErrType(ERR_OTHER);
    }
    | KW_IF error ')' statement %prec LOWER_THAN_ELSE {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(None, 0, "");
        p3 = terminal(_RP, ')', "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, $4);
        setErrType(ERR_TYPE6);
        m_error("missing \"(\"", @2.last_line);
        setErrType(ERR_OTHER);
    }
    | KW_IF '(' expression ')' statement KW_ELSE statement {
        TreeNode *p1, *p2, *p4, *p6;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        p6 = terminal(_ELSE, KW_ELSE, "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, $3);
        addBro($3, p4);
        addBro(p4, $5);
        addBro($5, p6);
        addBro(p6, $7);
    }
    | KW_IF '(' expression ')' error KW_ELSE statement {
        TreeNode *p1, *p2, *p4, *p5, *p6;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        p5 = terminal(None, 0, "");
        p6 = terminal(_ELSE, KW_ELSE, "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, $3);
        addBro($3, p4);
        addBro(p4, p5);
        addBro(p5, p6);
        addBro(p6, $7);
        setErrType(ERR_TYPE6);
        m_error("missing \";\"", @5.last_line);
        setErrType(ERR_OTHER);
    }
    | KW_IF '(' error ')' statement KW_ELSE statement {
        TreeNode *p1, *p2, *p3, *p4, *p6;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p3 = terminal(None, 0, "");
        p4 = terminal(_RP, ')', "");
        p6 = terminal(_ELSE, KW_ELSE, "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, p4);
        addBro(p4, $5);
        addBro($5, p6);
        addBro(p6, $7);
        setErrType(ERR_TYPE6);
        m_error("something wrong with expression between \"()\"", @3.last_line);
        setErrType(ERR_OTHER);
    }
    | KW_IF error ')' statement KW_ELSE statement {
        TreeNode *p1, *p2, *p3, *p5;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(None, 0, "");
        p3 = terminal(_RP, ')', "");
        p5 = terminal(_ELSE, KW_ELSE, "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, $4);
        addBro($4, p5);
        addBro(p5, $6);
        setErrType(ERR_TYPE6);
        m_error("missing \"(\"", @2.last_line);
        setErrType(ERR_OTHER);
    }
    | KW_WHILE '(' expression ')' statement {
        TreeNode *p1, *p2, *p4;
        p1 = terminal(_WHILE, KW_WHILE, "");
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, $3);
        addBro($3, p4);
        addBro(p4, $5);
    }
    | KW_WHILE '(' error ')' statement {
        TreeNode *p1, *p2, *p3, *p4;
        p1 = terminal(_WHILE, KW_WHILE, "");
        p2 = terminal(_LP, '(', "");
        p3 = terminal(None, 0, "");
        p4 = terminal(_RP, ')', "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, p4);
        addBro(p4, $5);
        m_error("something wrong with expression between \"()\"", @3.last_line);
    }
    | KW_WHILE error ')' statement {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_WHILE, KW_WHILE, "");
        p2 = terminal(None, 0, "");
        p3 = terminal(_RP, ')', "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, $4);
        m_error("missing \"(\"", @2.last_line);
    }
    | KW_BREAK ';' {
        TreeNode *p1 = terminal(_BREAK, KW_BREAK, "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, terminal(_SEMI, ';', ""));
    }
    | KW_CONTINUE ';' {
        TreeNode *p1 = terminal(_CONTINUE, KW_CONTINUE, "");
        $$ = nTerminal(Statement, p1);
        p1->parent = $$;
        addBro(p1, terminal(_SEMI, ';', ""));
    }
    ;
define_list: { $$ = nTerminal(None, NULL); }
    | define define_list {
        $$ = nTerminal(DefList, $1);
        $1->parent = $$;
        addBro($1, $2);
    }
    ;
define:
    specifier declare_list ';' {
        $$ = nTerminal(Define, $1);
        $1->parent = $$;
        addBro($1, $2);
        addBro($2, terminal(_SEMI, ';', ""));
    }
    | specifier error ';' {
        TreeNode *p2 = terminal(None, 0, "");
        $$ = nTerminal(Define, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE7);
        m_error("missing declare_list", @2.last_line);
        setErrType(ERR_OTHER);
    }
    ;
declare_list:
    declare {
        $$ = nTerminal(DecList, $1);
        $1->parent = $$;
    }
    | declare ',' declare_list {
        TreeNode *p2 = terminal(_COMMA, ',', "");
        $$ = nTerminal(DecList, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | error ',' declare_list {
        TreeNode *p1, *p2;
        p1 = terminal(None, 0, "");
        p2 = terminal(_COMMA, ',', "");
        $$ = nTerminal(DecList, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, $3);
        setErrType(ERR_TYPE8);
        m_error("something wrong with declaration", @1.last_line);
        setErrType(ERR_OTHER);
    }
    | declare ',' error {
        TreeNode *p2, *p3;
        p2 = terminal(_COMMA, ',', "");
        p3 = terminal(None, 0, "");
        $$ = nTerminal(DecList, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, p3);
        setErrType(ERR_TYPE8);
        m_error("unnecessary \",\"", @2.last_line);
        setErrType(ERR_OTHER);
    }
    ;
declare:
    var_declare {
        $$ = nTerminal(Declare, $1);
        $1->parent = $$;
    }
    | var_declare '=' expression {
        TreeNode *p2 = terminal(_ASSIGNOP, '=', "");
        $$ = nTerminal(Declare, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | error '=' expression {
        TreeNode *p1, *p2;
        p1 = terminal(None, 0, "");
        p2 = terminal(_ASSIGNOP, '=', "");
        $$ = nTerminal(Declare, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, $3);
        setErrType(ERR_TYPE9);
        m_error("missing the variable", @1.last_line);
        setErrType(ERR_OTHER);
    }
    ;
expression:
    expression '=' expression {
        TreeNode *p2 = terminal(_ASSIGNOP, '=', "");
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | expression TK_AND expression {
        TreeNode *p2 = terminal(_AND, TK_AND, "");
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | expression TK_OR expression {
        TreeNode *p2 = terminal(_OR, TK_OR, "");
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | expression relation_op expression {
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, $2);
        addBro($2, $3);
    }
    | expression '+' expression {
        TreeNode *p2 = terminal(_PLUS, '+', "");
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | expression '-' expression {
        TreeNode *p2 = terminal(_MINUS, '-', "");
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | expression '*' expression {
        TreeNode *p2 = terminal(_STAR, '*', "");
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | expression '/' expression {
        TreeNode *p2 = terminal(_DIV, '/', "");
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | '(' expression ')' {
        TreeNode *p1, *p3;
        p1 = terminal(_LP, '(', "");
        p3 = terminal(_RP, ')', "");
        $$ = nTerminal(Expression, p1);
        p1->parent = $$;
        addBro(p1, $2);
        addBro($2, p3);
    }
    | '-' expression %prec '!' {
        TreeNode *p1 = terminal(_MINUS, '-', "");
        $$ = nTerminal(Expression, p1);
        p1->parent = $$;
        addBro(p1, $2);
    }
    | '!' expression {
        TreeNode *p1 = terminal(_NOT, '!', "");
        $$ = nTerminal(Expression, p1);
        p1->parent = $$;
        addBro(p1, $2);
    }
    | TK_ID '(' args ')' {
        TreeNode *p1, *p2, *p4;
        p1 = terminal(_ID, 0, $1);
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        $$ = nTerminal(Expression, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, $3);
        addBro($3, p4);
    }
    | TK_ID '(' ')' {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_ID, 0, $1);
        p2 = terminal(_LP, '(', "");
        p3 = terminal(_RP, ')', "");
        $$ = nTerminal(Expression, p1);
        p1->parent = $$;
        addBro(p1, p2);
        addBro(p2, p3);
    }
    | expression '[' expression ']' {
        TreeNode *p2, *p4;
        p2 = terminal(_LB, '[', "");
        p4 = terminal(_RB, ']', "");
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
        addBro($3, p4);
    }
    | expression '.' TK_ID {
        TreeNode *p2, *p3;
        p2 = terminal(_DOT, '.', "");
        p3 = terminal(_ID, 0, $3);
        $$ = nTerminal(Expression, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, p3);
    }
    | TK_ID {
        TreeNode *p1;
        p1 = terminal(_ID, 0, $1);
        $$ = nTerminal(Expression, p1);
        p1->parent = $$;
    }
    | TK_CINT {
        TreeNode *p1;
        p1 = terminal(_INT, $1, "");
        $$ = nTerminal(Expression, p1);
        p1->parent = $$;
    }
    | TK_CFLOAT {
        TreeNode *p1;
        p1 = terminal(_FLOAT, $1, "");
        $$ = nTerminal(Expression, p1);
        p1->parent = $$;
    }
    | error ')' {
        setErrType(ERR_TYPE10);
        m_error("missing \"(\"", @1.last_line);
        setErrType(ERR_OTHER);
    }
    | expression '[' error ']' {
        setErrType(ERR_TYPE10);
        m_error("missing \"]\"", @3.last_line);
        setErrType(ERR_OTHER);
    }
    | TK_ID error ')' {
        setErrType(ERR_TYPE10);
        m_error("missing \"(\"", @2.last_line);
        setErrType(ERR_OTHER);
    }
    ;
relation_op:
    '<' {
        $$ = nTerminal(RelOp, terminal(_LT, '<', "<"));
    }
    | '>' {
        $$ = nTerminal(RelOp, terminal(_GT, '>', ">"));
    }
    | TK_LEQ {
        $$ = nTerminal(RelOp, terminal(_LEQ, TK_LEQ, "<="));
    }
    | TK_GEQ {
        $$ = nTerminal(RelOp, terminal(_GEQ, TK_GEQ, ">="));
    }
    | TK_EQ {
        $$ = nTerminal(RelOp, terminal(_EQU, TK_EQ, "=="));
    }
    | TK_NEQ {
        $$ = nTerminal(RelOp, terminal(_NEQ, TK_NEQ, "!="));
    }
    ;
args : 
    expression ',' args {
        TreeNode *p2 = terminal(_COMMA, ',', "");
        $$ = nTerminal(Args, $1);
        $1->parent = $$;
        addBro($1, p2);
        addBro(p2, $3);
    }
    | expression {
        $$ = nTerminal(Args, $1);
        $1->parent = $$;
    }
    | error ',' args {
        setErrType(ERR_TYPE11);
        m_error("something wrong with your expression", @1.last_line);
        setErrType(ERR_OTHER);
    }
    ;

%%
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Invalid input!\n");
        printf("You can input \"-h\" or \"-help\" for help\n");
        return 0;
    }
    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0)
    {
        printf("usage: complier.exe [input_file_name]\n");
        printf("       Output file will be in the same directory. Output files are as follows:\n");
        printf("       1. \"[input_file_name].tree\" for syntax tree;\n");
        printf("       2. \"[input_file_name].ir\" for IR;\n");
        printf("       3. \"[input_file_name].asm\" for MIPS instructions.\n");
        return 0; 
    }
    if((yyin = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        return 0;
    }
    char treeFileName[100], irFileName[100], targetFileName[100];
    setFileName(treeFileName, argv[1], ".tree");
    setFileName(irFileName, argv[1], ".ir");
    setFileName(targetFileName, argv[1], ".asm");
    treeFile = fopen(treeFileName, "w");
    //yydebug = 1;
    yyparse();
    fclose(yyin);
    initTable();
    semantics(syntaxTree);
    printTree(syntaxTree, 0);
    fclose(treeFile);
    if(errorOccured == FALSE)
    {
        translate(syntaxTree);
        //printf("^^^^^^^^^^^^^^^^\n");
        printCode(irFileName);
        targetFile = fopen(targetFileName, "w");
        targetCode(irHead);
        fclose(targetFile);
    }
    destroyTable();
    return 0;
}

void yyerror(char *msg)
{
    if(et != ERR_OTHER)
        strcpy(message, msg + 13);
    else
        printf("%s at line %d.\n", msg, yylineno);
}

void m_error(char *msg, int lineno)
{
    printf("Error type %d at Line %d: %s, maybe %s.\n", et, lineno, message, msg);
}

void setErrType(ErrorType errType)
{
    et = errType;
}

void setFileName(char *tarName, char *srcName, char *postfix)
{
    if(srcName == NULL)
        return;
    int len = strlen(srcName), pos = -1;
    for(int i = len - 1; i >= 0; i--)
    {
        if(srcName[i] == '.')
        {
            pos = i;
            break;
        }
    }
    if(pos != -1)
    {
        int i;
        for(i = 0; i < pos; i++)
            tarName[i] = srcName[i];
        tarName[i] = '\0';
    }
    else
        strcpy(tarName, srcName);
    strcat(tarName, postfix);
}