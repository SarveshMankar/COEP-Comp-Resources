#include<stdio.h>
#include<stdlib.h>
#include "func.h"

int main(){
    node *head;
    initAVL(&head);

    FILE *fp = fopen("test_names.txt", "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    while (!feof(fp))
    {
        char name[100];
        fscanf(fp, "%s", name);
        insertNode(&head, name);
    }

    traverse(head);

    // traverse(head);
    removeNode(&head, "o");    
    // removeNode(&head, "Guzman");    
    // removeNode(&head, "Gonzales");
    // removeNode(&head, "Villarreal");
    // removeNode(&head, "Young");
    // removeNode(&head, "Ward");

    printf("\n========== \nMain Answer\n");

    // removeNode(&head, "Liam");    
    traverse(head);

    // destroyAVL(head);

    return 0;
}