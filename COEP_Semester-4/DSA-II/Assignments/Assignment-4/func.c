#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void init(heap *h){
    h->A=(int *)malloc(sizeof(int));
    h->s=100;
    h->c=-1;
}

void display(heap h){
    for(int i=0;i<=h.c;i++){
        printf("%d ",h.A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}



void maxheap_insert(heap *h, int data){
    if(h->c==-1){
        h->A=realloc(h->A,sizeof(int));
    }else{
        h->A=realloc(h->A,(h->c+2)*sizeof(int));
    }

    if(!h->A){
        return;
    }
    h->c++;
    h->A[h->c]=data;

    maxheap_heapify(h);
    
    return;
}

void maxheap_heapify(heap *h){
    int i=h->c;
    while(i>0 && h->A[i]>h->A[(i-1)/2]){
        swap(&h->A[i],&h->A[(i-1)/2]);
        i=(i-1)/2;
    }
}

void maxheap_delete(heap *h){
    if(h->c<=0){
        h->c=-1;
        return;
    }

    int data = h->A[0];

    swap(&h->A[0],&h->A[h->c]);
    // printf("After Swapping!\t");
    // display(*h);
    h->c--;
    maxheap_heapifydel(h);

    return;
}

void maxheap_heapifydel(heap *h){
    int i=0;
    int imax=0;
    while (i<h->c)
    {
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
    if(h->A[0]<h->A[1]){
        swap(&h->A[0],&h->A[1]);
    }
}

void maxheap_ascendingSortUsingHeap(heap *h){
    int nodes=h->c+1;
    int index=h->c;
    
    int flag=0;

    for(int i=0;i<nodes-1;i++){
        if(h->A[i]>h->A[i+1]){
            flag=1;
            break;
        }
    }

    if(flag==0){
        return;
    }

    for(int j=0; j<nodes; j++){
        int i=0;
        
        swap(&h->A[i],&h->A[index]);
        index--;

        maxheap_heapifySort(h, index);
    }

    if(h->A[0] > h->A[1])
        swap(&h->A[0], &h->A[1]);
    return;
}

void maxheap_descendingSortUsingHeap(heap *h){
    int flag=0;
    int nodes=h->c-1;
    for(int i=0;i<nodes;i++){
        if(h->A[i]<h->A[i+1]){
            flag=1;
            break;
        }
    }

    if(flag==0){
        return;
    }

    int *temp=(int*)malloc(sizeof(int*)*h->c);
    if(!temp){
        return;
    }

    maxheap_ascendingSortUsingHeap(h);

    int n=h->c;
    for(int j=0; j<h->c+1;j++){
        temp[j]=h->A[n-j];
    }

    h->A=temp;
    return;
}

void maxheap_heapifySort(heap *h, int index){
    int i=0;
    int imax=0;
    while (i<index+1){
        if(2*i+1>index-1){
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



void minheap_insert(heap *h, int data){
    if(h->c==-1){
        h->A=realloc(h->A,(h->c+2)*sizeof(int));
    }else{
        h->A=realloc(h->A,(h->c+2)*sizeof(int));
    }

    if(!h->A){
        return;
    }
    h->c++;
    h->A[h->c]=data;

    minheap_heapify(h);
    
    return;
}

void minheap_heapify(heap *h){
    int i=h->c;
    while(i>0 && h->A[i]<h->A[(i-1)/2]){
        swap(&h->A[i],&h->A[(i-1)/2]);
        i=(i-1)/2;
    }
}


void minheap_delete(heap *h){
    if(h->c<=0){
        h->c=-1;
        return;
    }

    int data = h->A[0];

    swap(&h->A[0],&h->A[h->c]);
    h->c--;
    minheap_heapifydel(h);

    return;
}

void minheap_heapifydel(heap *h){
    int i=0;
    int imin=0;
    while (i<h->c)
    {
        if(2*i+1>h->c-1){
            break;
        }
        if(h->A[2*i+1]<h->A[2*i+2]){
            imin=2*i+1;
        }else{
            imin=2*i+2;
        }

        if(h->A[i]>h->A[imin]){
            swap(&h->A[i],&h->A[imin]);
            i=imin;
        }else{
            break;
        }
    }
    if(h->A[0]>h->A[1]){
        swap(&h->A[0],&h->A[1]);
    }
}

void minheap_descendingSortUsingHeap(heap *h){
    int nodes=h->c+1;
    int index=h->c;

    int flag=0;
    int n=h->c-1;
    for(int i=0;i<n;i++){
        if(h->A[i]<h->A[i+1]){
            flag=1;
            break;
        }
    }

    if(flag==0){
        return;
    }

    for(int j=0; j<nodes; j++){
        int data = h->A[0];
        int i=0;
        
        swap(&h->A[i],&h->A[index]);
        index--;

        minheap_heapifySort(h, index);
    }

    if(h->A[0] < h->A[1])
        swap(&h->A[0], &h->A[1]);
    return;
}

void minheap_ascendingSortUsingHeap(heap *h){
    int nodes=h->c+1;

    int flag=0;
    int n1=h->c-1;
    for(int i=0;i<n1;i++){
        if(h->A[i]>h->A[i+1]){
            flag=1;
            break;
        }
    }

    if(flag==0){
        return;
    }

    int *temp=(int*)malloc(sizeof(int*)*h->c);
    if(!temp){
        return;
    }    

    minheap_descendingSortUsingHeap(h);

    int n=h->c;
    for(int j=0; j<h->c+1;j++){
        temp[j]=h->A[n-j];
    }

    h->A=temp;
    return;
}

void minheap_heapifySort(heap *h, int index){
    int i=0;
    int imin=0;
    while (i<index+1){
        if(2*i+1>index-1){
            break;
        }
        if(h->A[2*i+1]<h->A[2*i+2]){
            imin=2*i+1;
        }else{
            imin=2*i+2;
        }

        if(h->A[i]>h->A[imin]){
            swap(&h->A[i],&h->A[imin]);
            i=imin;
        }else{
            break;
        }
    }
}
