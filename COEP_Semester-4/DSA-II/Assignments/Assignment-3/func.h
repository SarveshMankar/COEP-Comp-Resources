typedef struct node {
    char name[100];
    int balance;
    struct node *left, *right;
    struct node *parent;
} node;

typedef node* AVL;

void initAVL(AVL *t);
void insertNode(AVL *t, char name[]);
node *removeNode(AVL *t, char name[]);

int height(AVL t);
node *imbalanceNode(AVL t);
void adjustBF(AVL t);

void leftRotate(AVL *t, node *imb);
void rightRotate(AVL *t, node *imb);

void leftRightRotate(AVL *t, node *imb);
void rightLeftRotate(AVL *t, node *imb);

void traverse(AVL t);
node *inOrderSuccessor(AVL t);

void destroyAVL(AVL t);
