typedef enum {
    typeCon, typeId, typeOpr, typeReserve
} NodeType;

typedef struct {
    NodeType type;
    int value; // value of integer
    char name[30]; // name of identifier
} TNode; // terminal node

typedef struct {
    char name[30]; // name of non-terminal
    //int childNum;
} NTNode;

typedef struct treeNode {
    int isTerminal;
    union {
        TNode tnode; // terminal node
        NTNode ntnode; // non-terminal node
    };
    struct treeNode *child;
    struct treeNode *bro;
} TreeNode;