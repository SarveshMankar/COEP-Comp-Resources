#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "func.h"

void initStack(stack *s){
    s->top=NULL;
}

void push(stack *s, node *data){
    stack *t = (stack *)malloc(sizeof(stack));
    t->data=data;
    if(s->top==NULL){
        s->next=NULL;
    }else{
        t->next=s->top;
    }
    s->top=t;
    // printf("\n%d",top->data->data);
}

node *pop(stack *s){
    if(s->top==NULL){
        printf("UnderFlow!");
    }else{
        stack *temp = s->top;
        s->top=s->top->next;
        return temp->data;
        // stack *p=top;
        // stack *tn=p->next;
        // top=p->next;
        // free(p);
        // return tn->data;
    }
}

int isEmptyStack(stack *s){
    if(s->top==NULL){
        return 1;
    }else{
        return 0;
    }
}

stack *destroyStack(stack *s){
    stack *temp=s;
    stack *t;
    while (temp->top){
        t=temp->top->top;
        free(temp->top);
        temp=t;
    }
    free(temp);

    return NULL;    
}



// Queue

void initQueue(Queue *q){
    q->f = NULL;
    q->r = NULL;
    q->count = 0;
    q->size = 100;
}

void enqueue(Queue *Q, node *data) {

    if (Q->count + 1 == Q->size) {
        return ;
    }

    QNode * temp = Q->r;
    
    QNode * qnode = (QNode * ) malloc(sizeof(QNode));
    qnode -> data = data;

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

node *peekFront(Queue *Q) {
    if (Q->count == 0) {
        return NULL;
    }

    return Q->f->data;
}

node *peekRear(Queue *Q) {
    if (Q->count == 0) {
        return NULL;
    }
	
    return Q->r->data;
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

void insertWithoutRecursion(BST *t, int key){
    node *nn = (node *) malloc(sizeof(node));
    nn->data=key;
    nn->right=nn->left=NULL;

    if(!(*t)){
        *t=nn;
        return;
    }

    node *p = *t;
    node *q = NULL;

    while (p!=NULL){
        q=p;

        if(p->data==key){
            return;
        }

        if(p->data>key){
            p=p->left;
        }else if (p->data<key){
            p=p->right;
        }        
    }

    if (q->data>key){
        q->left=nn;
    }else{
        q->right=nn;
    }
}

void preOrderWithRecursion(BST t){
    if(t!=NULL){
		printf("%d\t",t->data);
		preOrderWithRecursion(t->left);
		preOrderWithRecursion(t->right);	
	}
}

void preOrderWithoutRecursion(BST t){    
    node *p=t;

    stack *preOrderStack = (stack *)malloc(sizeof(stack));
    initStack(preOrderStack); 

    if(p==NULL){
        return;
    }
    while (1)
    {
        if(p){
            push(preOrderStack,p);
            printf("%d\t",p->data);
            p=p->left;
        }else{
            if(preOrderStack->top){
                p=pop(preOrderStack);
                p=p->right;
            }else{
                break;
            }
        }
    }  

    preOrderStack=destroyStack(preOrderStack);
    free(preOrderStack);

    return;
}

void inOrderWithRecursion(BST t){
    if(t!=NULL){
		inOrderWithRecursion(t->left);
		printf("%d\t",t->data);
		inOrderWithRecursion(t->right);	
	}
}

void inOrderWithoutRecursion(BST t){
    node *p=t;

    if(p==NULL){
        return;
    }

    stack *inOrderStack = (stack *)malloc(sizeof(stack));
    initStack(inOrderStack); 

    while (1)
    {
        if(p){
            push(inOrderStack,p);
            p=p->left;
        }else{
            if(inOrderStack->top){
                p=pop(inOrderStack);
                printf("%d\t",p->data);
                p=p->right;
            }else{
                break;
            }
        }
    }  

    inOrderStack=destroyStack(inOrderStack);
    free(inOrderStack);

    return;
}

void postOrderWithRecursion(BST t){
    if(t!=NULL){
		postOrderWithRecursion(t->left);
		postOrderWithRecursion(t->right);	
		printf("%d\t",t->data);
	}
}

void postOrderWithoutRecursion(BST t){
    if(t==NULL){
        return;
    }

    node *p=t;

    stack *s1=(stack *)malloc(sizeof(stack));
    stack *s2=(stack *)malloc(sizeof(stack));

    initStack(s1);
    initStack(s2);

    push(s1,p);
    while (!isEmptyStack(s1)){
        p=pop(s1);
        push(s2,p);

        if(p->left){
            push(s1,p->left);
        }
        if(p->right){
            push(s1,p->right);
        }
    }

    while (!isEmptyStack(s2)){
        p=pop(s2);
        printf("%d\t",p->data);
    }    

    return;
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

void levelOrderWithQueue(BST t){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    initQueue(q);

    node *temp = t;
    while (temp){
        printf("%d\t",temp->data);
        if(temp->left){
            enqueue(q,temp->left);
        }
        if(temp->right){
            enqueue(q,temp->right);
        }
        temp=dequeue(q);
    }
    
    return;
}

void diagonalOrderWithQueue(BST t){
    if(!t) return;

    Queue *q = (Queue *)malloc(sizeof(Queue));
    initQueue(q);

    node *temp = t;
    enqueue(q,temp);
    while (!isEmpty(q)){
        temp=dequeue(q);
        while (temp){
            printf("%d\t",temp->data);
            if(temp->left){
                enqueue(q,temp->left);
            }
            temp=temp->right;
        }
    }    
}

int countNodesWithRecursion(BST t){
    if(t==NULL){
        return 0;
    }
    return 1+countNodesWithRecursion(t->left)+countNodesWithRecursion(t->right);
}

int countNodesWithoutRecursion(BST t){
    node *p=t;
    int count=0;

    if(p==NULL){
        return count;
    }

    stack *countNodesStack = (stack *)malloc(sizeof(stack));
    initStack(countNodesStack); 

    while (1)
    {
        if(p){
            push(countNodesStack,p);
            p=p->left;
        }else{
            if(countNodesStack->top){
                p=pop(countNodesStack);
                count++;
                p=p->right;
            }else{
                break;
            }
        }
    }

    countNodesStack=destroyStack(countNodesStack);
    free(countNodesStack);

    return count;
}

int countLeafNodesWithRecursion(BST t){
    if(t==NULL){
        return 0;
    }
    if(t->left==NULL && t->right==NULL){
        return 1;
    }
    return countLeafNodesWithRecursion(t->left)+countLeafNodesWithRecursion(t->right);
}

int countLeafNodesWithoutRecursion(BST t){
    node *p=t;
    int count=0;

    if(p==NULL){
        return count;
    }

    stack *countLeafNodesStack = (stack *)malloc(sizeof(stack));
    initStack(countLeafNodesStack); 

    while (1)
    {
        if(p){
            push(countLeafNodesStack,p);
            p=p->left;
        }else{
            if(countLeafNodesStack->top){
                p=pop(countLeafNodesStack);
                if(p->left==NULL && p->right==NULL){
                    count++;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }

    countLeafNodesStack=destroyStack(countLeafNodesStack);
    free(countLeafNodesStack);

    return count;
}


int countInternalNodesWithRecursion(BST t){
    if (t==NULL || (t->left==NULL && t->right==NULL)){
        return 0;
    }
    return 1+countInternalNodesWithRecursion(t->left)+countInternalNodesWithRecursion(t->right);
}

int countInternalNodesWithoutRecursion(BST t){
    node *p=t;
    int count=0;

    if(p==NULL){
        return count;
    }

    stack *countInternalNodesStack = (stack *)malloc(sizeof(stack));
    initStack(countInternalNodesStack); 

    while (1)
    {
        if(p){
            push(countInternalNodesStack,p);
            p=p->left;
        }else{
            if(countInternalNodesStack->top){
                p=pop(countInternalNodesStack);
                if(p->left==NULL){
                    if(p->right){
                        count++;
                    }
                }else{
                    count++;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }

    countInternalNodesStack=destroyStack(countInternalNodesStack);
    free(countInternalNodesStack);

    return count;
}

int isFullTreeWithRecursion(BST t){
    if(!t){
        return 1;
    }
    if(t->left == NULL && t->right==NULL){
        return 1;
    }
    if(t->left != NULL && t->right!=NULL){
        return isFullTreeWithRecursion(t->left) && isFullTreeWithRecursion(t->right);
    }
    return 0;
}

int isFullTreeWithoutRecursion(BST t){
    node *p=t;
    if(!p){
        return 1;
    }

    stack *isFullStack = (stack *)malloc(sizeof(stack));
    initStack(isFullStack);

    while (1){
        if(p){
            push(isFullStack,p);
            p=p->left;
        }else{
            if (isFullStack->top){
                p=pop(isFullStack);
                if ((p->left && !p->right) || (!p->left && p->right)){
                    return 0;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }

    isFullStack=destroyStack(isFullStack);
    free(isFullStack);

    return 1;
}

int isCompleteTreeWithoutRecursion(BST t){
    node *p=t;
    int flag=0;
    if(!p){
        return 1;
    }

    stack *isCompleteStack = (stack *)malloc(sizeof(stack));
    initStack(isCompleteStack); 

    while (1){
        if(p){
            push(isCompleteStack,p);
            p=p->left;
        }else{
            if(isCompleteStack->top){
                p=pop(isCompleteStack);
                if(!p->left && p->right){
                    if (flag==1){
                        return 0;
                    }
                    flag=1;
                    // return 0;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }
    
}

void insertBT(BST *t, int key){
	if ( (*t) == NULL){
		BST n = (BST) malloc(sizeof(node));
		n->data = key;
		n->left = n->right = NULL;
		*t = n;
	}

	if(rand() % 2 == 0){
		if(!(*t)->left){
			BST n = (BST) malloc(sizeof(node));
			n->data = key;
			n->left = n->right = NULL;
			(*t)->left = n;
			return;
		}

		insertBT(&(*t)->left, key);
	}
	else {
		if(!(*t)->right){
			BST n = (BST) malloc(sizeof(node));
			n->data = key;
			n->left = n->right = NULL;
			(*t)->right = n;
			return;
		}
		insertBT(&(*t)->right, key);
	}
	return;
}

int isBST(BST t){
    node *p=t;
    node *q;

    if(p==NULL){
        return 1;
    }

    stack *isBSTStack = (stack *)malloc(sizeof(stack));
    initStack(isBSTStack); 

    while (1)
    {
        if(p){
            push(isBSTStack,p);
            p=p->left;
            if(isBSTStack->top && p){
                if(p->data>isBSTStack->top->data->data){
                    return 0;
                }
            }
        }else{
            if(isBSTStack->top){
                p=pop(isBSTStack);
                // printf("%d\t",p->data);
                q=p;

                p=p->right;
                if(q && p){
                    if(p->data<q->data){
                        return 0;
                    }
                }
            }else{
                break;
            }
        }
    }  

    isBSTStack=destroyStack(isBSTStack);
    free(isBSTStack);

    return 1;
}

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

// void farLeafNode(BST t){
//     int t1=0;
//     int t2=0;
//     int c=0;
//     treenode *p=t;

//     stack st;
//     initStack(&st);

//     while(1){
//         if(p){
//             push(&st, p);
//             p=p->left;
//             t1++;
//             printf("\nt1=%d\tt2=%d",t1,t2);

//         }
//         else{
//             if(!isStackEmpty(st)){
//                 p=pop(&st);
//                 if(!p->left && !p->right){
//                     if(t1>t2){
//                         // printf("\nt1=%d\tt2=%d",t1,t2);
//                         t2=t1;
//                         c=p->data;
//                     }
//                     printf("\t%d",p->data);
//                     t1--;
//                 }
//                 p=p->right;
//                 printf("\nt1=%d\tt2=%d",t1,t2);
//             }else{
//                 break;
//             }
//         }
//     }
//     printf("\n%d",c); 
// }

void destroyWithRecursion(BST *t){
    if(*t){
        destroyWithRecursion(&(*t)->left);
        destroyWithRecursion(&(*t)->right);
        free(*t);
        *t=NULL;
    }
}

node *destroyWithoutRecursion(BST t){
    if(!t){return NULL;}
    node *p=t;
    node *q;

    stack *destroyTreeStack = (stack *)malloc(sizeof(stack));
    initStack(destroyTreeStack); 
    
    while (1){
        if(p){
            push(destroyTreeStack,p);
            p=p->left;
        }else{
            if(destroyTreeStack->top){
                p=pop(destroyTreeStack);
                q=p->right;
                // printf("%d\t",p->data);
                free(p);
                p=q;
            }else{
                break;
            }
        }
    }

    destroyTreeStack=destroyStack(destroyTreeStack);
    free(destroyTreeStack);

    free(q);
    return NULL;
    
}

int dc=0;
int countLevelNodes(node *t, int curr, int tl){
	if(t == NULL){
        // printf("\nAns:%d\n",dc);
        return dc;
    }
    if(curr == tl){
        dc++;
        // printf("%d=%d\t",t->data,dc);
    }
    countLevelNodes(t->left, curr+1, tl);
    countLevelNodes(t->right, curr+1, tl);
}

int breadthRecusrion(BST t){
    int breadth=0;
    int temp;
    for(int i=0;i<height(t);i++){
        dc=0;
        temp=countLevelNodes(t,0,i);
        if(temp>breadth){
            breadth=temp;
        }
    }
    return breadth;
}

int diameterOfBinaryTree(node* root){
    if (!root){
        return 0;
    }
    int dl=diameterOfBinaryTree(root->left);
    int dr=diameterOfBinaryTree(root->right);
    int cur=height(root->left)+height(root->right);

    int max1;
    if(dl>dr){
        max1=dl;
    }else{
        max1=dr;
    }

    if(max1>cur){
        return max1;
    }else{
        return cur;
    }

}

int D_height(node* t){
    if(t==NULL) return 0;
    int lh=height(t->left);
    int rh=height(t->right);
    int max;
    if(lh>rh){
        max=lh;
    }else{
        max=rh;
    }

    return max+1;
}

node *deleteWithRecursion(BST *t, int key){
    if((*t)==NULL) return *(t);

    node *p=*t;

    if(p->data>key){
        p->left=deleteWithRecursion(&p->left,key);
    }else if(p->data<key){
        p->right=deleteWithRecursion(&p->right,key);
    }else{
        if(!p->left && !p->right){
            free(p);
            return NULL;
        }else if(p->left==NULL){
            node *temp=p->right;
            free(p);
            return temp;
        }else if(p->right==NULL){
            node *temp=p->left;
            free(p);
            return temp;
        }else{
            // node *temp=p->right;
            // while (temp->left){
            //     temp=temp->left;
            // }
            // p->data=temp->data;
            // p->right=deleteWithRecursion(&p->right,temp->data);
            node *temp=p->left;
            while (temp->right){
                temp=temp->right;
            }
            p->data=temp->data;
            p->left=deleteWithRecursion(&p->left,temp->data);
        }
    }
    return p;
}

node *deleteWithoutRecursion(BST *t, int key){
    if(!(*t)) return NULL;

    node *p = (*t);
    node *q = NULL;

    while (p){
        if(p->data==key){
            break;
        }
        q=p;

        if(p->data>key){
            p=p->left;
        }else{
            p=p->right;
        }
    }

    if(!p) return NULL;

    if(p->left==NULL && p->right==NULL){
        if(q->left==p){
            q->left=NULL;
        }else{
            q->right=NULL;
        }
        free(p);
    }else if(p->left==NULL){
        if(q->left==p){
            q->left=p->right;
        }else{
            q->right=p->right;
        }
        free(p);
    }else if(p->right==NULL){
        if(q->left==p){
            q->left=p->left;
        }else{
            q->right=p->left;
        }
        free(p);
    }else{
        node *temp=p->left;
        node *parentForInorderPredecessor=NULL;
        while (temp->right){
            parentForInorderPredecessor=temp;
            temp=temp->right;
        }

        if(!parentForInorderPredecessor){
            p->data=temp->data;
            p->left=temp->left;
        }else{
            p->data=temp->data;
            parentForInorderPredecessor->right=NULL;
        }
        
        free(temp);        
    }

    
}