typedef struct node
{
    int data, bf;
    struct node *l,*r,*p;
} node;

typedef node* AVL;

void insert(AVL *t, int d);
int height(AVL t);
void adjustBF(AVL t);
node *imbalanceNode(AVL t);

void leftRotate(AVL *t, node *imb);
void rightRotate(AVL *t, node *imb);

void leftRightRotate(AVL *t, node *imb);
void rightLeftRotate(AVL *t, node *imb);


void inorder(AVL t);
void preorder(AVL t);
