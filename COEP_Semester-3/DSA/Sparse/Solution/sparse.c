#include<stdio.h>
#include<stdlib.h>
#include "sparse.h"

void display(Sparse s){
	Node * p;
	for(int i = 0; i < s.noOfRows; i++){
	    p = s.rows[i];
	    while(p){
	    	printf("%d %d %d\n",p->i, p->j, p->data);
	    	p = p-> next;
	    }
	}
}

void createNewNodeAndAddToOrthagonalMatrix(Sparse *s,int i, int j, int value){
	Node* nn = (Node *) malloc(sizeof(Node));
	if(!nn)
		return ;
		
	nn -> next = NULL;
	nn -> down = NULL;
	nn -> data = value;
	nn -> i = i;
	nn -> j = j;
	
	Node *p;	
	if(s->rows[i] == NULL){
	    s->rows[i] = nn;
	}else if(s->rows[i]-> next == NULL){
	    s->rows[i] -> next = nn;
	}else{
	   p = s-> rows[i];
	   while(p->next){
	   	p = p-> next;
	   } 
	   p -> next = nn;
	}
	
	 if(s -> columns[j] == NULL)
		s->columns[j] = nn;
	else{
	   p = s -> columns[j];
	   while(p -> down){
	   	p = p -> down;
	   }
	   p -> down = nn;
	}
	
	
}

void initSparse(Sparse* s){
	
	FILE *fptr;
	fptr = fopen("sparseInput.txt","r");
	fscanf(fptr,"%d %d", &s->noOfRows , &s->noOfColumns);
	printf("%d %d", s->noOfRows, s->noOfColumns);
	
	s->rows = (Node **) malloc(sizeof(Node*) * s->noOfRows);
	s->columns = (Node **) malloc(sizeof(Node*) * s->noOfColumns);
	
	for(int i = 0; i < s->noOfRows; i++)
		s->rows[i] = NULL;	
		
	for(int i = 0; i < s->noOfColumns; i++)
		s->columns[i] = NULL;
		
	int temp;
	for(int i = 0; i < s->noOfRows; i++){
	   	for(int j = 0; j < s->noOfColumns; j++){	
	   		fscanf(fptr,"%d",&temp);
	   		if(temp != 0){
	   		  createNewNodeAndAddToOrthagonalMatrix(s,i,j,temp);
	   		}
	   	}
	}	
	
	
}

