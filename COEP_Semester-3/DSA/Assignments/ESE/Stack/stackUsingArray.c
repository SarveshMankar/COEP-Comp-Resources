#include<stdio.h>
#include<stdlib.h>

void push(int stack[], int *top, int size, int data){
	if (*top==size-1){
		printf("\nStack is Full!\n");
	}else{
		*top=*top+1;
		stack[*top]=data;
	}
}

void pop(int stack[], int *top, int size){
	if (*top==-1){
		printf("\nStack is Empty!");
	}
	else{
		*top=(*top)-1;
	}
}

void isEmpty(int stack[], int top){
	if(top==-1){
		printf("Is Empty!");
		return 1;
	}else{
		printf("Not Empty!");
	}
}

void isFull(int stack[], int top, int size){
	if(top==size){
		printf("Is Empty!");
		return 1;
	}else{
		printf("Not Empty!");
	}
}

void peek(int stack[],int top){
	printf("\n%d", stack[top]);
}

void main(){
	int top=-1;
	int size=5;
	int stack[size];
		
	push(stack, &top, size, 10);
	push(stack, &top, size, 20);
	push(stack, &top, size, 30);
	push(stack, &top, size, 40);
	push(stack, &top, size, 50);
	push(stack, &top, size, 60);
	push(stack, &top, size, 70);

	pop(stack, &top, size);
	peek(stack, top);
	push(stack, &top, size, 80);
	peek(stack, top);
}