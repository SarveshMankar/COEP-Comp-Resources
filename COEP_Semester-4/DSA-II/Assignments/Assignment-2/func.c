#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include "func.h"

void initBST(aBST *t){
    t->A=NULL;
    t->s=0;
}

void insertBST(aBST *t, int k){
    if(t->s==0){
        t->A=(int*)malloc(sizeof(int));
        if(!t){
            return;
        }
        t->A[0]=k;
        t->s++;
        return;
    }
    int p=0;
    while (p<t->s && t->A[p]!=INT_MIN)
    {
        if(t->A[p]==k){
            return;
        }
        if(t->A[p]<k){
            p=p*2+2;
        }else{
            p=p*2+1;
        }
        if(p<t->s && (t)->A[p]==INT_MIN){
            t->A[p]=k;
            return;
        }
    }
    t->A=realloc(t->A,(p+1)*sizeof(int));
    if(!t->A){return;}
    for(int i=t->s;i<=p;i++){
        t->A[i]=INT_MIN;
    }
    t->s=p+1;
    t->A[p]=k;
    
}

void inOrder2(aBST *t, int i){
    if(i>=t->s || t->A[i]==INT_MIN){
        return;
    }
    
    inOrder2(t,i*2+1);

    if(t->A[i]!=INT_MIN)
        printf("%d ",t->A[i]);
    
    inOrder2(t,i*2+2);
}

void inOrder(aBST *t){
    inOrder2(t,0);
}

void printABST(aBST *t){
    for(int i=0;i<t->s;i++){
        printf("%d ",t->A[i]);
    }
}

int height(aBST *t){
    int i=t->s;
    int h=0;
    while (i>0){
        i=(i-1)/2;
        h++;
    }
    return h+1;
}

int countLeafNodes(aBST *t){
    int c=0;
    for(int i=0;i<t->s;i++){
        if(t->A[i]!=INT_MIN){
            if((i*2+1>=t->s || t->A[i*2+1]==INT_MIN) && (i*2+2>=t->s || t->A[i*2+2]==INT_MIN)){
                c++;
            }
        }
    }
    return c;
}

int isComplete(aBST *t){
    int c=0;
    for(int i=0;i<t->s;i++){
        if(t->A[i]!=INT_MIN){
            if(t->A[i*2+1]==INT_MIN && t->A[i*2+2]!=INT_MIN){
                return 0;
            }
        }
    }
    return 1;
}

void levelOrder(aBST *t){
    int l=1;
    int p=0;
    int te=0;
    int p1=0;
    int i=0;
    while(t->s>p1){
        if(t->A[p]!=INT_MIN){
            printf("%d ",t->A[p]);
        }
        i++;
        if(i==l){
            printf("\n");
            l=pow(2,te)+1;
            te++;
            i=0;
        }
        p++;
        p1++;
    }
}
