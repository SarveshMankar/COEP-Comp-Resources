#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include<limits.h>

void initStack(stack *ms){
	ms->A = (int*)malloc(sizeof(int) * 100);
    ms->s = 100;
	ms->top = -1;
	return;
}

void push(stack *S, int n){
	if(!S)
	  return;
	if(S->top == -1){
	  S->A[++S->top] = n;
	  return;
	}
	S->A[++S->top] = n;
	return;
}

int pop(stack *S){
	if(!S || S->top == -1)
	  return INT_MIN; // INT_MIN is defined in limits.h (minimum value for an object of type int
	int n = S->A[S->top--];
	return n;
}

int isEmptyS(stack *s){
	if(s->top==-1){
		// printf("Is Empty!");
		return 1;
	}else{
		// printf("Not Empty!");
		return 0;
	}
}

int isFullS(stack *s){
	if(s->top==s->s){
		return 1;
	}else{
		return 0;
	}
}

void peekS(stack *s){
	printf("\n%d", s->A[s->top]);
}
