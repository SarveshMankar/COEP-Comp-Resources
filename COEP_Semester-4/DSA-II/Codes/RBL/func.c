#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "func.h"

//Black = 0
//Red = 1

void initRBL(RBL *t){
    *t = NULL;
}

void insertNode(RBL *t, int data){
    node *nn = (node*)malloc(sizeof(node));
    nn->data=data;
    nn->left=nn->right=NULL;
    nn->parent=NULL;
    nn->balance=0;
    nn->color=1;
    
    if(!(*t)){
        (*t)=nn;
        nn->color=0;
        return;
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

    if(p->color==1){
        //check for uncle
        node *uncle=(node *)malloc(sizeof(node));

        if(p->left && p->left->data==data){
            uncle=p->parent->right;
        }else{
            uncle=p->parent->right;
            printf("\nUncle: %d\n",uncle->data);
            printf("Uncle Color: %d\n",uncle->color);
        }

        if(!uncle || uncle->color==0){

        }else if (uncle->color==1){
            node *tp=nn;
            while(tp){
                if(tp->color==0){
                    tp->color=1;
                    printf("\nChanged to Red");
                }else{
                    tp->color=0;
                    printf("\nChanged to Black");
                }
                tp=tp->parent;
                printf("\nOk1");
            }
            node *tu=nn;
            while(tu){
                if(tu->color==0){
                    tu->color=1;
                }else{
                    tu->color=0;
                }
                tu=tu->parent;
            }
            // p->color=0;
            // uncle->color=0;
            // p->parent->color=1;
        }
    }

    node *q = nn->parent;
    while (q){
        adjustBF(q);
        q=q->parent;
    }

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

node *removeNode(RBL *t, int data){
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

node *tempRemoveNode(RBL *t, int data){
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

node *inOrderSuccessor(RBL t){
    if(!t)
        return NULL;
    node *temp = t->right;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

void adjustBF(RBL t){
    if(!t)
        return;
    int lh = height(t->left);
    int rh = height(t->right);
    t->balance = lh - rh;

    adjustBF(t->parent);
}

node *imbalanceNode(RBL t){
    if(!t)
        return NULL;
    if(t->balance > 1 || t->balance < -1)
        return t;
    return imbalanceNode(t->parent);
}

int height(RBL t){
    if(!t)
        return 0;
    int lh = 0;
    int rh = 0;
    if (t->left){
        lh = height(t->left);
    }
    if (t->right){
        rh = height(t->right);
    }
    return (lh > rh ? lh : rh) + 1;
}

void leftRotate(RBL *t, node *imb){
    node *A = imb;
    node *B = imb->left;
    node *P = A->parent;

    node *BR=B->right;

    B->right=A;
    A->left=BR;
    B->parent=P;

    if(BR){
        BR->parent=A;
    }

    A->parent=B;

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

void rightRotate(RBL *t, node *imb){
    node *A = imb;
    node *B = imb->right;
    node *P = A->parent;

    node *BL=B->left;

    B->left=A;
    A->right=BL;
    B->parent=P;

    if(BL){
        BL->parent=A;
    }

    A->parent=B;

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

void leftRightRotate(RBL *t, node *imb){
    rightRotate(t,imb->left);
    adjustBF(imb->parent);
    leftRotate(t,imb);
    adjustBF(imb->parent);
}

void rightLeftRotate(RBL *t, node *imb){
    leftRotate(t,imb->right);
    adjustBF(imb->parent);
    rightRotate(t,imb);
    adjustBF(imb->parent);
}

void destroyRBL(RBL t){
    if(t == NULL){
        return;
    }

    destroyRBL(t->left);
    destroyRBL(t->right);
    free(t);
}

void traverse(RBL t){
    if(t == NULL){
        return;
    }
    printf("%d\t%d\t", t->data, t->balance);
    if(t->color==0){
        printf("Black");
    }else{
        printf("Red");
    }

    printf("\n");
    
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