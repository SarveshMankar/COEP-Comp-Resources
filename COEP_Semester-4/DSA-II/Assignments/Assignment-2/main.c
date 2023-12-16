#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include"func.h"


int main(){
    aBST t;
    initBST(&t);

    insertBST(&t, 2);
    insertBST(&t, 1);
    insertBST(&t, 3);
    insertBST(&t, 5);
    insertBST(&t, 7);
    insertBST(&t, 12);
    insertBST(&t, 17);
    insertBST(&t, 15);
    insertBST(&t, 32);
    insertBST(&t, 2);
    insertBST(&t, 77);
    insertBST(&t, 8);
    insertBST(&t, 9);
    insertBST(&t, 65);
    insertBST(&t, 0);
    insertBST(&t, 78);
    insertBST(&t, 14);
    insertBST(&t, 50);
    insertBST(&t, 44);
    insertBST(&t, 32);

    printf("Inorder: ");
    inOrder(&t);
    printf("\n");

    printf("\nHeight: %d\n",height(&t));

    printf("\nLeaf Nodes: %d\n",countLeafNodes(&t));

    if(isComplete(&t)){
        printf("\nTree is Complete!\n");
    }else{
        printf("\nTree is not Complete!\n");
    }
    
    printf("\nLevel Order: \n");
    levelOrder(&t);

    return 0;
}