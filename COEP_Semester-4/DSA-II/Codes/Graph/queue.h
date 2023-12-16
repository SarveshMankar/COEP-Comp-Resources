typedef struct Queue {
    struct Node * f;
    struct Node * r;
    int count;
    int size;
}
Queue;

typedef struct Node {
    int data;
    struct Node * next;
}
Node;

void initQueue(Queue *q);
int isEmpty(Queue *Q);
int isFull(Queue *Q);

int dequeue(Queue *Q);
int enqueue(Queue *Q, int data);