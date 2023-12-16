/*
Anjali Ajay Dofe
MIS 111903137
DSA lab assignment 1
*/
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
    bst t;
    int ch;
    double n;
    char names[LEN];
    initBST(&t);
    while(1){
        printf("\n************ MENU DRIVEN PROGRAM FOR BST ***********\n");
        printf("\nEnter 1 for inserting a node in the binary search tree");
        printf("\nEnter 2 for removing a node from the binary search tree");
        printf("\nEnter 3 for searching a node in the binary search tree");
        printf("\nEnter 4 for  post order traversal of the binary search tree");
        printf("\nEnter 5 for  displaying nodes in ith level of binary search tree");
        printf("\nEnter 6 for destroying the binary search tree");
        printf("\nEnter 7 to exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                {
                    printf("\nEnter MIS number : ");
                    scanf("%lf", &n);
                    printf("\nEnter name of the student : ");
                    scanf("%s",names);
                    insertNode(&t, n, names);
                    break;
                }
            case 2:
                {
                    printf("\nEnter MIS of node to be removed from the tree : ");
                    scanf("%lf", &n);
                    removeNode(&t, n);
                    printf("\nNode if present is removed\n");
                    break;
                }
            case 3:
                {
                    printf("\nEnter MIS of node to be searched from the tree : ");
                    scanf("%lf", &n);
                    int i = search(t, n);
                    if(i == 1)
                        printf("\nNode found\n");
                    else
                        printf("\nNode absent\n");
                    break;
                }
            case 4:
                {
                    printf("\n");
                    postorder(t);
                    printf("\n");
                    break;
                }
            case 5:
                {
                    printf("\nEnter level you want to traverse : ");
                    int i;
                    scanf("%d", &i);
                    printf("\n");
                    Display_Level(t, 0, i);
                    printf("\n");
                    break;
                }
            case 6:
                {
                    destroyTree(&t);
                    printf("\nTree is destroyed and all nodes in it deleted\n");
                    break;
                }
            case 7:
                {
                    exit(0);
                }
            default :
                {
                    printf("\nWrong choice");
                    break;
                }
        }

    }
//    initBST(&t);
//    insertNode(&t, 111903137, "Anjali");
//    insertNode(&t, 111903140, "Archisha");
//    insertNode(&t, 111903130, "Kareena");
//    insertNode(&t, 111903147, "Pallavi");
//    insertNode(&t, 111903135, "Jaan");
    //r_postorder(t); //for testing and matching output of non recursive postorder with recursive postorder
//    postorder(t);

    return 0;
}
