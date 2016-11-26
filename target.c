#include "compiler.h"

static VOT varTable[100];
static int varCount = 0;
static int _offset = 0;
static int argsCount = 0;

int getVarOffset(char *name)
{
	if(name[0] == '#')
		return -1;
	if(name[0] == '*' || name[0] == '&')
		name++;
	for(int i = 0; i < varCount; i++)
	{
		if(strcmp(name, varTable[i].name) == 0)
			return varTable[i].offset;
	}
	return -1;
}

void addVar(char *name, int size)
{
	if(name[0] == '#')
		return;
	if(name[0] == '*' || name[0] == '&')
		name++;
	if(getVarOffset(name) != -1)
		return;
	varTable[varCount].offset = _offset;
	_offset += size;
	strcpy(varTable[varCount].name, name);
	varCount++;
}

void allocReg(char *name, int no)
{
	char reg[5];
	sprintf(reg, "$t%d", no);
	if(name[0]=='*')
	{
		fprintf(targetFile, "lw %s, %d($sp)\n", reg, getVarOffset(name));
		fprintf(targetFile, "add %s, %s, $sp\n", reg, reg);
		fprintf(targetFile, "lw %s, 0(%s)\n", reg, reg);
	}
	else if(name[0]=='&')
	{
		fprintf(targetFile, "li %s, %d\n", reg, getVarOffset(name));
	}
	else if(name[0]=='#')
	{
		fprintf(targetFile, "li %s, %s\n", reg, &name[1]);
	}
	else
	{
		fprintf(targetFile, "lw %s, %d($sp)\n", reg, getVarOffset(name));
	}
}

void targetCode(InterCode *head)
{
	fprintf(targetFile, ".data\n");
	fprintf(targetFile, "_prompt: .asciiz \"Enter an integer:\"\n");
	fprintf(targetFile, "_ret: .asciiz \"\\n\"\n");
	fprintf(targetFile, ".globl main\n");
	fprintf(targetFile, ".text\n\n");
	fprintf(targetFile, "read:\n");
	fprintf(targetFile, "li $v0, 4\n");
	fprintf(targetFile, "la $a0, _prompt\n");
	fprintf(targetFile, "syscall\n");
	fprintf(targetFile, "li $v0, 5\n");
	fprintf(targetFile, "syscall\n");
	fprintf(targetFile, "jr $ra\n\n");
	fprintf(targetFile, "write:\n");
	fprintf(targetFile, "li $v0, 1\n");
	fprintf(targetFile, "syscall\n");
	fprintf(targetFile, "li $v0, 4\n");
	fprintf(targetFile, "la $a0, _ret\n");
	fprintf(targetFile, "syscall\n");
	fprintf(targetFile, "move $v0, $0\n");
	fprintf(targetFile, "jr $ra\n");
	InterCode *p = head, *q;
	do
	{
		q = p->next;
		while(1)
		{
			if(strcmp(q->args[0], "FUNCTION") == 0)
				break;
			if(q == head)
				break;
			q = q->next;
		}
		generateFunc(p, q);
		p = q;
	} while(p != head);
}

void generateFunc(InterCode *begin, InterCode *end)
{
	varCount = 0;
	_offset = 0;
	argsCount = 0;
	fprintf(targetFile, "\n%s:\n", begin->args[1]);
	InterCode *p = begin->next;
	while(p != end)
	{
		switch(p->argsCount)
		{
			case 2:
			{
				/**
				 * GOTO x
				 * RETURN x
				 * ARG x
				 * PARAM x
				 * READ x
				 * WRITE x
				 */
				if(strcmp(p->args[0], "GOTO") != 0)
					addVar(p->args[1], 4);
				break;
			}
			case 3:
			{
				/**
				 * LABEL x :
				 * FUNCTION f :
				 * x := y
				 * x := &y
				 * x := *y
				 * *x := y
				 * DEC x [size]
				 */
				if(strcmp(p->args[1], ":=") == 0)
				{
					addVar(p->args[0], 4);
					addVar(p->args[2], 4);
				}
				else if(strcmp(p->args[0], "DEC") == 0)
				{
					int size = atoi(p->args[2]);
					addVar(p->args[1], size);
				}
				break;
			}
			case 4:
			{
				/**
				 * x := CALL f
				 */
				addVar(p->args[0], 4);
				break;
			}
			case 5:
			{
				/**
				 * x := y + z
				 * x := y - z
				 * x := y * z
				 * x := y / z
				 */
				addVar(p->args[0], 4);
				addVar(p->args[2], 4);
				addVar(p->args[4], 4);
				break;
			}
			case 6:
			{
				/**
				 * IF x [relop] y GOTO z
				 */
				addVar(p->args[1], 4);
				addVar(p->args[3], 4);
				break;
			}
			default: break;
		}
		p = p->next;
	}
	fprintf(targetFile, "addi $sp, $sp, -%d\n", _offset);
	p = begin->next;
	while(p != end)
	{
		switch(p->argsCount)
		{
			case 2:
			{
				/**
				 * GOTO x
				 * RETURN x
				 * ARG x
				 * PARAM x
				 * READ x
				 * WRITE x
				 */
				if(strcmp(p->args[0], "GOTO") == 0)
					fprintf(targetFile, "j %s\n", p->args[1]);
				else if(strcmp(p->args[0], "RETURN") == 0)
				{
					allocReg(p->args[1], 0);
					fprintf(targetFile, "move $v0, $t0\n");
					fprintf(targetFile, "addi $sp, $sp, %d\n", _offset);
					fprintf(targetFile, "jr $ra\n");
				}
				else if(strcmp(p->args[0], "ARG") == 0)
				{
					allocReg(p->args[1], 0);
					fprintf(targetFile, "move $a%d, $t0\n", argsCount);
					argsCount++;
				}
				else if(strcmp(p->args[0], "PARAM") == 0)
				{
					int paramCount = 0;
					InterCode *q = p;
					while(strcmp(q->next->args[0], "PARAM") == 0)
					{
						q = q->next;
						paramCount++;
					}
					fprintf(targetFile, "sw $a%d, %d($sp)\n", paramCount, getVarOffset(p->args[1]));
				}
				else if(strcmp(p->args[0], "READ") == 0)
				{
					fprintf(targetFile, "addi $sp, $sp, -4\n");
					fprintf(targetFile, "sw $ra, 0($sp)\n");
					fprintf(targetFile, "jal read\n");
					fprintf(targetFile, "lw $ra, 0($sp)\n");
					fprintf(targetFile, "addi $sp, $sp, 4\n");
					if(p->args[1][0] == '*')
					{
						fprintf(targetFile, "lw $t0, %d($sp)\n", getVarOffset(p->args[1]));
						fprintf(targetFile, "add $t0, $t0, $sp\n");
						fprintf(targetFile, "sw $v0, 0($t0)\n");
					}
					else
					{
						fprintf(targetFile, "sw $v0, %d($sp)\n", getVarOffset(p->args[1]));
					}
				}
				else if(strcmp(p->args[0], "WRITE") == 0)
				{
					allocReg(p->args[1], 0);
					fprintf(targetFile, "move $a0, $t0\n");
					fprintf(targetFile, "addi $sp, $sp, -4\n");
					fprintf(targetFile, "sw $ra, 0($sp)\n");
					fprintf(targetFile, "jal write\n");
					fprintf(targetFile, "lw $ra, 0($sp)\n");
					fprintf(targetFile, "addi $sp, $sp, 4\n");
				}
				break;
			}
			case 3:
			{
				/**
				 * LABEL x :
				 * FUNCTION f :
				 * x := y
				 * x := &y
				 * x := *y
				 * *x := y
				 * DEC x [size]
				 */
				if(strcmp(p->args[1], ":=") == 0)
				{
					allocReg(p->args[2], 0);
					if(p->args[0][0] == '*')
					{
						fprintf(targetFile, "lw $t1, %d($sp)\n", getVarOffset(p->args[0]));
						fprintf(targetFile, "add $t1, $t1, $sp\n");
						fprintf(targetFile, "sw $t0, 0($t1)\n");
					}
					else
					{
						fprintf(targetFile, "sw $t0, %d($sp)\n", getVarOffset(p->args[0]));
					}
				}
				else if(strcmp(p->args[0], "LABEL") == 0)
				{
					fprintf(targetFile, "%s:\n", p->args[1]);
				}
				break;
			}
			case 4:
			{
				/**
				 * x := CALL f
				 */
				argsCount = 0;
				fprintf(targetFile, "addi $sp, $sp, -4\n");
				fprintf(targetFile, "sw $ra, 0($sp)\n");
				fprintf(targetFile, "jal %s\n", p->args[3]);
				fprintf(targetFile, "lw $ra, 0($sp)\n");
				fprintf(targetFile, "addi $sp, $sp, 4\n");
				if(p->args[0][0] == '*')
				{
					fprintf(targetFile, "lw $t0, %d($sp)\n", getVarOffset(p->args[0]));
					fprintf(targetFile, "add $t0, $t0, $sp\n");
					fprintf(targetFile, "sw $v0, 0($t0)\n");
				}
				else
					fprintf(targetFile, "sw $v0, %d($sp)\n", getVarOffset(p->args[0]));
				break;
			}
			case 5:
			{
				/**
				 * x := y + z
				 * x := y - z
				 * x := y * z
				 * x := y / z
				 */
				allocReg(p->args[2], 0);
				allocReg(p->args[4], 1);
				switch(p->args[3][0])
				{
					case '+':
					{
						fprintf(targetFile, "add $t0, $t0, $t1\n");
						break;
					}
					case '-':
					{
						fprintf(targetFile, "sub $t0, $t0, $t1\n");
						break;
					}
					case '*':
					{
						fprintf(targetFile, "mul $t0, $t0, $t1\n");
						break;
					}
					case '/':
					{
						fprintf(targetFile, "div $t0, $t1\n");
						fprintf(targetFile, "mflo $t0\n");
						break;
					}
					default: break;
				}
				fprintf(targetFile, "sw $t0, %d($sp)\n", getVarOffset(p->args[0]));
				break;
			}
			case 6:
			{
				/**
				 * IF x [relop] y GOTO z
				 */
				char relOp[4];
				if(strcmp(p->args[2], "==") == 0)
					strcpy(relOp, "beq");
				else if(strcmp(p->args[2], "!=") == 0)
					strcpy(relOp, "bne");
				else if(strcmp(p->args[2], ">") == 0)
					strcpy(relOp, "bgt");
				else if(strcmp(p->args[2], "<") == 0)
					strcpy(relOp, "blt");
				else if(strcmp(p->args[2], ">=") == 0)
					strcpy(relOp, "bge");
				else if(strcmp(p->args[2], "<=") == 0)
					strcpy(relOp, "ble");
				allocReg(p->args[1], 0);
				allocReg(p->args[3], 1);
				fprintf(targetFile, "%s $t0, $t1, %s\n", relOp, p->args[5]);
				break;
			}
			default: break;
		}
		p = p->next;
	}
}