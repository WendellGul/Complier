void generate(TreeNode *p, int tab)
{
    int i;
    for(i = 0; i < tab; i++)
        printf("\t");
    if(p->isTerminal == 1)
    {
        TNode tnode = p->tnode;
        switch(tnode.type)
        {
            case typeCon:
                printf("INT: %d\n", tnode.value);
            break;
            case typeId:
                printf("ID: %s\n", tnode.name);
            break;
            case typeOpr:
                switch(tnode.value)
                {
                    case LEQ: printf("OPER: LEQ\n"); break;
                    case GEQ: printf("OPER: GEQ\n"); break;
                    default : printf("OPER: %c\n", tnode.value);
                }       
            break;
            case typeReserve:
                switch(tnode.calue)
                {
                    case CONST: printf("RESERVED: CONST\n"); break;
                    case VAR: printf("RESERVED: VAR\n"); break;
                    case PROCEDURE: printf("RESERVED: PROCEDURE\n"); break;
                    case RESERVEDBEGIN: printf("RESERVED: BEGIN\n"); break;
                    case END: printf("RESERVED: END\n"); break;
                    case ODD: printf("RESERVED: ODD\n"); break;
                    case IF: printf("RESERVED: IF\n"); break;
                    case THEN: printf("RESERVED: THEN\n"); break;
                    case CALL: printf("RESERVED: CALL\n"); break;
                    case WHILE: printf("RESERVED: WHILE\n"); break;
                    case DO: printf("RESERVED: DO\n"); break;
                    case READ: printf("RESERVED: READ\n"); break;
                    case WRITE: printf("RESERVED: WRITE\n"); break;
                    case ASSIGN: printf("RESERVED: ASSIGN\n"); break;
                }
            break;
        }
    }
    else
    {
        NTNode ntnode = p->ntnode;
        printf("%s\n", ntnode.name);
        for(i = 0; i < ntnode.childNum; i++)
            generate(ntnode.child[i], tab + 1);
    }
}
