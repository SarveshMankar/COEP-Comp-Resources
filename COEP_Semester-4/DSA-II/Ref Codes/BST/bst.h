#define LEN 40

typedef struct node{
    double mis;//key
    char name[LEN];
    struct node *left, *right, *parent;
}node;

typedef node *bst;


typedef struct stack{
    node *A;
    int size;
    int top;
}stack;



//tree functions
void initBST(bst *t); // to initialize the tree
void insertNode(bst *t, double d, char a[LEN]); // recursive function to add a new node to the tree
void removeNode(bst *t, double d); // to remove a node from a tree
//void r_postorder(bst t);//for testing and matching ouput of non recursive postorder with recursive postorder
void postorder(bst t); // non-recursive function for post order traversal
int search(bst t, double d); // to recursive search for a node with the key and return a boolean value
void destroyTree(bst *t); // to delete all nodes of a tree
void Display_Level(bst t, int curr_level, int level); // to display all nodes of ith level

//stack functions
void initStack(stack *s, int i); //initializing and allocation memory to array stack
void push(stack *s, node n); //to insert node
node pop(stack *s); //to delete node
node peek(stack s); //to view top element of stack
int isfull(stack s); //checking if stack is full
int isempty(stack s); //checking if stack is empty

