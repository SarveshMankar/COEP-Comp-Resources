#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"

void initAVL(AVL *t){
    *t = NULL;
}

void insertNode(AVL *t, char name[]){
    if((*t) == NULL){
        (*t) = (AVL)malloc(sizeof(struct node));
        strcpy((*t)->name, name);
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->parent = NULL;    
        return;
    }

    node *parent = NULL;
    node *temp = (*t);

    while(temp){
        parent = temp;
        if(strcmp(name, temp->name) < 0){
            temp = temp->left;
        }else if(strcmp(name, temp->name) > 0){
            temp = temp->right;
        }else if(strcmp(name, temp->name) == 0){
            printf("Duplicate name found!\n");
            return;
        }
        if(temp == NULL){
            break;
        }
    }

    node *nn = (node *)malloc(sizeof(node));
    strcpy(nn->name, name);
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = parent;

    // (*t) = parent;

    if(strcmp(name, parent->name) < 0){
        parent->left = nn;
    }else{
        parent->right = nn;
    }

    adjustBF(nn->parent);
    node * imb = (node *)malloc(sizeof(node));
    imb = imbalanceNode(nn->parent);

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

        adjustBF(parent);
        imb = imbalanceNode(parent);
    }while (imb);
    
    adjustBF(parent->parent); //Just for precaution :)
    // printf("--------------\nMain traversal:\n");
    // traverse(*t);
    // printf("--------------\n");
}

node *removeNode(AVL *t, char name[]){
    if (*t == NULL)
        return *t;

    node *temp = *t;

    node *p,*q;
    p=*t;
    q=NULL;
    while(p!=NULL){
        if(strcmp(name,p->name)==0){
            break;
        }
        q=p;
        if(strcmp(name,p->name)<0){
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
        // free(p);
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
        // free(p);
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

        strcpy(p->name,r->name);

        removeNode(&(p->left),r->name);

        // printf("\nDeleting==========\n");
        // traverse(*t);

        }

        // node *successor = inOrderSuccessor(p);
        // printf("%s\n",q->name);
        // printf("%s\n",successor->name);
        // if(q->left==p){
        //     q->left=successor;
        //     successor->parent=q;
        // }else if (q->right==p){
        //     q->right=successor;
        //     successor->parent=q;
        // }
        // successor->parent->left=NULL;
    // }

    // printf("\n==========\n");
    // traverse(t);

    if (p->left){
        adjustBF(p->left);
    }
    if (p->right){
        adjustBF(p->right);
    }
    
    node * imb = (node *)malloc(sizeof(node));
    imb = imbalanceNode(p);

    // printf("\nImbalaced Data:- %s",imb->name);
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
    
    // adjustBF(imb->parent);

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

void leftRotate(AVL *t, node *imb){
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

void rightRotate(AVL *t, node *imb){
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
    printf("%s\t%d\n", t->name, t->balance);
    // if(t->parent){
    //     printf("%s\t%d\n", t->parent->name, t->parent->balance);
    // }
    traverse(t->left);
    traverse(t->right);
}