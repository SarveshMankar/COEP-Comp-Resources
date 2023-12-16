#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"func.h"
#include"queue.h"

void initQueue(Queue *q){
    q->f = NULL;
    q->r = NULL;
    q->count = 0;
    q->size = 100;
}

int enqueue(Queue *Q, int data) {
    int e = INT_MIN;

    if (Q->count + 1 == Q->size) {
        return e;
    }

    Node * temp = Q->r;
    
    Node * qnode = (Node * ) malloc(sizeof(Node));
    qnode -> data = data;

    if (Q->count == 0) {
        Q->f = qnode;
        Q->r = qnode;
    } else {
        temp -> next = qnode;
    }

    Q->r = qnode;
    Q->count++;

    return 0;
}

int isEmpty(Queue *Q) {
    return Q->count == 0;
}

int isFull(Queue *Q) {
    return Q->size == Q->count;
}

int dequeue(Queue *Q) {
    int e = INT_MIN;

    if (Q->count == 0) {
        return e;
    }

    int ret = Q->f -> data;
    Node * temp = Q->f;
    Q->f = Q->f -> next;
    free(temp);

    Q->count--;

    return ret;
}

int peekFront(Queue *Q) {
    if (Q->count == 0) {
        return -1;
    }

    return Q->f -> data;
}

int peekRear(Queue *Q) {
    if (Q->count == 0) {
        return -1;
    }
	
    return Q->r -> data;
}

