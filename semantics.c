#include "compiler.h"

static ValKind kind = TP_INT;  // 当前处理类型
static Symbol symbol = NULL;
static Symbol lastSym = NULL;
int level = 0;
static BOOL structing = FALSE;
static BOOL functing = FALSE;
static BOOL returning = FALSE;
static Function *curFunc = NULL;
BOOL errorOccured = FALSE;

void semantics(TreeNode *p)
{
	if(p == NULL)
		return;
	//printf("begin semantics.\n");
	switch(p->nType)
	{
		case Specifier:
		{
			//printf("Specifier\n");
			// 获取当前处理的符号类型
			if(p->child->nType == _TYPE)
			{
				if(p->child->child->nType == _INT)
					kind = TP_INT;
				else
					kind = TP_FLOAT;
			}
			else
			{
				kind = TP_STRUCT;
				semantics(p->child);
			}
			break;
		}
		case StructSpecifier:
		{
			//printf("StructSpecifier\n");
			if(p->childNum == 2)
			{
				// 使用已经定义的结构体
				symbol = findSymbol(p->child->bro->name, curFunc);
				if(symbol == NULL)
				{
					errorOccured = TRUE;
					setErrType(ERR_TYPE12);
					printf("Error type 17 at line %d: undefined structure \"%s\".\n", p->line, p->child->bro->name);
				}
			}
			else
			{
				// 定义结构体
				char name[30];
				if(p->child->bro->nType == None)
					getAnonymous(name);
				else
					strcpy(name, p->child->bro->child->name);
				symbol = findSymbol(name, curFunc);
				if(symbol != NULL)
				{
					errorOccured = TRUE;
					setErrType(ERR_TYPE13);
					printf("Error Type 16 at line %d: redefined structure \"%s\".\n", p->line, name);
				}
				else
				{
					Symbol s = createSymbol(name, level, p->line);
					setType(&(s->type), TP_STRUCT);
					if(enterTable(s) != TRUE)
						return;
					symbol = s;
					structing = TRUE;
					semantics(p->child->bro->bro->bro);
					structing = FALSE;
				}
			}
			break;
		}
		case CompSt:
		{
			//printf("CompSt\n");
			level++;
			semantics(p->child->bro);
			semantics(p->child->bro->bro);
			level--;
			break;
		}
		case ExtDef:
		{
			//printf("ExtDef\n");
			// 外部定义，根据第二个子节点是ExtDecList，SEMI还是FuncDec
			// 来确定是定义全局变量还是函数的定义并做不同的处理
			if(p->child->bro->nType == FuncDec)
			{
				semantics(p->child);
				Symbol s = findSymbol(p->child->bro->child->name, curFunc);
				if(s != NULL)
				{
					errorOccured = TRUE;
					setErrType(ERR_TYPE14);
					printf("Error type 4 at Line %d: function \"%s\" is redefined.\n", p->line, p->child->bro->child->name);
				}
				else
				{
					s = createSymbol(p->child->bro->child->name, level, p->line);
					setType(&(s->type), TP_FUNC);
					setFuncRet(s->type->func, kind);
					s->type->func->paramNum = 0;
					s->type->func->params = NULL;
					enterTable(s);
					curFunc = s->type->func;
					if(p->child->bro->childNum == 4)
					{
						functing = TRUE;
						semantics(p->child->bro->child->bro->bro);
						functing = FALSE;
					}
					semantics(p->child->bro->bro);
				}
			}
			else
			{
				for(TreeNode *temp = p->child; temp; temp = temp->bro)
					semantics(temp);
			}
			break;
		}
		case VarDec:
		{
			//printf("VarDec\n");
			Array *a = NULL;
			if(p->childNum != 1)
				a = NEW_ARRAY;
			TreeNode *temp = p;
			while(temp->childNum != 1)
			{
				if(temp->child->childNum == 1)
					setArray(&a, (int)temp->child->bro->bro->value, kind);
				else
				{
					setArray(&a, (int)temp->child->bro->bro->value, TP_ARRAY);
					a = a->elemType->array;
				}
				temp = temp->child;
			}
			temp = temp->child;
			if(structing)
			{
				Type* fType = findFieldType(symbol->type->structure, temp->name);
				if(fType == NULL)
				{
					if(a == NULL)
						setField(&symbol->type->structure, temp->name, kind);
					else
					{
						setField(&symbol->type->structure, temp->name, TP_ARRAY);
						setFieldTypeArray(&symbol->type->structure, temp->name, a);
					}
				}
				else
				{
					errorOccured = TRUE;
					setErrType(ERR_TYPE15);
					printf("Error type 15 at Line %d: Redefined field \"%s\".\n", p->line, temp->name);
				}
			}
			else if(functing)
			{
				Type* fType = findFieldType(curFunc->params, temp->name);
				if(fType == NULL)
				{
					if(a == NULL)
						setField(&curFunc->params, temp->name, kind);
					else
					{
						setField(&curFunc->params, temp->name, TP_ARRAY);
						setFieldTypeArray(&curFunc->params, temp->name, a);
					}
					curFunc->paramNum++;
				}
				else
				{
					errorOccured = TRUE;
					setErrType(ERR_TYPE15);
					printf("Error type 18 at Line %d: Redefined param \"%s\".\n", p->line, temp->name);
				}
			}
			else
			{
				symbol = findSymbol(temp->name, curFunc);
				if(symbol == NULL || (symbol != NULL && symbol->level != level))
				{
					Symbol s = createSymbol(temp->name, level, p->line);
					if(a == NULL)
						setType(&(s->type), kind);
					else
					{
						setType(&(s->type), TP_ARRAY);
						s->type->array = a;
					}
					if(!enterTable(s))
						return;
					symbol = s;
					lastSym = symbol;
				}
				else
				{
					errorOccured = TRUE;
					setErrType(ERR_TYPE16);
					printf("Error type 3 at Line %d: variable \"%s\" is redefined.\n", p->line, temp->name);
				}
			}
			break;
		}
		case Statement:
		{
			//printf("Statement\n");
			// 根据第一个子节点判断处理方式
			switch(p->child->nType)
			{
				case Expression:
				{
					//printf("Expression\n");
					Type *temp;
					analyseExp(&temp, p->child);
					break;
				}
				case CompSt:
				{
					semantics(p->child);
					break;
				}
				case _RETURN:
				{
					Type *temp;
					returning = TRUE;
					analyseExp(&temp, p->child->bro);
					returning = FALSE;
					if(isTypeEqual(temp, curFunc->retType) == FALSE)
					{
						errorOccured = TRUE;
						printf("Error type 8 at Line %d: Type mismatched for return.\n", p->line);
					}
					break;
				}
				default:
				{
					// if 语句
					Type *temp;
					analyseExp(&temp, p->child->bro->bro);
					if(temp == NULL)
						return;
					if(temp->kind != TP_INT)
					{
						errorOccured = TRUE;
						printf("Error type 19 at Line %d: only INT can be used as boolean.\n", p->line);
						return;
					}
					if(p->childNum == 5)
						semantics(p->child->bro->bro->bro->bro);
					else
					{
						semantics(p->child->bro->bro->bro->bro);
						semantics(p->child->bro->bro->bro->bro->bro->bro);
					}
				}
			}
			break;
		}
		case Declare:
		{
			//printf("Declare\n");
			semantics(p->child);
			if(p->childNum == 3)
			{
				if(structing)
				{
					errorOccured = TRUE;
					printf("Error type 20 at Line %d: can't initialize a field while defining the struct.\n", p->line);
				}
				else
				{
					Type *temp;
					analyseExp(&temp, p->child->bro->bro);
					if(isTypeEqual(lastSym->type, temp) == FALSE)
					{
						errorOccured = TRUE;
						printf("Error type 5 at Line %d: incompatible type near \"=\".\n", p->line);
					}
				}
			}
			break;
		}
		default:
		{
			//printf("%s\n", typeNameTable[p->nType]);
			for(TreeNode *temp = p->child; temp; temp = temp->bro)
				semantics(temp);
		}
	}
}

void analyseExp(Type **expType, TreeNode *p)
{
	if(p->childNum == 1)
	{
		/**
		 * ID
		 * INT
		 * FLOAT
		 */
		switch(p->child->nType)
		{
			case _ID:
			{
				if(returning)
				{
					Type *temp = findFieldType(curFunc->params, p->child->name);
					if(temp != NULL)
					{	
						*expType = temp;
						return;
					}
				}
				symbol = findSymbol(p->child->name, curFunc);
				if(symbol == NULL)
				{
					errorOccured = TRUE;
					printf("Error type 1 at line %d: \"%s\" was not declared yet.\n", p->line, p->child->name);
					*expType = NULL;
				}
				else
					*expType = symbol->type;
				break;
			}
			case _INT:
			{
				*expType = NEW_TYPE;
				(*expType)->kind = TP_INT;
				break;
			}
			case _FLOAT:
			{
				*expType = NEW_TYPE;
				(*expType)->kind = TP_FLOAT;
				break;
			}
		}
	}
	else if(p->childNum == 2)
	{
		/**
		 * NOT Exp
		 * MINUS Exp
		 */
		Type *temp;
		analyseExp(&temp, p->child->bro);
		if(p->child->nType == _NOT)
		{
			if(temp->kind != TP_INT)
			{
				errorOccured = TRUE;
				printf("Error type 21 at Line %d: only int can use \"!\"(not).\n", p->line);
			}
			else
				*expType = temp;
		}
		else
		{
			if(temp->kind != TP_INT && temp->kind != TP_FLOAT)
			{
				errorOccured = TRUE;
				printf("Error type 22 at Line %d: only int or float can use \"-\"(minus).\n", p->line);
			}
			else
				*expType = temp;
		}
	}
	else if(p->childNum == 3)
	{
		/**
		 * Exp '=' Exp
		 * Exp AND Exp
		 * Exp OR Exp
		 * Exp [cal] Exp
		 * '(' Exp ')'
		 * ID '(' ')'
		 * Exp DOT ID
		 */
		switch(p->child->bro->nType)
		{
			case Expression:
			{
				analyseExp(expType, p->child->bro);
				break;
			}
			case _LP:
			{
				symbol = findSymbol(p->child->name, curFunc);
				if(symbol == NULL)
				{
					errorOccured = TRUE;
					printf("Error type 11 at Line %d: \"%s\" is not a function.\n", p->line, p->child->name);
					return;
				}
				Function *func = symbol->type->func;
				if(func->paramNum == 0)
					*expType = func->retType;
				else
				{
					errorOccured = TRUE;
					printf("Error type 9 at Line %d: unmatched parameters for function \"%s\".\n", p->line, p->child->name);
				}
				break;
			}
			case _DOT:
			{
				Type *temp;
				analyseExp(&temp, p->child);
				if(temp->kind != TP_STRUCT)
				{
					errorOccured = TRUE;
					printf("Error type 13 at Line %d: use \".\" on none struct variable.\n", p->line);
				}
				else
				{
					Type *fType = findFieldType(temp->structure, p->child->bro->bro->name);
					if(fType == NULL)
					{
						errorOccured = TRUE;
						printf("Error type 14 at Line %d: Non-existent field \"%s\".\n", p->line, p->child->bro->bro->name);
						*expType = NULL;
					}
					else
						*expType = fType;
				}
				break;
			}
			case _AND:
			case _OR:
			{
				Type *temp1, *temp2;
				analyseExp(&temp1, p->child);
				analyseExp(&temp2, p->child->bro->bro);
				if(temp1->kind != _INT || temp2->kind != _INT)
				{
					errorOccured = TRUE;
					printf("Error type 19 at Line %d: only INT can be used as boolean.\n", p->line);
				}
				else
					*expType = temp1;
				break;
			}
			case _ASSIGNOP:
			{
				if(checkLeft(p->child) == FALSE)
				{
					errorOccured = TRUE;
					printf("Error type 6 at Line %d: the left-hand side of \"=\" must have left side value.\n", p->line);
				}
				else
				{
					Type *temp1, *temp2;
					analyseExp(&temp1, p->child);
					if(temp1 == NULL)
						return;	
					analyseExp(&temp2, p->child->bro->bro);
					if(isTypeEqual(temp1, temp2))
						*expType = temp1;
					else
					{
						errorOccured = TRUE;
						printf("Error type 5 at Line %d: both sides of \"=\" must be the same type.\n", p->line);
					}
				}
				break;
			}
			default:
			{
				Type *temp1, *temp2;
				analyseExp(&temp1, p->child);
				if(temp1 == NULL)
				{
					*expType = NULL;
					return;
				}
				analyseExp(&temp2, p->child->bro->bro);
				if(isTypeEqual(temp1, temp2) && (temp1->kind == TP_INT || temp1->kind == TP_FLOAT))
					*expType = temp1;
				else
				{
					errorOccured = TRUE;
					printf("Error type 7 at Line %d: Type mismatched for operands.\n", p->line);
				}
			}
		}
	}
	else if(p->childNum == 4)
	{
		/**
		 * Exp '[' Exp ']'
		 * ID '(' args ')'
		 */
		if(p->child->nType == Expression)
		{
			TreeNode *h = p;
			while(h->childNum == 4 && h->child->nType == Expression)
				h = h->child;
			if(!(h->childNum == 1 && h->child->nType == _ID))
				return;
			symbol = findSymbol(h->child->name, curFunc);
			if(symbol == NULL)
			{
				errorOccured = TRUE;
				printf("Error type 1 at line %d: \"%s\" was not declared yet.\n", h->line, h->child->name);
			}
			else if(symbol->type->kind != TP_ARRAY)
			{
				errorOccured = TRUE;
				printf("Error type 10 at Line %d: \"%s\" is not an array.\n", h->line, namePool.names + symbol->pos);
			}
			else
			{
				h = h->parent;
				Array *a = symbol->type->array;
				while(h != p && a->elemType->kind == TP_ARRAY)
				{
					// 检查[]内数字合法性
					Type *temp;
					analyseExp(&temp, p->child->bro->bro);
					if(temp->kind != TP_INT)
					{
						errorOccured = TRUE;
						printf("Error type 12 at Line %d: the type of exp between \"[]\" should be INT.\n", p->line);
						*expType = NULL;
						return;
					}
					h = h->parent;
					a = a->elemType->array;
				}
				if(a->elemType->kind != TP_ARRAY && h != p)
				{
					errorOccured = TRUE;
					// []过多
					printf("Error type 23 at Line %d: array dimension ERROR.\n", p->line);
					return;
				}
				// 检查第一个[]内数字的合法性
				Type *temp;
				analyseExp(&temp, h->child->bro->bro);
				if(temp->kind != TP_INT)
				{
					errorOccured = TRUE;
					printf("Error type 12 at Line %d: the type of exp between \"[]\" should be INT.\n", h->line);
					*expType = NULL;
					return;
				}
				if(h == p && a->elemType->kind != TP_ARRAY)
				{
					// 刚好对齐，取出基本元素定义
					*expType = a->elemType;					
				}
				else
				{
					errorOccured = TRUE;
					printf("Error type 12 at Line %d: the type of exp between \"[]\" should be INT.\n", h->line);
					return;
				}
			}
		}
		else
		{
			symbol = findSymbol(p->child->name, curFunc);
			if(symbol == NULL)
			{
				errorOccured = TRUE;
				printf("Error type 2 at line %d: FUNCTION \"%s\" was not declared yet.\n", p->line, p->child->name);
			}
			else if(symbol->type->kind != TP_FUNC)
			{
				errorOccured = TRUE;
				printf("Error type 11 at Line %d: \"%s\" is NOT a function.\n", p->line, p->child->name);
			}
			else
			{
				Function *func = symbol->type->func;
				// 计算args的参数数目
				TreeNode *args = p->child->bro->bro;
				int count = 1;
				while(args->childNum == 3)
				{
					count++;
					args = args->child->bro->bro;
				}
				if(count != func->paramNum)
				{
					errorOccured = TRUE;
					printf("Error type 9 at Line %d: unmatched parameters for function \"%s\".\n", p->line, namePool.names + symbol->pos);
					*expType = NULL;
					return;
				}
				// 依次检查各个参数
				FieldList *params = func->params;
				for(int i = 0; i < count; i++)
				{
					args = p->child->bro->bro;
					Type *temp;
					analyseExp(&temp, args->child);
					if(isTypeEqual(temp, params->fieldType) == FALSE)
					{
						errorOccured = TRUE;
						printf("Error type 9 at Line %d: unmatched parameters for function \"%s\".\n", p->line, namePool.names + symbol->pos);
						return;
					}
					params = params->next;
				}
				*expType = func->retType;
			}
		}
	}
}

BOOL isTypeEqual(Type *t1, Type *t2)
{
	if(t1 == NULL || t2 == NULL)
		return FALSE;
	if(t1->kind != t2->kind)
		return FALSE;
	switch(t1->kind)
	{
		case TP_ARRAY:
		{
			Array *a1 = t1->array;
			Array *a2 = t2->array;
			if(a1->size != a2->size)
				return FALSE;
			return isTypeEqual(a1->elemType, a2->elemType);
		}
		case TP_STRUCT:
			return t1->structure->pos == t2->structure->pos;
		default:
			return TRUE;
	}
}

BOOL checkLeft(TreeNode *p)
{
	if(p->childNum == 1 && p->child->nType == _ID)
		return TRUE;
	if(p->childNum == 3 && p->child->bro->nType == _DOT)
		return TRUE;
	if(p->childNum == 4 && p->child->bro->nType == _LB)
		return TRUE;
	return FALSE;
}