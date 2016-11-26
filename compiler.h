/************************global*************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

typedef int BOOL;

#define TRUE    1
#define FALSE   0
/************************global*************************/

/***********************tree.c************************/
#define TABNUM 3

extern const char * const typeNameTable[];
extern FILE *treeFile;

typedef enum {
    /*0 Epsilon*/
    None,
    /*1 Tokens*/
    _SEMI, _COMMA, _ASSIGNOP, _EQU, _NEQ, _LT, _GT, _LEQ, _GEQ, 
    _PLUS, _MINUS, _STAR, _DIV, _MOD,
    _AND, _OR, _DOT, _NOT, _TYPE,
    _LP, _RP, _LB, _RB, _BEGIN, _END,
    _STRUCT, _RETURN, _IF, _ELSE, _WHILE, _BREAK, _CONTINUE, 
    _ID, _INT, _FLOAT,
    /*2 High-level Definitions*/
    Program, ExtDefList, ExtDef, ExtDecList,
    /*3 Specifiers*/
    Specifier, StructSpecifier, OptTag, Tag,
    /*4 Declarators*/
    VarDec, FuncDec, ParamList, ParamDec,
    /*5 Statements*/
    CompSt, StmtList, Statement,
    /*6 Local Definitions*/
    DefList, Define, DecList, Declare,
    /*7 Expressions*/
    Expression, ExpPart, Operand, Operator, RelOp, Args
} NodeType;

typedef struct treeNode {
    BOOL isTerminal;
    int line;  // line number
    int level;
    NodeType nType;
    char name[30];
    float value;
    int childNum;
    struct treeNode *child;
    struct treeNode *bro;
    struct treeNode *parent;
} TreeNode;

TreeNode* nTerminal(NodeType nType, TreeNode *child);
TreeNode* terminal(NodeType nType, float value, char *name);
void addBro(TreeNode *p, TreeNode *bro);
void printTree(TreeNode *p, int tab);
void printNode(TreeNode *p, int tab);
void freeNode(TreeNode *p);

extern TreeNode *syntaxTree;
extern FILE *yyin, *yyout;
extern int yylineno;

/***********************tree.c************************/

/**********************symbol.c**********************/
typedef struct _Symbol* Symbol;
typedef struct Type Type;
typedef struct Function Function;
typedef struct Array Array;
typedef struct FieldList FieldList;
typedef struct NamePool NamePool;
typedef FieldList Structure;

#define MAX_SIZE    0x3fff
#define POOL_SIZE   1024
#define NEW_SYMBOL  ((Symbol)malloc(sizeof(struct _Symbol)))
#define NEW_ARRAY   ((Array *)malloc(sizeof(Array)))
#define NEW_STRUCT  ((FieldList *)malloc(sizeof(FieldList)))
#define NEW_FUNC    ((Function *)malloc(sizeof(Function)))
#define NEW_TYPE    ((Type *)malloc(sizeof(Type)))
#define NEW_FIELD   NEW_STRUCT

#define getSymbolName(s)  namePool.names + ((s)->pos)    

extern Symbol table[MAX_SIZE];
extern NamePool namePool; 

// 关键字池
struct NamePool {
    char names[POOL_SIZE];
    int curPos;
};

// 类型
typedef enum ValKind {
    TP_INT, TP_FLOAT, TP_ARRAY, TP_STRUCT, TP_FUNC
} ValKind;

// 函数类型符号表
struct Function {
    Type *retType;  // 返回值类型
    int paramNum;  // 参数个数
    FieldList *params;  // 参数域
};

// 数组类型符号表
struct Array {
    Type *elemType;  // 元素类型
    int size;  // 数组大小
};

// 符号域（函数参数域或结构成员域）
struct FieldList {
    int pos;  // 符号名在关键字池中的位置
    Type *fieldType;
    FieldList *next;
};

// 符号类型
struct Type {
    ValKind kind;
    union {
        Array *array;
        Structure *structure;  // 结构体头结点保存结构名
        Function *func;
    };
};

// 符号
struct _Symbol {
    int pos;  // 符号名在关键字池中的位置
    int line;  // 符号所在行号
    Type *type;  // 符号类型
    int level;  // 符号作用域
    int option; // 其他属性
    Symbol next;  // 同名符号下推链
};

// 符号表其他属性
enum OPTION {
    OPTION_NONE       = 0x00ff,
    IS_STRUCT_DECLARE = 0x01ff,
};

unsigned int hash_pjw(const char *name);
void initTable();
Symbol createSymbol(const char *name, int level, int line);
void setType(Type **t, ValKind kind);
void setArray(Array **a, int size, ValKind kind);
void setField(FieldList **field, char *name, ValKind kind);
BOOL setFieldTypeArray(FieldList **field, char *name, Array *a);
void setFuncRet(Function *func, ValKind retType);
BOOL enterTable(Symbol symbol);
Symbol findSymbol(const char *name, Function *curFunc);
Type* findFieldType(FieldList *field, const char *name);
void getAnonymous(char *name);
void m_itoa(int n, char *s);
void destroyTable();
void freeType(Type *type);
void freeField(FieldList *f);

extern int level;
/**********************symbol.c**********************/

/********************semantics.c*********************/
extern BOOL errorOccured;

void semantics(TreeNode *p);
void analyseExp(Type **expType, TreeNode *p);
BOOL isTypeEqual(Type *t1, Type *t2);
BOOL checkLeft(TreeNode *p);
/********************semantics.c*********************/

/***********************ir.c************************/
/**
 * 中间代码的形式
 * args_count=2:
 *     GOTO x
 *     RETURN x
 *     ARG x
 *     PARAM x
 *     READ x
 *     WRITE x
 * args_count=3:
 *     LABEL x :
 *     FUNCTION f :
 *     x := y
 *     x := &y
 *     x := *y
 *     *x := y
 *     DEC x [size]
 * args_count=4:
 *     x := CALL f
 * args_count=5:
 *     x := y + z
 *     x := y - z
 *     x := y * z
 *     x := y / z
 * args_count=6:
 *     IF x [relop] y GOTO z
 */
// 中间代码结点
typedef struct InterCode
{
    int argsCount;
    char args[6][30];
    struct InterCode *prev;  // 前一个
    struct InterCode *next;  // 后一个
} InterCode;

#define NEW_CODE        ((InterCode *)malloc(sizeof(InterCode)))
#define SIZE_OF_EACH    4


// 生成新的LABEL
void newLabel(char *name);
// 生成新的临时变量
void newTemp(char *name);
// 添加一条中间代码
void addCode(int argsCount, ...);
// 打印中间代码到文件中
void printCode(char *fileName);
// 删除一个中间代码结点
void deleteCodeNode(InterCode *p);
// 将语法树翻译成中间代码
void translate(TreeNode *p);
// 将一行中间代码打印到文件中
void printOneLine(FILE *fp, InterCode *p);
// 获取某类型的内存空间大小
int getTypeSize(Type *type);
// 将表达式语句翻译成中间代码
void translateExp(TreeNode *p, char *place, int option);
// 将函数参数翻译成中间代码
void translateArgs(TreeNode *p, FieldList *f);
// 将条件语句翻译成中间代码
void translateCond(TreeNode *p, char *labelT, char *labelF);
// 
void getAddress(TreeNode *p, char *place);
//
int getStructOffset(Structure *struc, char *fieldName);
/***********************ir.c************************/

/***********************target.c************************/
typedef struct VarOffsetTable 
{
    char name[30];
    int offset;
} VOT;
extern FILE *targetFile;
extern InterCode *irHead;
void targetCode(InterCode *h);
void generateFunc(InterCode *begin, InterCode *end);
int getVarOffset(char *name);
void addVar(char *name, int size);
void allocReg(char *name, int no);
/***********************tarhet.c************************/

/**********************Error Type***********************/
typedef enum ErrorType {
    ERR_OTHER,
    ERR_REDEFINE,
    ERR_FULL_SYMBOL,
    ERR_TYPE1,
    ERR_TYPE2,
    ERR_TYPE3,
    ERR_TYPE4,
    ERR_TYPE5,
    ERR_TYPE6,
    ERR_TYPE7,
    ERR_TYPE8,
    ERR_TYPE9,
    ERR_TYPE10,
    ERR_TYPE11,
    ERR_TYPE12,
    ERR_TYPE13,
    ERR_TYPE14,
    ERR_TYPE15,
    ERR_TYPE16,
    ERR_TYPE17,
    ERR_TYPE18,
    ERR_TYPE19,
    ERR_TYPE20
} ErrorType;

extern ErrorType et;

void m_error(char *msg, int lineno);
void setErrType(ErrorType errType);
/**********************Error Type***********************/