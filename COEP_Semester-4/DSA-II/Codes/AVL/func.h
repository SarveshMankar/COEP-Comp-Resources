typedef struct node {
    int data, balance;
    struct node *left, *right;
    struct node *parent;
} node;

typedef node* AVL;

void initAVL(AVL *t);
void insertNode(AVL *t, int data);
node *removeNode(AVL *t, int data);

int height(AVL t);
node *imbalanceNode(AVL t);
void adjustBF(AVL t);

void leftRotate(AVL *t, node *imb);
void rightRotate(AVL *t, node *imb);

void leftRightRotate(AVL *t, node *imb);
void rightLeftRotate(AVL *t, node *imb);

void traverse(AVL t);
node *inOrderSuccessor(AVL t);
void inorder(node *t);
void preorder(node *t);

void destroyAVL(AVL t);


node *tempRemoveNode(AVL *t, int data);