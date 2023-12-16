#include<stdio.h>
#include<stdlib.h>

typedef struct myQueue{
    int *arr, front, rear, size, count;
} Queue;

void init(Queue *queue, int size){
    queue->arr=(int *)malloc(sizeof(int)*size);
    queue->front=queue->rear=-1;
    queue->count=0;
    queue->size=size;
}

int isFull(Queue *queue){
    if(queue->count==queue->size){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(Queue *queue){
    if(queue->count==0){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(Queue *queue, int data){
    if(isFull(queue)){
        return;
    }else{
        if(isEmpty(queue)){
            queue->front=queue->rear=0;
            queue->arr[queue->rear]=data;
        }else{
            queue->rear+=1;
            queue->arr[queue->rear]=data;
        }
    }
    queue->count+=1;
}

void dequeue(Queue *queue){
    if(isEmpty(queue)){
        return;
    }else{
        if(queue->front==queue->rear){
            queue->front=queue->rear=-1;
        }else{
            queue->front+=1;
        }
    }
    queue->count-=1;

}

void display(Queue *queue){
    int i=0;
	int s=queue->front;
	int e=queue->rear;
	
	while(s!=e){
		printf("%d\t",queue->arr[s]);
		s=(s+1)%queue->size;
	}
	printf("%d\n",queue->arr[s]);

	printf("---------------");
}

void main(){
    Queue *q1 = (Queue *)malloc(sizeof(Queue));
    int size=10;
    init(q1,size);

    enqueue(q1,10);
    enqueue(q1,20);
    enqueue(q1,30);
    enqueue(q1,40);
    enqueue(q1,50);

    display(q1);

    dequeue(q1);
    dequeue(q1);

    display(q1);
}