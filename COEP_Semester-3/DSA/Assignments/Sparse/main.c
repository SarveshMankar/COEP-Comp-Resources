#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int i,j,value;
    struct Node *next;
    struct Node *down;
} Node;

typedef struct Sparse{
    int nrows,ncols;
    Node ** rows;
    Node ** cols;
} Sparse;

void addNode(Sparse *s, int i, int j, int data);
void sparse_init(Sparse *s);


void display(Sparse *s){
	Node * p;
	for(int i = 0; i < s->nrows; i++){
	    p = s->rows[i];
	    while(p!=NULL){
	    	printf("\n%d %d %d",p->i, p->j, p->value);
	    	p = p-> next;
	    }
        printf("\n");
	}
}


void transpose(Sparse **s){
    Sparse s2;
    sparse_init(&s2);

    Node * p;
	for(int i = 0; i < (*s)->nrows; i++){
	    p = (*s)->rows[i];
	    while(p!=NULL){
            addNode(&s2,p->j,p->i,p->value);
	    	p = p-> next;
	    }
	}
    printf("\nTransposed!\n");
    //display(&s2);
    *s = &s2;
}

void addNode(Sparse *s, int i, int j, int data){
    Node *n = (Node*) malloc(sizeof(Node));

    n->i=i;
    n->j=j;
    n->value=data;
    n->down=NULL;
    n->next=NULL;

    Node *n1;
    
    
    if(s->rows[i]==NULL){
        s->rows[i]=n;
    }
    else{
        n1=s->rows[i];
        while(n1->next){
            n1=n1->next;
        }
        n1->next=n;
    }

    if(s->cols[j]==NULL){
        s->cols[j]=n;
    }
    else{
        n1=s->cols[j];
        while(n1->down){
            n1=n1->down;
        }
        n1->down=n;
    }
}

void sparse_init(Sparse *s){
        
        FILE *fptr;
        fptr = fopen("sparseInput.txt","r");
        fscanf(fptr,"%d %d", &s->nrows , &s->ncols);

        s->rows=(Node**) malloc(sizeof(Node*)* s->nrows);
        s->cols=(Node**) malloc(sizeof(Node*)* s->ncols);

        for(int f=0;f<s->nrows;f++){
            s->rows[f]=NULL;
        }

        for(int f=0;f<s->ncols;f++){
            s->cols[f]=NULL;
        }

        int val;
        for (int i1=0;i1<s->nrows;i1++){
            for(int j1=0;j1<s->ncols;j1++){
                fscanf(fptr,"%d",&val);
                if (val!=0){
                    addNode(s,i1,j1,val);
                }
            }
        }
}

void main(){
    Sparse *s;
    sparse_init(s);
    
    display(s);

    transpose(&s);
    display(s);
}