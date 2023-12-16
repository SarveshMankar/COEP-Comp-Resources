#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"
#include "../func.h"

void initStack(stack *s){
    s->top=NULL;
}

void push(stack *s, node *data){
    stack *t = (stack *)malloc(sizeof(stack));
    t->data=data;
    if(s->top==NULL){
        s->next=NULL;
    }else{
        t->next=s->top;
    }
    s->top=t;
    // printf("\n%d",top->data->data);
}

node *pop(stack *s){
    if(s->top==NULL){
        printf("UnderFlow!");
    }else{
        stack *temp = s->top;
        s->top=s->top->next;
        return temp->data;
        // stack *p=top;
        // stack *tn=p->next;
        // top=p->next;
        // free(p);
        // return tn->data;
    }
}

int isEmptyStack(stack *s){
    if(s->top==NULL){
        return 1;
    }else{
        return 0;
    }
}

stack *destroyStack(stack *s){
    stack *temp=s;
    stack *t;
    while (temp->top){
        t=temp->top->top;
        free(temp->top);
        temp=t;
    }
    free(temp);

    return NULL;    
}
