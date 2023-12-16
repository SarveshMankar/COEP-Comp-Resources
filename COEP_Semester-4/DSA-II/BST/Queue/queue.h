typedef struct Queue {
    struct QNode * f;
    struct QNode * r;
    int count;
    int size;
}
Queue;

typedef struct QNode {
    int data;
    struct QNode * next;
}
QNode;

void initQueue(Queue *q);
int isEmpty(Queue *Q);
int isFull(Queue *Q);

int dequeue(Queue *Q);
int enqueue(Queue *Q, int data);