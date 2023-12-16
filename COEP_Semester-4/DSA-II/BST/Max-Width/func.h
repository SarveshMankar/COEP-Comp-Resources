typedef struct node
{
    int data;
    struct node *left, *right;
} node;


typedef node* BST;


//Queue
typedef struct Queue {
    struct QNode * f;
    struct QNode * r;
    int count;
    int size;
}
Queue;

typedef struct QNode {
    node *data;
    int index;
    struct QNode * next;
}
QNode;

void initQueue(Queue *q);

void enqueue(Queue *Q, node *data, int index);
node *dequeue(Queue *Q);

int isEmpty(Queue *Q);
int isFull(Queue *Q);
QNode *peekRear(Queue *Q);
QNode *peekFront(Queue *Q);





void initBST(BST *t);
void insertWithRecursion(BST *t, int key);

void inOrderWithRecursion(BST t);

void preOrderWithRecursion(BST t);

void postOrderWithRecursion(BST t);

void displayLevel(BST t, int curr, int level);
void levelOrderWithQueue(BST t);

int height(BST t);

int maxWidth(BST t);
