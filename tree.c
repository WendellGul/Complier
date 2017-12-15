#include "compiler.h"
#include "parser.tab.h"

const char * const typeNameTable[] = 
{
    /*0 Epsilon*/
    "None",
    /*1 Tokens*/
    "SEMI", "COMMA", "ASSIGNOP", "EQU", "NEQ", "LT", "GT", "LEQ", "GEQ", 
    "PLUS", "MINUS", "STAR", "DIV", "MOD", 
    "AND", "OR", "DOT", "NOT", "TYPE",
    "LP", "RP", "LB", "RB", "BEGIN", "END",
    "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", 
    "ID", "INT", "FLOAT",
    /*2 High-level Definitions*/
    "Program", "ExtDefList", "ExtDef", "ExtDecList",
    /*3 Specifiers*/
    "Specifier", "StructSpecifier", "OptTag", "Tag",
    /*4 Declarators*/
    "VarDec", "FuncDec", "ParamList", "ParamDec",
    /*5 Statements*/
    "CompSt", "StmtList", "Statement",
    /*6 Local Definitions*/
    "DefList", "Define", "DecList", "Declare",
    /*7 Expressions*/
    "Expression", "ExpPart", "Operand", "Operator", "RelOp", "Args"
};

/**
 * create a non-terminal node
 * @param  nType  node type
 * @param  child child node
 * @return       the node pointer if success, else return NULL
 */
TreeNode* nTerminal(NodeType nType, TreeNode *child)
{
    TreeNode *p;
    if((p = (TreeNode *)malloc(sizeof(TreeNode))) == NULL)
        return NULL;
    p->isTerminal = FALSE;
    p->nType = nType;
    p->line = yylineno;
    p->child = child;
    p->childNum = 1;
    p->bro = NULL;
    p->parent = NULL;
    return p;
}

/**
 * create a terminal node
 * @param  nType    node type
 * @param  value   the int or float value of the node
 * @param  name the name of the ID
 * @return         the node pointer if success, else return NULL
 */
TreeNode* terminal(NodeType nType, float value, char *name)
{
    TreeNode *p;
    if((p = (TreeNode *)malloc(sizeof(TreeNode))) == NULL)
        return NULL;
    p->isTerminal = TRUE;
    p->nType = nType;
    p->value = value;
    p->line = yylineno;
    strcpy(p->name, name);
    p->child = NULL;
    p->bro = NULL;
    p->parent = NULL;
    p->childNum = 0;
    return p;
}

void addBro(TreeNode *p, TreeNode *bro)
{
    p->bro = bro;
    p->parent->childNum++;
    bro->parent = p->parent;
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

void printTree(TreeNode *p, int tab)
{
    if(p == NULL)
        return ;
    TreeNode *pChild, *pBro;
    printNode(p, tab);
    pChild = p->child;
    printTree(pChild, tab + 1);
    if(pChild != NULL)
        for(pBro = pChild->bro; pBro != NULL; pBro = pBro->bro)
            printTree(pBro, tab + 1);
}

void printNode(TreeNode *p, int tab)
{
    int i = 0;
    if(p->isTerminal == TRUE)
    {
        while(tab != 0 && i++ < TABNUM * (tab - 1))
            fprintf(treeFile, " ");
        if(tab != 0)
            fprintf(treeFile, "|__");
        switch(p->nType)
        {
            case _INT:
                fprintf(treeFile, "INT: %d line: %d\n", (int)p->value, p->line);
            break;
            case _FLOAT:
                fprintf(treeFile, "FLOAT: %d line: %d\n", (float)p->value, p->line);
            break;
            case _ID:
                fprintf(treeFile, "ID: %s line: %d\n", p->name, p->line);
            break;
            default:
                fprintf(treeFile, "%s\n", typeNameTable[p->nType]);
        }
    }
    else
    {
        if(p->nType != None)
        {
            while(tab != 0 && i++ < TABNUM * (tab - 1))
                fprintf(treeFile, " ");
            if(tab != 0)
                fprintf(treeFile, "|__");
            fprintf(treeFile, "%s\n", typeNameTable[p->nType]);
        }
    }
}
