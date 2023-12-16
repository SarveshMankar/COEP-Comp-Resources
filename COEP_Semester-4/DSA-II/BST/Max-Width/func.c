#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "func.h"


// Queue

void initQueue(Queue *q){
    q->f = NULL;
    q->r = NULL;
    q->count = 0;
    q->size = 100;
}

void enqueue(Queue *Q, node *data, int index) {

    if (Q->count + 1 == Q->size) {
        return ;
    }

    QNode * temp = Q->r;
    
    QNode * qnode = (QNode * ) malloc(sizeof(QNode));
    qnode -> data = data;
    qnode -> index = index;

    if (Q->count == 0) {
        Q->f = qnode;
        Q->r = qnode;
    } else {
        temp -> next = qnode;
    }

    Q->r = qnode;
    Q->count++;

}

int isEmpty(Queue *Q) {
    return Q->count == 0;
}

int isFull(Queue *Q) {
    return Q->size == Q->count;
}

node *dequeue(Queue *Q) {

    if (Q->count == 0) {
        return NULL;
    }

    node *ret = Q->f->data;
    QNode * temp = Q->f;
    Q->f = Q->f -> next;
    free(temp);

    Q->count--;

    return ret;
}

QNode *peekFront(Queue *Q) {
    if (Q->count == 0) {
        return NULL;
    }

    return Q->f;
}

QNode *peekRear(Queue *Q) {
    if (Q->count == 0) {
        return NULL;
    }
	
    return Q->r;
}





void initBST(BST *t){
    *t = NULL;
}

void insertWithRecursion(BST *t, int key){
    if((*t)==NULL){
        node *nn = (node *)malloc(sizeof(node));
        nn->data=key;
        nn->left=nn->right=NULL;
        *t=nn;
    }else if((*t)->data==key){
        return;
    }else if((*t)->data>key){
        insertWithRecursion(&(*t)->left,key);
    }else if((*t)->data<key){
        insertWithRecursion(&(*t)->right,key);
    }
}

void preOrderWithRecursion(BST t){
    if(t!=NULL){
		printf("%d\t",t->data);
		preOrderWithRecursion(t->left);
		preOrderWithRecursion(t->right);	
	}
}

void inOrderWithRecursion(BST t){
    if(t!=NULL){
		inOrderWithRecursion(t->left);
		printf("%d\t",t->data);
		inOrderWithRecursion(t->right);	
	}
}

void postOrderWithRecursion(BST t){
    if(t!=NULL){
		postOrderWithRecursion(t->left);
		postOrderWithRecursion(t->right);	
		printf("%d\t",t->data);
	}
}

void displayLevel(BST t, int curr, int level){
    if(t==NULL){
        return;
    }
    if(curr==level){
        printf("%d\t",t->data);
    }
    displayLevel(t->left,curr+1,level);
    displayLevel(t->right,curr+1,level);
}

void levelOrderWithRecursion(BST t){
    int depth=height(t);
    for(int i=0;i<depth;i++){
        displayLevel(t,0,i);
        printf("\n");
    }
}

// void levelOrderWithQueue(BST t){
//     Queue *q = (Queue *)malloc(sizeof(Queue));
//     initQueue(q);

//     node *temp = t;
//     while (temp){
//         printf("%d\t",temp->data);
//         if(temp->left){
//             enqueue(q,temp->left);
//         }
//         if(temp->right){
//             enqueue(q,temp->right);
//         }
//         temp=dequeue(q);
//     }
    
//     return;
// }

int height(BST t){
    if(!t){
        return 0;
    }else{
        int l=height(t->left);
        int r=height(t->right);

        if(l>r){
            return l+1;
        }else{
            return r+1;
        }
    }
}

int maxWidth(BST t){
    if(!t) return 0;

    int ans=0;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    initQueue(q);

    enqueue(q,t,0);
    while(!isEmpty(q)){
        int size=q->count;
        QNode *temp = peekFront(q);
        int min=temp->index;
        int first, last;

        for(int i=0; i<size;i++){
            temp=peekFront(q);
            int curr_index = temp->index-min;

            node *treeNode = dequeue(q);
            if(i==0){
                first=curr_index;
            }
            if(i==size-1){
                last=curr_index;
            }
            if(treeNode->left){
                enqueue(q,treeNode->left,2*curr_index+1);
                temp=peekFront(q);
                int curr_index = temp->index;
            }
            if(treeNode->right){
                enqueue(q,treeNode->right,2*curr_index+2);
            }
        }
        int width = last - first + 1;
        if(width>ans){
            ans=width;
        }
    }

    return ans;
}