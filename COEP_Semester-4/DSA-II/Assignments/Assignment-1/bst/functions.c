#include <stdio.h>
#include <stdlib.h>
#include "./functions.h"

int generateRange(int n, char *filename){

	FILE *fptr;

	fptr = fopen(filename, "w");

	for(int i = 0; i < n; i++){
		fprintf(fptr, "%d\n", rand());
	}

	fclose(fptr);	
}

void initTree(Tree *t){
	Tree temp = *t;
	temp = (Tree ) malloc(sizeof(Node));
	temp->left = NULL;
	temp->right = NULL;
	return;
}


void insertBT(Tree *t, int key){
	if ( (*t) == NULL){
		Tree n = (Tree) malloc(sizeof(Node));
		n->data = key;
		n->left = n->right = NULL;
		*t = n;
	}

	if(rand() % 2 == 0){
		if(!(*t)->left){
			Tree n = (Tree) malloc(sizeof(Node));
			n->data = key;
			n->left = n->right = NULL;
			(*t)->left = n;
			return;
		}

		insertBT(&(*t)->left, key);
	}
	else {
		if(!(*t)->right){
			Tree n = (Tree) malloc(sizeof(Node));
			n->data = key;
			n->left = n->right = NULL;
			(*t)->right = n;
			return;
		}
		insertBT(&(*t)->right, key);
	}
	return;
}

void insertBST(Tree *t, int key){
	if ( (*t) == NULL){
		Tree n = (Tree) malloc(sizeof(Node));
		n->data = key;
		n->left = n->right = NULL;
		*t = n;
	}
	if ((*t)->data == key)
		return;

	if((*t)->data > key){
		insertBST(&(*t)->left, key);
	}
	else if ((*t)->left, key){
		insertBST(&(*t)->right, key);
	}

}


int searchBST(Tree t, int key){

	if(t == NULL)
		return 0;

	if(t->data == key)
		return 1;

	if (t->data > key)
		return searchBST(t->left, key)+1;
	else
		return searchBST(t->right, key)+1;

}

void searchBT(Tree t, int key, int *flag, int *count){

	*count = *count + 1;
	if(!t)
		return;
	if(t->data == key){
		*flag = 1;
		return;
	}
	if (*flag == 0)
		searchBT(t->left, key, flag, count);
	if (*flag == 0)
		searchBT(t->right, key, flag, count);
	return;
}

		

void displayInorder(Tree t){

	if (t == NULL)
		return;
	
	displayInorder(t->left);
	printf("%d\n", t->data);
	displayInorder(t->right);
}



int fact(int n){
	if (n == 1)
		return 1;
	return fact(n-1)*n;
}
