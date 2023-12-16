#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} List;

void printList(List* n){
    while(n!=NULL){
        printf("%d\n",n->data);
        n = n->next;
    }
}

void append(List* n, int d){
    List* newNode = (List*) malloc(sizeof(List));
    newNode->data=d;
    newNode->next=NULL;

    //If List in empty
    if(n==NULL){
        n=newNode;
        return;
    }

    while(n->next!=NULL){
        n=n->next;
    }

    n->next=newNode;

}

void addToFirst(List** head, int d){
    List* newNode = (List*) malloc(sizeof(List));
    newNode->data=d;
    newNode->next=*head;
    *head=newNode;
}

void search(List* n, int d){
    while(n!=NULL){
        if(n->data==d){
            printf("Found");
            return;
        }
        n=n->next;
    }
    printf("Not Found");
}

void sorted(List* n){
    int temp=n->data;
    while(n!=NULL){
        if(temp<=n->data){
            temp=n->data;
        }
        else{
            printf("Not Sorted");
            return;
        }
        n=n->next;
    }
    printf("Sorted");
}

void pop(List* n){
    while(n->next->next!=NULL){
        n=n->next;
    }
    n->next=NULL;
}

void removeElement(List* n, int d){
    while(n->next->data!=d){
        n=n->next;
    }
    n->next=n->next->next;
}

void main(){
    List* head = NULL;
    List* second = NULL;
    List* third = NULL;

    head = (List*) malloc(sizeof(List));
    second = (List*) malloc(sizeof(List));
    third = (List*) malloc(sizeof(List));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    printList(head);
    printf("\n");

    append(head,1111);
    printList(head);
    printf("\n");

    addToFirst(&head, 0);
    printList(head);
    printf("\n");

    search(head, 1111);
    printf("\n");

    search(head, 11111);
    printf("\n");

    sorted(head);
    printf("\n");

    pop(head);
    printList(head);
    printf("\n");

    removeElement(head, 2);
    printList(head);

}