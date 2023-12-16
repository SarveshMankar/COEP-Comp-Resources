#include <stdio.h>
#include <stdlib.h>
typedef struct Queue{
    int front, rear;
    int count;
} Queue;


typedef struct Stack{
    int top;
    int count;
    int size;
} Stack;

void enqueue(Queue **Q, int data){
    Queue *temp = *Q;
    if (temp->count+1 > MAX_SIZE){

    }
}

int main(){
    
}