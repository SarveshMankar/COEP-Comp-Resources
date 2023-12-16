#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void init(heap *h){
    h->A=NULL;
    h->s=100;
    h->c=0;
}

void insert(heap *h, int data){    
    h->A=realloc(h->A,(h->c+1)*sizeof(int));
    if(!h->A){
        return;
    }
    h->c++;
    h->A[h->c]=data;

    heapify(h);
    
    return;
}

void delete(heap *h){
    int data = h->A[0];
    int flag=0;
    int i=0;
    for(i; i<h->c+1;i++){
        if(h->A[i]==data){
            flag=1;
            break;
        }
    }

    if(flag){
        swap(&h->A[i],&h->A[h->c]);
        h->c--;
        heapifydel(h);
    }
    return;
}

void heapify(heap *h){
    int i=h->c;
    while(i>0 && h->A[i]>h->A[(i-1)/2]){
        swap(&h->A[i],&h->A[(i-1)/2]);
        i=(i-1)/2;
    }
}

void heapifydel(heap *h){
    int i=0;
    int c=0;
    int max=0;
    int imax=0;
    while (i<h->c)
    {
        c++;
        if(2*i+1>h->c-1){
            break;
        }
        if(h->A[2*i+1]>h->A[2*i+2]){
            imax=2*i+1;
        }else{
            imax=2*i+2;
        }

        if(h->A[i]<h->A[imax]){
            swap(&h->A[i],&h->A[imax]);
            i=imax;
        }else{
            break;
        }
    }
    
}

void display(heap *h){
    for(int i=0;i<=h->c;i++){
        printf("%d ",h->A[i]);
    }
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}