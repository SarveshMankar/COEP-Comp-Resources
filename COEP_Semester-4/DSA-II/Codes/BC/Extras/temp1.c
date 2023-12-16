#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.c"

typedef struct operator{
    char op;
} operator;

typedef struct nd1{
    int type;
    node *n1;
    operator *op;
} nd1;

typedef struct LL{
    nd1 *n1;
    struct LL *next;
} LL;

void appendLL(LL **head, nd1 *n1){
    LL *newNode = (LL *)malloc(sizeof(LL));
    newNode->n1 = n1;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }else{
        LL *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

LL *makeIt(char str[], LL *head){
    int len = strlen(str);

    node *n1 = (node *)malloc(sizeof(node));
    n1=NULL;    

    for(int i=0; i<len; i++){
        if(!(isOperator(str[i]))){
            append(&n1, str[i]);
        }else{
            nd1 *l1 = (nd1 *)malloc(sizeof(nd1));

            l1->type = 1;
            l1->n1 = n1;

            operator *op1 = (operator *)malloc(sizeof(operator));
            op1=NULL;
            l1->op = op1;

            appendLL(&head, l1);


            operator *op2 = (operator *)malloc(sizeof(operator));
            op2->op = str[i];

            nd1 *l2 = (nd1 *)malloc(sizeof(nd1));
            l2->type = 2;
            l2->n1 = NULL;
            l2->op = op2;

            appendLL(&head, l2);

            n1 = NULL;
        }
        printf("%c", str[i]);
        printf("\n");
    }

    return head;
}

void displayn1(node *n1){
    node *temp = n1;
    while(temp != NULL){
        printf("%c", temp->data);
        temp = temp->next;
    }
}

void displayop(operator *op){
    printf("%c", op->op);
}

void displayLL(LL *head){
    LL *temp = head;
    while(temp != NULL){
        printf("\n%d", temp->n1->type);

        if(temp->n1->n1!=NULL){
            printf("\tWe have Number!\t");
            displayn1(temp->n1->n1);
        }else if (temp->n1->op!=NULL){
            printf("\tWe have Operator!\t");
            displayop(temp->n1->op);
        }
        
        temp = temp->next;
    }
}


void main(){
    char str[] = "123+456+*%";
    LL *head = NULL;

    head = makeIt(str, head);
    printf("\nDisplay List:\t");
    displayLL(head);
}