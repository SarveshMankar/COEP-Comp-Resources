#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;


typedef node* BST;

typedef struct stack{
    node *data;
    struct stack *next;
}stack;

stack* top = NULL;

// void initStack(stack **s);
void push(node *data);
node *pop();

void initBST(BST *t);
void insertWithRecursion(BST *t, int key);
void insertWithoutRecursion(BST *t, int key);
void insertBT(BST *t, int key);

void inOrderWithRecursion(BST t);
void inOrderWithoutRecursion(BST t);

void preOrderWithRecursion(BST t);
void preOrderWithoutRecursion(BST t);

void postOrderWithRecursion(BST t);
void postOrderWithoutRecursion(BST t);

int countNodesWithRecursion(BST t);
int countNodesWithoutRecursion(BST t);

int countLeafNodesWithRecursion(BST t);
int countLeafNodesWithoutRecursion(BST t);

int countInternalNodesWithRecursion(BST t);
int countInternalNodesWithoutRecursion(BST t);

int isFullTreeWithRecursion(BST t);
int isFullTreeWithoutRecursion(BST t);

int isCompleteTreeWithoutRecursion(BST t);

int isBST(BST t);

int height(BST t);

void destroyWithRecursion(BST *t);
node *destroyWithoutRecursion(BST t);

int countLevelNodes(node *t, int curr, int tl);
int breadthRecusrion(BST t);

void push(node *data){
    stack *s = (stack *)malloc(sizeof(stack));
    s->data=data;
    if(top==NULL){
        s->next=NULL;
    }else{
        s->next=top;
    }
    top=s;
    // printf("\n%d",top->data->data);
}

node *pop(){
    if(top==NULL){
        printf("UnderFlow!");
    }else{
        stack *temp = top;
        top=top->next;
        return temp->data;
        // stack *p=top;
        // stack *tn=p->next;
        // top=p->next;
        // free(p);
        // return tn->data;
    }
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

    if(p==NULL){
        return;
    }
    while (1)
    {
        if(p){
            push(p);
            printf("%d\t",p->data);
            p=p->left;
        }else{
            if(top){
                p=pop();
                p=p->right;
                // break;
            }else{
                break;
            }
        }
    }  

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
    while (1)
    {
        if(p){
            push(p);
            p=p->left;
        }else{
            if(top){
                p=pop();
                printf("%d\t",p->data);
                p=p->right;
            }else{
                break;
            }
        }
    }  

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
    node *p=t;

    if(p==NULL){
        return;
    }
    while (1)
    {
        if(p){
            if(p->right){
                push(p->right);
            }
            push(p);
            p=p->left;
        }else{
            if(top){
                // printf("%d\t",p->data);
                p=pop();
                if(!p->right){
                    printf("%d\t",p->data);
                    p=NULL;
                }
                if(!p){
                    p=pop();
                    if(p->data==top->data->data){
                        printf("%d\t",top->data->data);
                        push(p);
                    }
                }
                // p=p->right;
                // break;
            }else{
                break;
            }
        }
    }  

    return;
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
    while (1)
    {
        if(p){
            push(p);
            p=p->left;
        }else{
            if(top){
                p=pop();
                count++;
                // printf("%d\t",p->data);
                p=p->right;
            }else{
                break;
            }
        }
    }  

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
    while (1)
    {
        if(p){
            push(p);
            p=p->left;
        }else{
            if(top){
                p=pop();
                if(p->left==NULL && p->right==NULL){
                    count++;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }  

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
    while (1)
    {
        if(p){
            push(p);
            p=p->left;
        }else{
            if(top){
                p=pop();
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
    top=NULL;
    while (1){
        if(p){
            push(p);
            p=p->left;
        }else{
            if (top){
                p=pop();
                if ((p->left && !p->right) || (!p->left && p->right)){
                    return 0;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }
    return 1;
}

int isCompleteTreeWithoutRecursion(BST t){
    node *p=t;
    int flag=0;
    if(!p){
        return 1;
    }
    top=NULL;
    while (1){
        if(p){
            push(p);
            p=p->left;
        }else{
            if(top){
                p=pop();
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
    while (1)
    {
        if(p){
            push(p);
            p=p->left;
            if(top && p){
                if(p->data>top->data->data){
                    return 0;
                }
            }
        }else{
            if(top){
                p=pop();
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
    top=NULL;
    while (1){
        if(p){
            push(p);
            p=p->left;
        }else{
            if(top){
                p=pop();
                q=p->right;
                // printf("%d\t",p->data);
                free(p);
                p=q;
            }else{
                break;
            }
        }
    }

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


int main(){
    BST t = NULL;
    initBST(&t);

    insertWithRecursion(&t, 10);
    insertWithRecursion(&t, 5);
    insertWithRecursion(&t, 15);
    insertWithRecursion(&t, 3);
    insertWithRecursion(&t, 7);
    insertWithRecursion(&t, 12);

    insertWithRecursion(&t, 17);
    insertWithRecursion(&t, 15);

    insertWithoutRecursion(&t, 32);
    insertWithoutRecursion(&t, 1);
    // insertWithoutRecursion(&t, 8);
    insertWithoutRecursion(&t, 65);
    insertWithoutRecursion(&t, 23);
    insertWithoutRecursion(&t, 4);



    // insertWithRecursion(&t, 25);
    // insertWithRecursion(&t, 20);
    // insertWithRecursion(&t, 36);
    // insertWithRecursion(&t, 10);
    // insertWithRecursion(&t, 22);
    // insertWithRecursion(&t, 30);
    // insertWithRecursion(&t, 40);

    // insertBT(&t, 10);
    // insertBT(&t, 5);
    // insertBT(&t, 15);
    // insertBT(&t, 3);
    // insertBT(&t, 7);
    // insertBT(&t, 12);


    printf("PreOrder Traversal with Recursion:\n");
    preOrderWithRecursion(t);
    printf("\n");

    printf("InOrder Traversal with Recursion:\n");
    inOrderWithRecursion(t);
    printf("\n");

    printf("PostOrder Traversal with Recursion:\n");
    postOrderWithRecursion(t);
    printf("\n");

    int cnr = countNodesWithRecursion(t);
    printf("\nCounting Number of Nodes with Recursion:%d\n",cnr);

    int cni = countNodesWithoutRecursion(t);
    printf("Counting Number of Nodes without Recursion:%d\n",cni);

    int clr = countLeafNodesWithRecursion(t);
    printf("\nCounting Leaf Nodes with Recursion:%d\n",clr);

    int cli = countLeafNodesWithoutRecursion(t);
    printf("Counting Leaf Nodes without Recursion:%d\n",cli);

    int ci = countInternalNodesWithRecursion(t);
    printf("\nCounting Internal Nodes with Recursion:%d\n",ci);

    int cr = countInternalNodesWithoutRecursion(t);
    printf("Counting Internal Nodes without Recursion:%d\n",cr);

    int isFullr = isFullTreeWithRecursion(t);
    printf("\nIs Tree Full with Recursion: %d",isFullr);

    int isFulli = isFullTreeWithoutRecursion(t);
    printf("\nIs Tree Full without Recursion: %d",isFulli);

    int isCompletei = isCompleteTreeWithoutRecursion(t);
    printf("\n\nIs Tree Complete without Recursion: %d\n",isCompletei);

    int isBSTi = isBST(t);
    printf("\nIs Tree BST without Recursion: %d\n",isBSTi);

    int h = height(t);
    printf("\nHeight of Tree: %d",h);
    printf("\n");

    printf("\nPreOrder Traversal without Recursion:\n");
    preOrderWithoutRecursion(t);
    printf("\n");

    printf("\nInOrder Traversal without Recursion:\n");
    inOrderWithoutRecursion(t);
    printf("\n");

    // printf("\nPostOrder Traversal without Recursion:\n");
    // postOrderWithoutRecursion(t);
    // printf("\n");

    // printf("\nDestroying Tree:\n");
    // destroyWithRecursion(&t);

    // printf("\nDestroying Tree:\n");
    // t=destroyWithoutRecursion(t);

    
    int breadth=breadthRecusrion(t);
    printf("\nBreadth of Tree:%d\n",breadth);

    printf("\nWorking Well!\n");

    return 0;
}