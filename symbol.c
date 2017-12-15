#include "compiler.h"

#define A_NAME_HEAD	"__compiler_exp"
#define A_NAME_TAIL	"__"
static int nameCount = 0;

NamePool namePool; 
Symbol table[MAX_SIZE];
/**
 * hash function
 * @param  name string
 * @return      hash value
 */
unsigned int hash_pjw(const char *name) 
{
	unsigned int val = 0, i;
	for(; *name; ++name)
	{
		val = (val << 2) + *name;
		if(i = val & ~MAX_SIZE)
			val = (val ^ (i >> 12)) & MAX_SIZE;
	}
	return val;
}

/**
 * init symbol table
 */
void initTable()
{
	namePool.curPos = 0;
	for(int i = 0; i < MAX_SIZE; i++)
		table[i] = NULL;
	Symbol read = createSymbol("read", 0, 0);
	setType(&read->type, TP_FUNC);
	setFuncRet(read->type->func, TP_INT);
	enterTable(read);
	Symbol write = createSymbol("write", 0, 0);
	setType(&write->type, TP_FUNC);
	setFuncRet(write->type->func, TP_INT);
	setField(&write->type->func->params, "", TP_INT);
	write->type->func->paramNum = 1;
	enterTable(write);
}

/**
 * create a symbol by name
 * @param  name  symbol name
 * @param  level symbol level
 * @param  line  symbol line
 * @return       a new symbol struct pointer
 */
Symbol createSymbol(const char *name, int level, int line)
{
	Symbol symbol = NEW_SYMBOL;
	int len = strlen(name);
	if(namePool.curPos + len >= POOL_SIZE)
		return NULL;
	strcpy(namePool.names + namePool.curPos, name);
	symbol->pos = namePool.curPos;
	symbol->level = level;
	symbol->line = line;
	symbol->type = NULL;
	symbol->next = NULL;
	namePool.curPos += len + 1;
	return symbol;
}

/**
 * set the property of a Type struct
 * @param t    the Type struct pointer to be set
 * @param kind type kind
 */
void setType(Type **t, ValKind kind)
{
	if(*t == NULL)
		*t = NEW_TYPE;
	(*t)->kind = kind;
	switch(kind)
	{
		case TP_ARRAY:
			(*t)->array = NEW_ARRAY;
			(*t)->array->elemType = NULL;
		break;
		case TP_STRUCT:
			(*t)->structure = NULL;
		break;
		case TP_FUNC:
			(*t)->func = NEW_FUNC;
			(*t)->func->retType = NULL;
			(*t)->func->params = NULL;
			(*t)->func->paramNum = 0;
		break;
		default:
		break;
	}
}

/**
 * set the property of a Array struct
 * @param a    the Array struct pointer to be set
 * @param size array size
 * @param kind type kind
 */
void setArray(Array **a, int size, ValKind kind)
{
	if(*a == NULL)
		*a = NEW_ARRAY;
	(*a)->size = size;
	(*a)->elemType = NEW_TYPE;
	setType(&((*a)->elemType), kind);
}

/**
 * set the property of a Field struct
 * @param field the Field struct pointer to be set
 * @param name  field name
 * @param kind  type kind
 */
void setField(FieldList **field, char *name, ValKind kind)
{
	int len = strlen(name);
	if(namePool.curPos + len >= POOL_SIZE)
		return;
	strcpy(namePool.names + namePool.curPos, name);
	if(*field == NULL)
	{
		*field = NEW_FIELD;
		(*field)->pos = namePool.curPos;
		(*field)->fieldType = NEW_TYPE;
		setType(&((*field)->fieldType), kind);
		(*field)->next = NULL;
	}
	else
	{
		FieldList *s = NEW_FIELD, *temp;
		s->pos = namePool.curPos;
		s->fieldType = NEW_TYPE;
		setType(&(s->fieldType), kind);
		s->next = NULL;
		for(temp = *field; temp->next; temp = temp->next);
		temp->next = s;
	}
	namePool.curPos += len + 1;
}

BOOL setFieldTypeArray(FieldList **field, char *name, Array *a)
{
	if(*field == NULL)
		return FALSE;
	for(FieldList **f = field; *f; *f = (*f)->next)
	{
		if(strcmp(namePool.names + (*f)->pos, name) == 0)
		{
			(*f)->fieldType->array = a;
			return TRUE;
		}
	}
	return FALSE;
}

/**
 * set the return type of a Function struct
 * @param func     the Function struct to be set
 * @param retType  return type
 * @param paramNum param num
 */
void setFuncRet(Function *func, ValKind retType)
{
	if(func->retType == NULL)
		func->retType = NEW_TYPE;
	setType(&(func->retType), retType);
}

/**
 * enter symbol table
 * @param  symbol the symbol pointer to be added in the table
 * @return        TRUE if success, otherwise return FALSE
 */
BOOL enterTable(Symbol symbol)
{
	if(symbol == NULL)
		return FALSE;
	char *name = namePool.names + symbol->pos;
	unsigned int hash = hash_pjw(name);
	int idx = hash;
	while(table[idx])
	{
		int pos = table[idx]->pos;
		char *existName = namePool.names + pos;
		if(strcmp(existName, name) == 0)
		{
			if(table[idx]->level == level)
				return FALSE;
			symbol->next = table[idx];
			table[idx] = symbol;
			break;
		}
		else
			idx++;
		if(idx == hash)
			return FALSE;
	}
	table[idx] = symbol;
	return TRUE;
}

/**
 * find a symbol by name
 * @param  name symbol name to be found
 * @return      the symbol pointer if found, else return NULL
 */
Symbol findSymbol(const char *name, Function *curFunc)
{
	unsigned int hash = hash_pjw(name);
	int idx = hash;
	while(table[idx])
	{
		int pos = table[idx]->pos;
		char *existName = namePool.names + pos;
		if(strcmp(existName, name) == 0)
			return table[idx];
		else
			idx++;
		if(idx == hash)
			break;
	}
	if(idx == hash)
	{
		if(curFunc == NULL)
			return NULL;
		Type *type = findFieldType(curFunc->params, name);
		if(type != NULL)
		{
			Symbol s = createSymbol(name, 0, -1);
			s->type = type;
			return s;
		}
	}
	return NULL;
}


Type* findFieldType(FieldList *field, const char *name)
{
	for(FieldList *f = field; f; f = f->next)
	{
		char *existName = namePool.names + f->pos;
		if(strcmp(existName, name) == 0)
			return f->fieldType;
	}
	return NULL;
}

void getAnonymous(char *name)
{
	strcpy(name, A_NAME_HEAD);
	char temp[20];
	m_itoa(nameCount, temp);
	nameCount++;
	strcat(name, temp);
	strcat(name, A_NAME_TAIL);
}

void m_itoa(int n, char *s)
{
	int i = 0, c = n / 26;
	strcpy(s, "");
	if(c != 0)
	{
		for(i = 0; i < c; i++)
			s[i] = 'z';
	}
	else
		s[i++] = 'a' + (n % 26);
	s[i] = '\0';
}

/**
 * destroy symbol table
 */
void destroyTable()
{
	for(int i = 0; i < MAX_SIZE; i++)
	{
		Symbol s = table[i], temp;
		while(s)
		{
			freeType(s->type);
			temp = s;
			s = s->next;
			free(temp);
			temp = NULL;
		}
		
	}
}

void freeType(Type *type)
{
	if(type == NULL)
		return;
	switch(type->kind)
	{
		case TP_INT:
		case TP_FLOAT:
		{
			free(type);
			type = NULL;
			break;
		}
		case TP_ARRAY:
		{
			freeType(type->array->elemType);
			free(type->array);
			break;
		}
		case TP_STRUCT:
		{
			freeField(type->structure);
			break;
		}
		case TP_FUNC:
		{
			freeType(type->func->retType);
			freeField(type->func->params);
			break;
		}
	}
}

void freeField(FieldList *f)
{
	FieldList *p = f, *temp;
	while(p)
	{
		freeType(f->fieldType);
		temp = p;
		p = p->next;
		free(temp);
		temp = NULL;
	}
}