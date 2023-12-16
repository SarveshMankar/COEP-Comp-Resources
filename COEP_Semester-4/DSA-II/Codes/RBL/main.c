#include<stdio.h>
#include<stdlib.h>
#include "func.h"

int main(){

    RBL *t = (RBL *)malloc(sizeof(RBL));
    initRBL(t);

    insertNode(t, 15);
    traverse(*t);
    printf("\n1-----------\n");

    insertNode(t, 20);
    traverse(*t);
    printf("\n2-----------\n");

    insertNode(t, 5);
    traverse(*t);
    printf("\n3-----------\n");

    insertNode(t, 8);
    traverse(*t);
    printf("\n4-----------\n");

    // insertNode(t, 31);
    // traverse(*t);
    // printf("\n5-----------\n");
    
    // insertNode(t, 100);
    // traverse(*t);
    // printf("\n6-----------\n");

    // insertNode(t, 2);
    // traverse(*t);
    // printf("\n7-----------\n");

    // insertNode(t, 1);
    // traverse(*t);
    // printf("\n8-----------\n");

    // insertNode(t, 0);
    // traverse(*t);
    // printf("\n9-----------\n");

    // printf("\n------------\n");
    // inorder(*t);

    // printf("\n------------\n");
    // removeNode(t,20);
    // traverse(*t);

    // printf("\n------------\n");
    // removeNode(t,100);
    // traverse(*t);

    return 0;
}