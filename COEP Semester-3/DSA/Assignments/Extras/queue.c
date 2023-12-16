#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct queue
{
    int *A, f, r, s;
} Queue;

void init_Queue(Queue *q, int s){
    q->A = (int*)malloc(sizeof(int)*s);
    q->f=-1;
    q->r=-1;
    q->s=s;
}

int isEmpty(Queue *q){
    return q->f==-1 && q->r==-1;
}

int isFull(Queue *q){
    return q->r==q->s;
}

void enqueue(Queue *q, int data){
    if (isFull(q)){
        printf("\nQueue is Full!");
        return;
    }
    if (q->f==-1 && q->r==-1){
        q->f=0;
        q->r=0;
    }else{
        q->r=q->r+1;
    }
    q->A[q->r]=data;
}

void dequeue(Queue *q){
    if (isEmpty(q)){
        printf("\nQueue is Empty!");
        return;
    }else if(q->r==0 && q->f==0){
        q->f=-1;
        q->r=-1;
    }else{
        q->f=q->f+1;
    }
    printf("\nRemoved Element: %d",q->A[q->f-1]);

}

void display(Queue *q){
    for (int i=q->f; i<=q->r;i++){
        printf("\n%d",q->A[i]);
    }
}

void main(){
    Queue *q1;
    init_Queue(q1,5);

    dequeue(q1);

    printf("\n\nEnqueued!");
    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 40);
    enqueue(q1, 50);
    enqueue(q1, 60);
    enqueue(q1, 70);

    display(q1);

    printf("\n\nDequeued!");
    dequeue(q1);
    display(q1);

    printf("\n\nEnqueued!");
    enqueue(q1, 40);
    display(q1);

}