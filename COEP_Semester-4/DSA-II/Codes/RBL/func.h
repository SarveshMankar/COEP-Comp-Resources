typedef struct node {
    int data, balance, color;
    struct node *left, *right;
    struct node *parent;
} node;

typedef node* RBL;

void initRBL(RBL *t);
void insertNode(RBL *t, int data);
node *removeNode(RBL *t, int data);

int height(RBL t);
node *imbalanceNode(RBL t);
void adjustBF(RBL t);

void leftRotate(RBL *t, node *imb);
void rightRotate(RBL *t, node *imb);

void leftRightRotate(RBL *t, node *imb);
void rightLeftRotate(RBL *t, node *imb);

void traverse(RBL t);
node *inOrderSuccessor(RBL t);
void inorder(node *t);
void preorder(node *t);

void destroyRBL(RBL t);


node *tempRemoveNode(RBL *t, int data);