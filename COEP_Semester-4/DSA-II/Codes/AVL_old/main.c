#include<stdio.h>
#include<stdlib.h>
#include "func.c"

void main(){
    AVL t = NULL;
    // insert(&t, 20);
    // insert(&t, 10);
    // insert(&t, 5);
    // insert(&t, 2);

    // insert(&t, 10);
    // insert(&t, 5);
    // insert(&t, 12);
    // insert(&t, 9);
    // insert(&t, 2);
    // insert(&t, 1);

    // insert(&t, 10);
    // insert(&t, 20);
    // insert(&t, 30);
    // insert(&t, 15);


    // insert(&t, 10);
    // insert(&t, 5);
    // insert(&t, 20);

    // insert(&t, 10);
    // insert(&t, 15);
    // insert(&t, 5);

    insert(&t, 178);
    insert(&t, 32);
    insert(&t, 59);
    insert(&t, 205);
    insert(&t, 210);
    insert(&t, 80);
    insert(&t, 75);
    insert(&t, 66);
    insert(&t, 100);
    insert(&t, 125);
    insert(&t, 10);
    insert(&t, 15);
    insert(&t, 108);
    insert(&t, 84);

    // insert(&t, 10);
    // insert(&t, 20);
    // insert(&t, 30);
    // insert(&t, 40);
    // insert(&t, 50);
    // insert(&t, 25);


    preorder(t);
    printf("-----------------\n");
    // inorder(t);
}
