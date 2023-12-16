#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int *A,r,f,s,c;
} Queue;

void initQueue(Queue *q, int size){
	q->A = (int *) malloc(sizeof(int)*size);
	q->r=-1;
	q->f=-1;
	q->s=size;
	q->c=0;
}

int isFull(Queue *q){
	if (q->c==q->s){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(Queue * q){
	if (q->c==0){
		return 1;	
	}else{
		return 0;
	}
}

void enqueue(Queue *q, int data){
	if (isFull(q)){
		return;
	}else{
		if (q->c==0){
			q->f=q->r=0;
			q->A[q->r]=data;
		}else{
			q->r=(q->r+1)%q->s;
			q->A[q->r]=data;
		}
		q->c=q->c+1;
	}
}

void dequeue(Queue *q){
	if (isEmpty(q)){
		return;
	}else{
		if (q->c==1){
			printf("\n%d",q->A[q->f]);
			q->r==-1;
			q->f==-1;
		}else{
			printf("\n%d",q->A[q->f]);
			q->f=(q->f+1)%q->s;
		}

		q->c=q->c-1;
	}
}

void peekRear(Queue *q){
	printf("\nRear= %d",q->A[q->r]);
}

void peekFront(Queue *q){
	printf("\nFront= %d",q->A[q->f]);
}

void displayQueue(Queue *q){
	int i=0;
	int s=q->f;
	int e=q->r;
	
	while(s!=e){
		printf("%d\t",q->A[s]);
		s=(s+1)%q->s;
	}
	printf("%d\n",q->A[s]);

	printf("---------------");
}

void main(){
	Queue *q = (Queue *) malloc (sizeof(Queue));
	initQueue(q,5); 
	
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	enqueue(q,40);
	enqueue(q,50);
	enqueue(q,60);

	displayQueue(q);
	peekRear(q);
	peekFront(q);

	dequeue(q);

	enqueue(q,70);

	dequeue(q);
	dequeue(q);

	enqueue(q,80);
	enqueue(q,90);

	dequeue(q);

	displayQueue(q);	
}