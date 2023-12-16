#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} node;

void add(node **head, int data){
	node *last = *head;

	node *n = (node *)malloc(sizeof(node));
	n->data=data;
	n->next=NULL;

	if (!*head){
		printf("Adding at the Start!\n");
		*head=n;
	}else{
		while(last->next!=NULL){
			last = last->next;
		}
		last->next = n;
	}
}

//Add to Start
void addToStart(node **head, int data){
	node *n = (node *) malloc(sizeof(node));
	n->data=data;
	n->next=*head;

	*head = n;
}

void reverse(node **head){
	node *curr = *head;
	node *prev = NULL;
	node *next = NULL;

	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
}

void deleteNodeAtPosition(node *head, int pos){
	int i=0;
	while(i==pos-1){
		head=head->next;
	}
	node *n = head->next;
	printf("Deleted: %d ",n->data);
	head->next=head->next->next;
	free(n);
}

void deleteNodeByData(node *head, int data){
	node *n = head;
	while(n->next->data!=data){
		n=n->next;
	}
	printf("Current: %d",n->next->data);
	node *temp = n->next;
	n->next=n->next->next;
	free(temp);
}

void display(node *head){
	printf("\n");
	if (!head){
		printf("\nThe List is Empty!\n");
	}else{
		while(head!=NULL){
			printf("%d\t",head->data);
			head=head->next;
		}
	}
	printf("\n");

}

void main(){
	node *head = (node *) malloc(sizeof(node));
	head = NULL;
	add(&head,10);
	add(&head,20);
	add(&head,30);
	add(&head,40);
	add(&head,50);
	
	addToStart(&head,0);
	display(head);

	deleteNodeAtPosition(head,2);
	display(head);	
	deleteNodeByData(head,40);
	display(head);

	//printf("\nReversing The Lsit:\n");
	//reverse(&head);
	//display(head);
	
	
}