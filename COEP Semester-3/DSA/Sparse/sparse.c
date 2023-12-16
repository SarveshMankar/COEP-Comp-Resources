#include<stdio.h>
#include<stdlib.h>
#include "sparse.h"

void addNote(Sparse *s, int i, int j, int val){
    Node* n1 = (Node*) malloc(sizeof(Node));
    n1->i=i;
    n1->j=j;
    n1->value=val;
    n1->down=NULL;
    n1->next=NULL;

    Node *p;
    if (s->rows[i]==NULL){
        s->rows[i]=n1;
    }else{
        p=s->rows[i];
        while (p->next)
        {
            p=p->next;
        }
        p->next=n1;
        
    }
}

void sparse_init(Sparse *s){
        
        FILE *fptr;
        fptr = fopen("sparseInput.txt","r");
        fscanf(fptr,"%d %d", &s->nrows , &s->ncols);
        printf("%d %d",s->nrows,s->nrows);

        s->rows=(Node**) malloc(sizeof(Node*)* s->nrows);
        s->cols=(Node**) malloc(sizeof(Node*)* s->ncols);

        for(int f=0;f<s->nrows;f++){
            s->rows[f]=NULL;
        }

        for(int f=0;f<s->nrows;f++){
            s->rows[f]=NULL;
        }
}