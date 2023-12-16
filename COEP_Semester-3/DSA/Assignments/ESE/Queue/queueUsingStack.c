#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size,top;
    int *a;
} stack;

void display(stack *s);
void push(stack *s, int data);
void pop(stack *s1);

stack *s1;

void push(stack *s, int data){
    s->top=s->top+1;
    s->a[s->top]=data;
}

void pop(stack *s1){
    stack *s2 = (stack*) malloc (sizeof(stack));
    s2->size=100;
    s2->top=-1;
    s2->a=(int *)malloc(sizeof(int)*s2->size);

    int myTop = s1->top;
    while(myTop>=0){
        push(s2,s1->a[myTop]);
        myTop--;
    }

    int popped = s2->a[s2->top];
    s2->top=s2->top-1;
    

    myTop = s2->top;
    s1->top=-1;
    while(myTop>=0){
        push(s1,s2->a[myTop]);
        myTop--;
    }
}


void display(stack *s){
    printf("---------\n");
    int top=s->top;
    while(top>=0){
        printf("%d\t",s->a[top]);
        top--;
    }
    printf("\n---------\n");
}

void main(){
    s1 = (stack*) malloc (sizeof(stack));
    s1->size=100;
    s1->top=-1;
    s1->a=(int *)malloc(sizeof(int)*s1->size);

    push(s1,10);
    push(s1,20);
    push(s1,30);
    push(s1,40);
    push(s1,50);
    push(s1,60);
    display(s1);

    pop(s1);
    display(s1);
}