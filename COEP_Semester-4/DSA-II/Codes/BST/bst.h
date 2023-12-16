typedef struct node {
    int data;
    struct node *left, *right;
} node;

void initBST(node **t); // to initialize the tree
void insertNode(node **t, int data);
int search(node *t, int data);
void displayTLevel(node *t, int curr, int tl);
void displayTree(node *t);
int treeDepth(node *t);
node  *deleteNode(node *t, int data); 
node *minValueNode(node* node);
node *deleteTree(node *t);

void preOrderTraversal(node *t);
void inOrderTraversal(node *t);
void postOrderTraversal(node *t);

void postOrderTraversalWithoutRecursion(node *t);
void push(node *t, int size, int *top, node stack[]);
