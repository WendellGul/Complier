#include "compiler.h"

// temp和label计数器，用于生成新的temp和label
static int tempCount = 0, labelCount = 0;

// 中间代码的头结点
InterCode * irHead = NULL;

static int curSize = 0;

static Function *curFunc = NULL;
static Structure *curStruct = NULL;

// 用于保存curStruct和curSize
static Structure *__curStruct = NULL;
static int __curSize = 0;

void save()
{
	__curStruct = curStruct;
	__curSize = curSize;
}

void load()
{
	curStruct = __curStruct;
	curSize = __curSize;
}

void deleteCodeNode(InterCode *p)
{
	if(p->next == p)
	{
		free(p);
		p = NULL;
		 irHead = NULL;
	}
	else
	{
		InterCode *temp = p;
		p = p->prev;
		p->next = temp->next;
		p->next->prev = p;
		free(temp);
	}
}

/**
 * 生成新的Label，名称放在name
 * @param name 存放label名
 */
void newLabel(char *name)
{
	strcpy(name, "label");
	char temp[20];
	itoa(labelCount, temp, 10);
	labelCount++;
	strcat(name, temp);
}

/**
 * 生成新的临时变量，存在name中
 * @param name 存放临时变量名
 */
void newTemp(char *name)
{
	strcpy(name, "_t");
	char temp[20];
	itoa(tempCount, temp, 10);
	tempCount++;
	strcat(name, temp);
}

/**
 * 添加一条代码
 */
void addCode(int argsCount, ...)
{
	InterCode *p = NEW_CODE;
	p->argsCount = argsCount;
	va_list ap;
	va_start(ap, argsCount);
	for(int i = 0; i < argsCount; i++)
		strcpy(p->args[i], va_arg(ap, char *));
	if( irHead == NULL)
	{
		p->prev = p;
		p->next = p;
		 irHead = p;
	}
	else
	{
		 irHead->prev->next = p;
		p->prev =  irHead->prev;
		 irHead->prev = p;
		p->next =  irHead;
	}
}

/**
 * 将中间代码打印到文件中
 * @param fileName file name
 */
void printCode(char *fileName)
{
	if( irHead == NULL)
		return;
	FILE *fp = fopen(fileName, "w");
	assert(fp != NULL);
	InterCode *p =  irHead;
	do
	{
		for(int i = 0; i < p->argsCount; i++)
			fprintf(fp, "%s ", p->args[i]);
		fprintf(fp, "\n");
		p = p->next;
	} while(p !=  irHead);
	fclose(fp);
}

void translate(TreeNode *p)
{
	//printf("begin translate\n");
	if(p == NULL)
		return;
	switch(p->nType)
	{
		case Specifier:
			//printf("Specifier\n");
			return;
		case FuncDec:
		{
			//printf("FuncDec\n");
			Symbol s = findSymbol(p->child->name, curFunc);
			curFunc = s->type->func;
			addCode(3, "FUNCTION", p->child->name, ":");
			FieldList *params = curFunc->params;
			for(int i = 0; i < curFunc->paramNum; i++)
			{
				addCode(2, "PARAM", namePool.names + params->pos);
				params = params->next;
			}
			break;
		}
		case Declare:
		{
			//printf("Declare\n");
			TreeNode *temp = p->child->child;
			if(temp->nType != _ID)
			{
				temp = temp->child;
				if(p->nType != _ID)
				{
					printf("Cannot translate: Code contains variables of multi-dimensional \
					array type or parameters of array type.\n");
					exit(0);
				}
			}
			Symbol s = findSymbol(temp->name, curFunc);
			if(s->type->kind == TP_ARRAY || s->type->kind == TP_STRUCT)
			{
				char size[8];
				itoa(getTypeSize(s->type), size, 10);
				addCode(3, "DEC", getSymbolName(s), size);
			}
			if(p->childNum == 3)
			{
				translateExp(p->child->bro->bro, getSymbolName(s), 1);
			}
			break;
		}
		case Statement:
		{
			//printf("Statement\n");
			// 根据第一个子结点分别处理
			switch(p->child->nType)
			{
				case Expression:
				{
					//printf("Expression\n");
					translateExp(p->child, NULL, 0);
					break;
				}
				case CompSt:
				{
					//printf("CompSt\n");
					translate(p->child);
					break;
				}
				case _RETURN:
				{
					//printf("_RETURN\n");
					char temp[30];
					translateExp(p->child->bro, temp, 0);
					addCode(2, "RETURN", temp);
					break;
				}
				case _IF:
				{
					//printf("_IF\n");
					char label1[30], label2[30], label3[30];
					newLabel(label1);
					newLabel(label2);
					if(p->childNum == 7)
						newLabel(label3);
					translateCond(p->child->bro->bro, label1, label2);
					addCode(3, "LABEL", label1, ":");
					translate(p->child->bro->bro->bro->bro);
					if(p->childNum == 7)
						addCode(2, "GOTO", label3, ":");
					addCode(3, "LABEL", label2, ":");
					if(p->childNum == 7)
					{
						translate(p->child->bro->bro->bro->bro->bro->bro);
						addCode(3, "LABEL", label3, ":");
					}
					break;
				}
				case _WHILE:
				{
					//printf("_WHILE\n");
					char label1[30], label2[30], label3[30];
					newLabel(label1);
					newLabel(label2);
					newLabel(label3);
					addCode(3, "LABEL", label1, ":");
					translateCond(p->child->bro->bro, label2, label3);
					addCode(3, "LABEL", label2, ":");
					translate(p->child->bro->bro->bro->bro);
					addCode(2, "GOTO", label1);
					addCode(3, "LABEL", label3, ":");
					break;
				}
			}
			break;
		}
		default:
		{
			//printf("%s\n", typeNameTable[p->nType]);
			for(TreeNode *temp = p->child; temp; temp = temp->bro)
				translate(temp);
		}
	}
}

void translateExp(TreeNode *p, char *place, int option)
{
	if(p->child->nType == _LP)
		translateExp(p->child->bro, place, option);
	else if(p->childNum == 3 && p->child->bro->nType == _ASSIGNOP)
	{
		// exp '=' exp
		char temp[30];
		translateExp(p->child, temp, 0);
		translateExp(p->child->bro->bro, temp, 1);
		if(place != NULL)
		{
			if(option == 0)
				strcpy(place, temp);
			else
				addCode(3, place, ":=", temp);
		}
	}
	else if(p->childNum == 3 && p->child->bro->nType == _LP)
	{
		// ID '(' ')'
		if(place == NULL)
		{
			if(strcmp(p->child->name, "read") == 0)
				return;
			char temp[30];
			newTemp(temp);
			addCode(4, temp, ":=", "CALL", p->child->name);
		}
		else
		{
			if(option == 0)
				newTemp(place);
			if(strcmp(p->child->name, "read") == 0)
				addCode(2, "READ", place);
			else
				addCode(4, place, ":=", "CALL", p->child->name);
		}
	}
	else if(p->childNum == 4 && p->child->bro->nType == _LP)
	{
		// ID '(' args ')'
		if(place == NULL)
		{
			if(strcmp(p->child->name, "write") == 0)
			{
				char temp[30];
				translateExp(p->child->bro->bro->child, temp, 0);
				addCode(2, "WRITE", temp);
			}
			else
			{
				Symbol s = findSymbol(p->child->name, curFunc);
				translateArgs(p->child->bro->bro, s->type->func->params);
				char temp[30];
				newTemp(temp);
				addCode(4, temp, ":=", "CALL", p->child->name);
			}
		}
		else
		{
			if(strcmp(p->child->name, "write") == 0)
			{
				char temp[30];
				translateExp(p->child->bro->bro->child, temp, 0);
				addCode(2, "WRITE", temp);
				if(option == 0)
				{
					place[0] = '#';
					place[1] = '0';
					place[2] = '\0';
				}
				else
				{
					addCode(3, place, ":=", "#0");
				}
			}
			else
			{
				Symbol s = findSymbol(p->child->name, curFunc);
				translateArgs(p->child->bro->bro, s->type->func->params);
				if(option == 0)
					newTemp(place);
				addCode(4, place, ":=", "CALL", p->child->name);
			}
		}
	}
	if(place == NULL)
		return;
	if(p->child->nType == _INT)
	{
		// INT
		if(option == 0)
			sprintf(place, "#%d", (int)p->child->value);
		else
		{
			char temp[30];
			sprintf(temp, "#%d", (int)p->child->value);
			addCode(3, place, ":=", temp);
		}
	}
	else if(p->child->nType == _ID && p->childNum == 1)
	{
		// ID
		if(option == 0)
			strcpy(place, p->child->name);
		else
			addCode(3, place, ":=", p->child->name);
	}
	else if(p->childNum == 3 && (p->child->bro->nType == _PLUS
		|| p->child->bro->nType == _MINUS
		|| p->child->bro->nType == _STAR
		|| p->child->bro->nType == _DIV))
	{
		char temp1[30], temp2[30];
		translateExp(p->child, temp1, 0);
		if((temp1[0] == '#' && temp1[1] == '0') && (p->child->bro->nType == _STAR || p->child->bro->nType ==_DIV))
		{
			if(option == 0)
			{
				place[0]='#';
				place[1]='0';
				place[2]='\0';
			}
			else
				addCode(3, place, ":=", "#0");
		}
		translateExp(p->child->bro->bro, temp2, 0);
		if((temp2[0] == '#' && temp2[1] == '0') && (p->child->bro->nType == _STAR || p->child->bro->nType ==_DIV))
		{
			if(option == 0)
			{
				place[0]='#';
				place[1]='0';
				place[2]='\0';
			}
			else
				addCode(3, place, ":=", "#0");
		}
		else if(temp1[0] == '#' && temp2[0] == '#')
		{
			int i1 = atoi(&temp1[1]);
			int i2 = atoi(&temp2[1]);
			if(p->child->bro->nType == _PLUS)
			{
				if(option == 0)
					sprintf(place, "#%d", i1 + i2);
				else
				{
					char temp[30];
					sprintf(temp, "#%d", i1 + i2);
					addCode(3, place, ":=", temp);
				}
			}
			else if(p->child->bro->nType == _MINUS)
			{
				if(option == 0)
					sprintf(place, "#%d", i1 - i2);
				else
				{
					char temp[30];
					sprintf(temp, "#%d", i1 - i2);
					addCode(3, place, ":=", temp);
				}
			}
			else if(p->child->bro->nType == _STAR)
			{
				if(option == 0)
					sprintf(place, "#%d", i1 * i2);
				else
				{
					char temp[30];
					sprintf(temp, "#%d", i1 * i2);
					addCode(3, place, ":=", temp);
				}
			}
			else
			{
				if(option == 0)
					sprintf(place, "#%d", i1 / i2);
				else
				{
					char temp[30];
					sprintf(temp, "#%d", i1 / i2);
					addCode(3, place, ":=", temp);
				}
			}
		}
		else if(temp2[0] == '#' && temp2[1] == '0')
		{
			if(option == 0)
				strcpy(place, temp1);
			else
				addCode(3, place, ":=", temp1);
		}
		else if(temp1[0] == '#' && temp1[1] == '0' && p->child->bro->nType == _PLUS)
		{
			if(option == 0)
				strcpy(place, temp2);
			else
				addCode(3, place, ":=", temp2);
		}
		else
		{
			char op[2];
			op[1] = '\0';
			switch(p->child->bro->nType)
			{
				case _PLUS:  op[0] = '+'; break;
				case _MINUS: op[0] = '-'; break;
				case _STAR:  op[0] = '*'; break;
				default: op[0] = '/';
			}
			if(option == 0)
				newTemp(place);
			addCode(5, place, ":=", temp1, op, temp2);
		}
	}
	else if(p->child->nType == _MINUS)
	{
		// '-' exp
		char temp[30];
		translateExp(p->child->bro, temp, 0);
		if(temp[0] == '#')
		{
			int i = atoi(&temp[1]);
			if(option == 0)
				sprintf(place, "#%d", -i);
			else
			{
				char temp[30];
				sprintf(temp, "#%d", -i);
				addCode(3, place, ":=", temp);
			}
		}
		else
		{
			if(option == 0)
				newTemp(place);
			addCode(5, place, ":=", "#0", "-", temp);
		}
	}
	else if(p->child->nType == _NOT ||
		p->child->bro->nType == RelOp ||
		p->child->bro->nType == _AND ||
		p->child->bro->nType == _OR)
	{
		// '!' exp
		// exp RelOp exp
		// exp AND exp
		// exp OR exp
		char label1[30], label2[30];
		newLabel(label1);
		newLabel(label2);
		if(option == 0)
			newTemp(place);
		addCode(3, place, ":=", "#0");
		translateCond(p, label1, label2);
		addCode(3, "LABEL", label1, ":");
		addCode(3, place, ":=", "#1");
		addCode(3, "LABEL", label2, ":");
	}
	else if(p->childNum == 4 && p->child->bro->nType == _LB)
	{
		// ID '[' exp ']'
		char temp1[30], temp2[30];
		getAddress(p->child, temp1);
		translateExp(p->child->bro->bro, temp2, 0);
		if(temp2[0] == '#' && temp2[1] == '0')
		{
			char temp[30];
			if(temp1[0] == '&')
				strcpy(temp, &temp1[1]);
			else
				sprintf(temp, "*%s", temp1);
			if(option == 0)
				strcpy(place, temp);
			else
				addCode(3, place, ":=", temp);
		}
		else if(temp2[0] == '#')
		{
			int i = atoi(&temp2[1]);
			char temp[30], tempI[30];
			sprintf(tempI, "#%d", i * curSize);
			newTemp(temp);
			addCode(5, temp, ":=", temp1, "+", tempI);
			char result[30];
			sprintf(result, "*%s", temp);
			if(option == 0)
				strcpy(place, result);
			else
				addCode(3, place, ":=", result);
		}
		else
		{
			char temp[30], tempI[30], result[30], num[30];
			sprintf(num, "#%d", curSize);
			newTemp(temp);
			newTemp(tempI);
			addCode(5, tempI, ":=", temp2, "*", num);
			addCode(5, temp, ":=", temp1, "+", tempI);
			sprintf(result, "*%s", temp);
			if(option == 0)
				strcpy(place, result);
			else
				addCode(3, place, ":=", result);
		}
	}
	else if(p->childNum == 3 && p->child->bro->nType == _DOT)
	{
		// exp '.' ID
		char left[30], temp[30], result[30];
		getAddress(p->child, left);
		int offsetI = getStructOffset(curStruct, p->child->bro->bro->name);
		char offset[30];
		sprintf(offset, "#%d", offsetI);
		newTemp(temp);
		addCode(5, temp, ":=", left, "+", offset);
		sprintf(result, "*%s", temp);
		if(option == 0)
			strcpy(place, result);
		else
			addCode(3, place, ":=", result);
	}
}

void translateCond(TreeNode *p, char *labelT, char *labelF)
{
	if(p->child->nType == _NOT)
	{
		translateCond(p->child->bro, labelF, labelT);
		return;
	}
	if(p->childNum == 3 && p->child->bro->nType == RelOp)
	{
		char temp1[30], temp2[30];
		translateExp(p->child, temp1, 0);
		translateExp(p->child->bro->bro, temp2, 0);
		if(temp1[0] == '#' && temp2[0] == '#')
		{
			int i1 = atoi(&temp1[1]);
			int i2 = atoi(&temp2[1]);
			if(strcmp(p->child->bro->child->name, ">") == 0)
			{
				if(i1 > i2)
					addCode(2, "GOTO", labelT);
				else
					addCode(2, "GOTO", labelF);
			}
			else if(strcmp(p->child->bro->child->name, "<") == 0)
			{
				if(i1 < i2)
					addCode(2, "GOTO", labelT);
				else
					addCode(2, "GOTO", labelF);
			}
			else if(strcmp(p->child->bro->child->name, ">=") == 0)
			{
				if(i1 >= i2)
					addCode(2, "GOTO", labelT);
				else
					addCode(2, "GOTO", labelF);
			}
			else if(strcmp(p->child->bro->child->name, "<=") == 0)
			{
				if(i1 <= i2)
					addCode(2, "GOTO", labelT);
				else
					addCode(2, "GOTO", labelF);
			}
			else if(strcmp(p->child->bro->child->name, "==") == 0)
			{
				if(i1 == i2)
					addCode(2, "GOTO", labelT);
				else
					addCode(2, "GOTO", labelF);
			}
			else if(strcmp(p->child->bro->child->name, "!=") == 0)
			{
				if(i1 != i2)
					addCode(2, "GOTO", labelT);
				else
					addCode(2, "GOTO", labelF);
			}
		}
		else
		{
			addCode(6, "IF", temp1, p->child->bro->child->name, temp2, "GOTO", labelT);
			addCode(2, "GOTO", labelF);
		}
	}
	else if(p->childNum == 3 && p->child->bro->nType == _AND)
	{
		char label[30];
		newLabel(label);
		translateCond(p->child, label, labelF);
		addCode(3, "LABEL", label, ":");
		translateCond(p->child->bro->bro, labelT, labelF);
	}
	else if(p->childNum == 3 && p->child->bro->nType == _OR)
	{
		char label[30];
		newLabel(label);
		translateCond(p->child, labelT, label);
		addCode(3, "LABEL", label, ":");
		translateCond(p->child->bro->bro, labelT, labelF);
	}
	else
	{
		char temp[30];
		translateExp(p, temp, 0);
		if(temp[0] == '#')
		{
			if(temp[1] == '0')
				addCode(2, "GOTO", labelF);
			else
				addCode(2, "GOTO", labelT);
		}
		else
		{
			addCode(6, "IF", temp, "!=", "#0", "GOTO", labelT);
			addCode(2, "GOTO", labelF);
		}
	}
}

void translateArgs(TreeNode* p, FieldList* args)
{
	if(args == NULL)
		return;
	if(p->childNum == 3)
		translateArgs(p->child->bro->bro, args->next);
	if(args->fieldType->kind == TP_INT)
	{
		char temp[30];
		translateExp(p->child, temp, 0);
		addCode(2, "ARG", temp);
	}
	else if(args->fieldType->kind == TP_STRUCT)
	{
		char temp[30];
		getAddress(p->child, temp);
		addCode(2, "ARG", temp);
	}
	else
	{
		printf("can't deal with using array as args.\n");
		exit(0);
	}
}

void getAddress(TreeNode *p, char *place)
{
	if(p->childNum == 1)
	{
		Symbol s = findSymbol(p->child->name, curFunc);
		if(s->type->kind == TP_STRUCT)
			curStruct = s->type->structure;
		else
			curSize = SIZE_OF_EACH;
		sprintf(place, "&%s", p->child->name);
	}
	else if(p->childNum == 4 && p->child->bro->nType == _LB)
	{
		char temp1[30], temp2[30];
		getAddress(p->child, temp1);
		save();
		translateExp(p->child->bro->bro, temp2, 0);
		load();
		if(temp2[0] == '#' && temp2[1] == '0')
			strcpy(place, temp1);
		else if(temp2[0] == '#')
		{
			int i = atoi(&temp2[1]);
			char temp[30], tempI[30];
			newTemp(temp);
			sprintf(tempI, "#%d", i * curSize);
			addCode(5, temp, ":=", temp1, "+", tempI);
			strcpy(place, temp);
		}
		else
		{
			char temp[30], tempI[30], num[30];
			sprintf(num, "#%d", curSize);
			newTemp(temp);
			newTemp(tempI);
			addCode(5, tempI, ":=", temp2, "*", num);
			addCode(5, temp, ":=", temp1, "+", tempI);
			strcpy(place, temp);
		}
	}
	else
	{
		char left[30];
		getAddress(p->child, left);
		int offsetI = getStructOffset(curStruct, p->child->bro->bro->name);
		char offset[30];
		sprintf(offset, "#%d", offsetI);
		newTemp(place);
		addCode(5, place, ":=", left, "+", offset);
		Symbol s = findSymbol(p->child->bro->bro->name, curFunc);
		if(s->type->kind == TP_ARRAY)
			curSize = SIZE_OF_EACH;
		else if(s->type->kind == TP_STRUCT)
			curStruct = s->type->structure;
	}
}

/**
 * 得到结构或者数组所需内存
 * @param  type 结构或数组类型指针
 * @return      内存空间大小
 */
int getTypeSize(Type *type)
{
	if(type->kind == TP_ARRAY)
		return type->array->size * SIZE_OF_EACH;
	int size = 0;
	for(FieldList *f = type->structure; f; f = f->next)
	{
		if(f->fieldType->kind != TP_ARRAY && f->fieldType->kind != TP_STRUCT)
			size += SIZE_OF_EACH;
		else
			size += getTypeSize(f->fieldType);
	}
	return size;
}

int getStructOffset(Structure *struc, char *fieldName)
{
	int count = 0;
	for(FieldList *f = struc; f; f = f->next)
	{
		char *existName = namePool.names + f->pos;
		if(strcmp(existName, fieldName) == 0)
			break;
		if(f->fieldType->kind != TP_ARRAY && f->fieldType->kind != TP_STRUCT)
			count += 4;
		else
			count += getTypeSize(f->fieldType);
	}
	return count;
}

