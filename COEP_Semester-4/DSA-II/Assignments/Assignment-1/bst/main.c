#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./functions.h"

int main(int argc, char **argv){
	
	Tree BST = NULL;
	Tree BT = NULL;

	FILE *fptr;
	fptr = fopen("test.txt", "r");

	int s;
	insertBST(&BST, 3);
	insertBST(&BST, 2);
	insertBST(&BST, 5);
	insertBST(&BST, 1);
	insertBT(&BT, 1);
	insertBT(&BT, 5);
	insertBT(&BT, 7);
	insertBST(&BST, 7);
	for(int i = 0; i < 10000; i++){
		fscanf(fptr, "%d",&s );
		insertBT(&BT, s);
		insertBST(&BST, s);
	}
	int count = 0;
	int flag = 0;

	int searchs = 0;

	char *d = argv[1];
	int i = 0;
	while(d[i] != '\0'){
		searchs = (10*searchs)+(d[i]-'0');
		i++;
	}
	printf("%s", argv[2]);

	if (!strcmp(argv[2], "BST"))
		count = searchBST(BST, searchs);
	else
		searchBT(BT,searchs , &flag, &count);
	printf("\n%d", count);

	return 0;
}

