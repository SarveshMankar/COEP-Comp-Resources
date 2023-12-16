#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"

int main(){
    BST t = NULL;
    initBST(&t);

    insertWithRecursion(&t, 10);
    insertWithRecursion(&t, 5);
    insertWithRecursion(&t, 15);
    insertWithRecursion(&t, 3);
    insertWithRecursion(&t, 7);
    insertWithRecursion(&t, 9);
    insertWithRecursion(&t, 12);

    insertWithRecursion(&t, 17);
    insertWithRecursion(&t, 15);

    insertWithRecursion(&t, 32);
    insertWithRecursion(&t, 1);
    insertWithRecursion(&t, 65);
    insertWithRecursion(&t, 23);
    insertWithRecursion(&t, 4);
    insertWithRecursion(&t, 11);


    int ans = maxWidth(t);
    printf("%d", ans);
    
    printf("\nWorking Well!\n");

    return 0;
}