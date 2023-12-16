#include<stdio.h>
#include<stdlib.h>
#include "func.h"


void leftRotate(AVL *t, node *imb){
    node *A = imb;
    node *B = imb->l;
    node *P = A->p;

    node *BR=B->r;

    B->r=A;
    A->l=BR;
    B->p=P;

    if(BR){
        BR->p=A;
    }

    A->p=B;

    A->bf=0;
    B->bf=0;

    if((*t)==A){
        (*t)=B;
        return;
    }

    // printf("\n%d\n",(*t)->data);
    // printf("\n%d\n",(*t)->l->data);
    // printf("\n%d\n",(*t)->r->data);

    // A->l=NULL;
    printf("Here\n");

    if(B->p && B->p->l==A){
        B->p->l=B;
    }else{
        B->p->r=B;
    }

    adjustBF(*t);
    return;
}

void rightRotate(AVL *t, node *imb){
    node *A = imb;
    node *B = imb->r;
    node *P = A->p;

    node *BL=B->l;

    B->l=A;
    A->r=BL;
    B->p=P;

    if(BL){
        BL->p=A;
    }

    A->p=B;

    A->bf=0;
    B->bf=0;

    if((*t)==A){
        (*t)=B;
        adjustBF(*t);
        return;
    }

    // printf("\n%d\n",(*t)->data);
    // printf("\n%d\n",(*t)->l->data);
    // printf("\n%d\n",(*t)->r->data);

    // A->l=NULL;

    if(B->p && B->p->l==A){
        B->p->l=B;
    }else{
        B->p->r=B;
    }
    adjustBF(*t);

}

void leftRightRotate(AVL *t, node *imb){
    rightRotate(t,imb->l);
    // printf("Left Right Rotate\n");
    // printf("-----------------\n");
    // preorder(*t);
    // printf("-----------------\n");
    adjustBF(*t);
    leftRotate(t,imb);
    adjustBF(*t);

}

void rightLeftRotate(AVL *t, node *imb){
    leftRotate(t,imb->r);
    rightRotate(t,imb);
    adjustBF(*t);
}

void insert(AVL *t, int d){
    node *data = (node *)malloc(sizeof(node));
    data->data = d;
    data->l = data->r = data->p = NULL;
    data->bf = 0;

    node *p = *t;
    node *q = NULL;
    while(p){
        q = p;
        if(p->data > d)
            p = p->l;
        else
            p = p->r;
    }

    if(!q)
        (*t) = data;
    else if(q->data > d){
        q->l = data;
        data->p = q;
    }
    else{
        q->r = data;
        data->p = q;
    }

    adjustBF(data->p);
    node * imb = (node *)malloc(sizeof(node));
    imb = imbalanceNode(data->p);

    printf("Inserted %d\n", d);
    if(imb){
        printf("Imbalance node: %d\n" ,imb->data);
    }

    do{
        if(!imb)
            break;
        node *parent = imb->p;

        if(imb && imb->bf==2 && imb->l && imb->l->bf==1){
            leftRotate(t,imb);
        }else if (imb && imb->bf==-2 && imb->r && imb->r->bf==-1){
            rightRotate(t,imb);
        }
        else if (imb && imb->bf==2 && imb->l && imb->l->bf==-1){
            leftRightRotate(t,imb);
        }else if (imb && imb->bf==-2 && imb->r && imb->r->bf==1){
            rightLeftRotate(t,imb);
        }

        adjustBF(parent);
        imb = imbalanceNode(parent);
    }while (imb);
    
    adjustBF(*t);
    printf("--------------\nMain Preoder traversal:\n");
    preorder(*t);
    printf("--------------\n");
}

void adjustBF(AVL t){
    if(!t)
        return;
    int lh = height(t->l);
    int rh = height(t->r);
    t->bf = lh - rh;

    adjustBF(t->p);
}

node *imbalanceNode(AVL t){
    if(!t)
        return NULL;
    if(t->bf > 1 || t->bf < -1)
        return t;
    return imbalanceNode(t->p);
}

int height(AVL t){
    if(!t)
        return 0;
    int lh = height(t->l);
    int rh = height(t->r);
    return (lh > rh ? lh : rh) + 1;
}

void inorder(AVL t){
    if(t){
        inorder(t->l);
        printf("%d -> %d\n", t->data, t->bf);
        inorder(t->r);
    }
}

void preorder(AVL t){
    if(t){
        printf("%d -> %d\n", t->data, t->bf);
        preorder(t->l);
        preorder(t->r);
    }
}