#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} List;

// Display all the elements of the list
void printList(List *n)
{   printf("Hey");
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}

void addToFirst(List** head, int d){
    List* newNode = (List*) malloc(sizeof(List));
    newNode->data=d;
    newNode->next=*head;
    *head=newNode;
}

void append(List* n, int d){
    List* newNode = (List*) malloc(sizeof(List));
    newNode->data=d;
    newNode->next=NULL;

    //If List in empty
    if(n==NULL){
        addToFirst(&n,d);
        //n=newNode;
        return;
    }
    n->next=NULL;

    while(n->next!=NULL){
        n=n->next;
    }

    n->next=newNode;

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
    int t=n->data;
    while(n->next->next!=NULL){
        if (t>n->next->data){
            printf("Not Sorted!");
            return;
        }else{
            n=n->next;
        }
    }
    printf("Sorted!");
}

void pop(List* n){
    while(n->next->next!=NULL){
        n=n->next;
    }
    free(n->next);
    n->next=NULL;
}

void removeElement(List* n, int d){
    while(n->next->data!=d){
        n=n->next;
    }
    n->next=n->next->next;
}

void destroy(List **n){
    /*List* temp = (List*) malloc(sizeof(List));
    temp->next=n->next;
    while(n!=NULL){
        free(n);
        n=temp->next;
        temp->next=n->next;
    }*/
    List* curr = *n;
    List* next;
    while (curr!=NULL)
    {
        next=curr->next;
        free(curr);
        curr=next;
    }
    *n=NULL;
    
}

int main(){
    List* head = NULL;
    List* second = NULL;
    List* third = NULL;

    head = (List*) malloc(sizeof(List));
    second = (List*) malloc(sizeof(List));
    third = (List*) malloc(sizeof(List));

    append(head,1111);

    
    head->data=109;
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
    printf("\n");

    destroy(&head);
    printList(head);
    printf("\n");

    return 0;
}
