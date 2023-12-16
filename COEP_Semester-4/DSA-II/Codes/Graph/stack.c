#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include<limits.h>

void initStack(stack **s, int size){
	*s = (stack *)malloc(sizeof(stack));
	(*s)->size=size;
	(*s)->top=-1;
	(*s)->A=(int *)malloc(sizeof(int)*size+1);
}

void push(stack *s, int data){
	if ((s)->A[(s)->top]==(s)->size-1){
		printf("\nStack is Full!\n");
	}else{
		(s)->top++;
		(s)->A[(s)->top]=data;		
		// *top=*top+1;
		// s[*top]=data;
	}
}

int pop(stack *s){
	if ((s)->top==-1){
		printf("\nStack is Empty!");
		return INT_MIN;
	}
	else{
		int top=(s)->A[(s)->top];
		(s)->top--;
		// *top=(*top)-1;
		return top;
	}
}

int isEmptyS(stack *s){
	if(s->top==-1){
		// printf("Is Empty!");
		return 1;
	}else{
		// printf("Not Empty!");
	}
}

int isFullS(stack *s){
	if(s->top==s->size){
		return 1;
	}else{
		return 0;
	}
}

void peekS(stack *s){
	printf("\n%d", s->A[s->top]);
}


// void main(){
// 	int top=-1;
// 	int size=5;
// 	int stack[size];
		
// 	push(stack, &top, size, 10);
// 	push(stack, &top, size, 20);
// 	push(stack, &top, size, 30);
// 	push(stack, &top, size, 40);
// 	push(stack, &top, size, 50);
// 	push(stack, &top, size, 60);
// 	push(stack, &top, size, 70);

// 	pop(stack, &top, size);
// 	peek(stack, top);
// 	push(stack, &top, size, 80);
// 	peek(stack, top);
// }