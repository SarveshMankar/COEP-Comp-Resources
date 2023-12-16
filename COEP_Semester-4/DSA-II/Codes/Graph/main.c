#include<stdio.h>
#include<stdlib.h>
#include"func.h"
#include"queue.h"

int main(){
    graph G;
    initGraph(&G, "graph.txt");
    display(G);

    // Queue Q;
    // initQueue(&Q);
    printf("\n");
    BFS(G, 1);

    printf("\n");
    DFS(G, 1);


    printf("\n\nWorking Well!\n");
    return 0;
}