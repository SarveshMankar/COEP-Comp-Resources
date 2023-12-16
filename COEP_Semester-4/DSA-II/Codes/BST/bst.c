#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

void initBST(node **tree)
{
    tree = NULL;
}

void insertNode(node **t, int data){
	node *nn = (node*)malloc(sizeof(node));
	nn->data=data;
	if (*t==NULL){
		*t=nn;
	}else if(data<(*t)->data){
		insertNode(&(*t)->left,data);
	}else if(data>(*t)->data){
		insertNode(&(*t)->right,data);
	}
}

int search(node *t, int data){
	if (t==NULL){
		return 0;
	}
	if((t)->data==data){
		return 1;
	}else if(data<(t)->data){
		search(t->left,data);
	}else if(data>(t)->data){
		search(t->right,data);
	}
}

void displayLevel(node *t, int curr, int tl){
	if(t == NULL)
        return;
    if(curr == tl){
        printf("%d\t",t->data);
    }
    displayLevel(t->left, curr+1, tl);
    displayLevel(t->right, curr+1, tl);
}

int treeDepth(node *t){
	if (t==NULL){
		return 0;
	}
	int left = treeDepth(t->left);
	int right = treeDepth(t->right);

	if (left>right){
		return left+1;
	}else{
		return right+1;
	}
}

void displayTree(node *t){
	int curr=0;
	int depth = treeDepth(t) - 1;

	for(int i=0; i<=depth; i++){
		printf("\n");
		displayLevel(t,curr,i);
	}
}

void preOrderTraversal(node *t){
	if (t==NULL){
		return;
	}
	printf("%d\t",t->data);
	preOrderTraversal(t->left);
	preOrderTraversal(t->right);
}

void inOrderTraversal(node *t){
	if(t!=NULL){
		inOrderTraversal(t->left);
		printf("%d\t",t->data);
		inOrderTraversal(t->right);	
	}
}

void postOrderTraversal(node *t){
	if(t==NULL){
		return;
	}
	postOrderTraversal(t->left);
	postOrderTraversal(t->right);
	printf("%d\t", t->data);
}


node *minValueNode(node* node){
    /* loop down to find the leftmost leaf */
    while (node && node->left != NULL)
        node = node->left;
 
    return node;
}


node* deleteNode(node* t, int data)
{
    // base case
    if (t == NULL)
        return t;

    if (data < t->data)
        t->left = deleteNode(t->left, data);
    else if (data > t->data)
        t->right = deleteNode(t->right, data);
 
    // if data is same as t's data
    else {
        // node with only one child or no child
        if (t->left == NULL) {
            node* temp = t->right;
            free(t);
            return temp;
        }
        else if (t->right == NULL) {
            node* temp = t->left;
            free(t);
            return temp;
        }
        // (smallest in the right subtree)
        node* temp = minValueNode(t->right);
        // Copy the inorder successor's content to this node
        t->data = temp->data;
        // Delete the inorder successor
        t->right = deleteNode(t->right, temp->data);
    }
    return t;
}

node *deleteTree(node *t){
	if (t==NULL){
		return t;
	}
	deleteTree(t->left);
	deleteTree(t->right);
	free(t);
}

void push(node *t, int size, int *top, node stack[]){
	if (*top==size-1){
		printf("Stack is full");
	}else{
		*top=*top+1;
		stack[*top]=*t;
	}	
}

//https://prepinsta.com/data-structures/post-order-tree-traversal-without-recursion/
void postOrderTraversalWithoutRecursion(node *t){
	int top=-1;
	int size=10;
	node stack[size];
	node *temp = (node*)malloc(sizeof(node));
	temp=t;
	while (temp)
	{
		if(temp->right){
			push(temp,size,&top,stack);
		}
		push(temp,size,&top,stack);

		temp=temp->left;
	}
	
	
}