#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "func.h"

void initAVL(AVL *t){
    *t = NULL;
}

void insertNode(AVL *t, int data){
    node *nn = (node*)malloc(sizeof(node));
    nn->data=data;
    nn->left=nn->right=NULL;
    nn->parent=NULL;
    nn->balance=0;
    
    if(!(*t)){
        (*t)=nn;   
    }

    node *temp=(*t);
    node *p=NULL;

    while (temp){
        p=temp;
        if(temp->data>data){
            temp=temp->left;
        }else if (temp->data<data){
            temp=temp->right;
        }else{
            return;
        }
    }

    if(p->data>data){
        p->left=nn;
    }else{
        p->right=nn;
    }
    nn->parent=p;

    node *q = nn->parent;
    adjustBF(q);

    // while (q){
        // adjustBF(q);
        // q=q->parent;
    // }

    node *imb=(node *)malloc(sizeof(node));
    imb=imbalanceNode(nn->parent);

    do{
        if(!imb) break;
        node *parent=imb->parent;
        if(imb->balance==2 && imb->left && imb->left->balance==1){
            leftRotate(t,imb);
        }else if (imb->balance==2 && imb->left->balance==-1){
            leftRightRotate(t,imb);
        }else if(imb->balance==-2 && imb->right->balance==1){
            rightLeftRotate(t,imb);
        }else if(imb->balance==-2 && imb->right->balance==-1){
            rightRotate(t,imb);
        }
        
        adjustBF(parent);

        imb=imbalanceNode(parent);

    }while (imb);

    return;    
}

node *removeNode(AVL *t, int data){
    if (*t == NULL)
        return *t;

    node *temp=*t;
    node *p=NULL;

    while (t){
        if(temp->data==data) break;

        p=temp;
        if(temp->data>data){
            temp=temp->left;
        }else if (temp->data<data){
            temp=temp->right;
        }
    }

    printf("\np->data= %d\n",p->data);
    printf("\ntemp->data= %d\n",temp->data);
    
    if(!temp) return NULL;

    if(!temp->left && !temp->right){
        if(p->left && p->left->data==data){
            p->left=NULL;
        }else{
            p->right=NULL;
        }

    }else if (temp->left && !temp->right){
        if(p->left->data==data){
            p->left=temp->left;
        }else{
            p->right=temp->left;
        }
    }else if (temp->right && !temp->left){
        if(p->left->data==data){
            p->left=temp->right;
        }else{
            p->right=temp->right;
        }
    }else{
        node *r;
        r=p->left;
        while (r->right){
            r=r->right;
        }

        temp->data=r->data;
        removeNode(&temp->left,r->data);
        
    }
    
    adjustBF(p);
    // printf("\nTemp Remove Code: \n");
    // traverse(*t);

    node *imb=(node *)malloc(sizeof(node));
    imb=imbalanceNode(p);

    do{
        if(!imb) break;
        node *parent=imb->parent;
        if(imb->balance==2 && imb->left && imb->left->balance==1){
            leftRotate(t,imb);
        }else if (imb->balance==2 && imb->left->balance==-1){
            leftRightRotate(t,imb);
        }else if(imb->balance==-2 && imb->right->balance==1){
            rightLeftRotate(t,imb);
        }else if(imb->balance==-2 && imb->right->balance==-1){
            rightRotate(t,imb);
        }
        
        adjustBF(parent);

        imb=imbalanceNode(parent);

    }while (imb);

    // printf("\n------------\n");
    // traverse(*t);
    return temp;
}

node *tempRemoveNode(AVL *t, int data){
    printf("\nTemp Remove Code: \n");
    traverse(*t);
    if (*t == NULL)
        return *t;

    node *temp = *t;

    node *p,*q;
    p=*t;
    q=NULL;
    while(p!=NULL){
        if(data==p->data){
            break;
        }
        q=p;
        if(data<p->data){
            p=p->left;
        }else{
            p=p->right;
        }
    }

    if(!p){
        return NULL;
    }
    if(!p->left && !p->right){
        // printf("Parent: %s\n",q->name);
        if(q){
            if(q->left==p){
                q->left=NULL;
            }else{
                q->right=NULL;
            }
        }else{
            *t=NULL;
        }
    }else if(p->left && !p->right){
        if(q){
            if(q->left==p){
                q->left=p->left;
            }else{
                q->right=p->left;
            }
            p->left->parent=q;
        }else{
            *t=p->left;
        }
    }else if(!p->left && p->right){
        if(q){
            if(q->left==p){
                q->left=p->right;
            }else{
                q->right=p->right;
            }
            p->right->parent=q;
        }else{
            *t=p->right;
        }
        // free(p);
    }else{
        node *r;
        r=p->left;
        while (r->right){
            r=r->right;
        }

        p->data=r->data;

        removeNode(&(p->left),r->data);
    }

    if (p->left){
        adjustBF(*t);
    }
    if (p->right){
        adjustBF(*t);
    }

    printf("\nTemp Remove Code: \n");
    traverse(*t);
    
    node * imb = (node *)malloc(sizeof(node));
    imb = imbalanceNode(p);

    do{
        if(!imb)
            break;
        node *parent = imb->parent;

        if(imb && imb->balance==2 && imb->left && imb->left->balance==1){
            leftRotate(t,imb);
        }else if (imb && imb->balance==-2 && imb->right && imb->right->balance==-1){
            rightRotate(t,imb);
        }
        else if (imb && imb->balance==2 && imb->left && imb->left->balance==-1){
            leftRightRotate(t,imb);
        }else if (imb && imb->balance==-2 && imb->right && imb->right->balance==1){
            rightLeftRotate(t,imb);
        }

        adjustBF(imb->parent);
        imb = imbalanceNode(parent);
    }while (imb);
    
    return temp;
}

node *inOrderSuccessor(AVL t){
    if(!t)
        return NULL;
    node *temp = t->right;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

void adjustBF(AVL t){
    if(!t)
        return;
    int lh = height(t->left);
    int rh = height(t->right);
    t->balance = lh - rh;

    adjustBF(t->parent);
}

node *imbalanceNode(AVL t){
    if(!t)
        return NULL;
    if(t->balance > 1 || t->balance < -1)
        return t;
    return imbalanceNode(t->parent);
}

int height(AVL t){
    if(!t)
        return 0;
    int lh = height(t->left);
    int rh = height(t->right);

    return (lh > rh ? lh : rh) + 1;
}

void leftRotate(AVL *t, node *imb){
    node *A = imb;
    node *B = imb->left;
    node *P = A->parent;

    node *BR=B->right;

    B->right=A;
    A->parent=B;

    B->parent=P;

    A->left=BR;
    if(BR){
        BR->parent=A;
    }


    A->balance=0;
    B->balance=0;

    if((*t)==A){
        (*t)=B;
        return;
    }

    if(B->parent && B->parent->left==A){
        B->parent->left=B;
    }else{
        B->parent->right=B;
    }

    adjustBF(imb->parent);
    return;
}

void rightRotate(AVL *t, node *imb){
    node *A = imb;
    node *B = imb->right;
    node *P = A->parent;

    node *BL=B->left;

    B->left=A;
    A->parent=B;
    B->parent=P;

    A->right=BL;

    if(BL){
        BL->parent=A;
    }

    A->balance=0;
    B->balance=0;

    if((*t)==A){
        (*t)=B;
        return;
    }

    if(B->parent && B->parent->left==A){
        B->parent->left=B;
    }else{
        B->parent->right=B;
    }

}

void leftRightRotate(AVL *t, node *imb){
    rightRotate(t,imb->left);
    adjustBF(imb->parent);
    leftRotate(t,imb);
    adjustBF(imb->parent);
}

void rightLeftRotate(AVL *t, node *imb){
    leftRotate(t,imb->right);
    adjustBF(imb->parent);
    rightRotate(t,imb);
    adjustBF(imb->parent);
}

void destroyAVL(AVL t){
    if(t == NULL){
        return;
    }

    destroyAVL(t->left);
    destroyAVL(t->right);
    free(t);
}

void traverse(AVL t){
    if(t == NULL){
        return;
    }
    printf("%d\t%d\n", t->data, t->balance);
    // if(t->parent){
    //     printf("%s\t%d\n", t->parent->name, t->parent->balance);
    // }
    traverse(t->left);
    traverse(t->right);
}

void inorder(node *t){
    if(!t){
        return;
    }
    inorder(t->left);
    printf("\n%d",t->data);
    inorder(t->right);
}

void preorder(node *t){
    if(!t){
        return;
    }
    printf("\n%d",t->data);
    preorder(t->left);
    preorder(t->right);
}