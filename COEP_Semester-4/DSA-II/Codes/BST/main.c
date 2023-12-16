#include<stdio.h>
#include<stdlib.h>
#include"bst.c"

void main(){

    node *tree;
    initBST(&tree);

    insertNode(&tree,8);
    printf("%d",tree->data);
    insertNode(&tree,3);
    insertNode(&tree,1);
    insertNode(&tree,6);
    insertNode(&tree,4);
    insertNode(&tree,7);
    insertNode(&tree,10);
    insertNode(&tree,14);

    if (search(tree,1234561)){
        printf("\nData Found!");
    }else{
        printf("\nData Not Found!");
    }

    printf("\nDisplaying Level: ");
    displayLevel(tree,0,2);

    printf("\nDepth of the BST: %d", treeDepth(tree));

    printf("\nDisplay Complete Tree: \n");
    displayTree(tree);

    printf("\n Pre-Order Traversal: \n");
    preOrderTraversal(tree);

    printf("\n In-Order Traversal: \n");
    inOrderTraversal(tree);

    printf("\n Post-Order Traversal: \n");
    postOrderTraversal(tree);

    printf("\nDeleting Node 3 \n");
    tree = deleteNode(tree, 3);

    printf("\nDisplay Complete Tree: \n");
    displayTree(tree);

    //printf("\n Post-Order Traversal without Recursion: \n");
    //postOrderTraversalWithoutRecursion(tree);

    printf("\nDeleting Tree \n");
    tree = deleteTree(tree);

    printf("\n");
}
