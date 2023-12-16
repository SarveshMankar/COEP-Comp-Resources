#include<stdio.h>
#include<stdlib.h>

typedef struct LL
{
    int data;
    struct LL *next; 
} node;

node *top = NULL;

void push(int data){
    node *n1 = (node*) malloc(sizeof(node));
    n1->data=data;

    if(top==NULL){
        n1->next=NULL;
    }else{
        n1->next=top;
    }
    top=n1;
}

void pop(){
    node *n1 = top;
    top=top->next;
    free(n1);
}

void peek(){
    printf("%d",top->data);
}

void display(){
    node *temp;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}

void main(){
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    push(50);
    push(60);
    
    display();
}