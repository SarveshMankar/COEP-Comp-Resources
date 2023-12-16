#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int prn;
    char name[50];
    struct node* next;
} Node;

void addNode(Node* n, int pnr, char name[50]){
    Node *n1;
    n1 = (Node*) malloc(sizeof(Node));
    strcpy(n1->name,name);
    n1->prn=pnr;

    while(n->next->next!=NULL){
        n=n->next;
    }

    n1->next=n->next;
    n->next=n1;

}

int countClubMembers(Node* n1){
    int c=0;
    while(n1!=NULL){
        c++;
        n1=n1->next;
    }
    return c;
}

void deleteNode(Node** n, char name[50]){
    if (strcmp((*n)->name,name)==0){
        *n=(*n)->next;
    }
    else{
        Node* temp=*n;
        while(temp->next!=NULL){
            if (strcmp(temp->next->name,name)==0){
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
        }
    }
}

void printPresidentName(Node* n){
    printf("President: %s\n",n->name);
}

void printSecretaryName(Node* n){
    while(n->next!=NULL){
        n=n->next;
    }
    printf("Secretary: %s\n",n->name);
}

void printList(Node* n){
    printf("----------------\n");
    while(n!=NULL){
        printf("%s\n",n->name);
        n=n->next;
    }
}

void main(){
    Node *n1,*n2;
    char data[50];
    int prn;

    n1 = (Node *) malloc(sizeof(Node));
    strcpy(n1->name,"President");
    n1->next=NULL;

    n2 = (Node *) malloc(sizeof(Node));
    strcpy(n2->name,"Secretary");
    n2->next=NULL;

    n1->next=n2;

    printList(n1);

    strcpy(data,"Name1");
    prn=1;
    addNode(n1,prn,data);
    printList(n1);

    strcpy(data,"Name2");
    prn=2;
    addNode(n1,prn,data);
    printList(n1);
    printf("\nTotal number of members in club: %d\n",countClubMembers(n1));

    printPresidentName(n1);
    printSecretaryName(n1);

    deleteNode(&n1,"President");
    printList(n1);
    printPresidentName(n1);
    printSecretaryName(n1);
}
