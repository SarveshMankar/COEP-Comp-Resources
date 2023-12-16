#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"

int main(){

    printf("Initializing Graph using Adjacency List!");
    graph *G;
    G = (graph*)malloc(sizeof(graph));
    init(G,"data.txt");

    printf("\n\nDisplaying Graph!\n");
    print(G);

    printf("\n\nBFS Traversal!\n");
    BFS(G,0);

    printf("\n\nDFS Traversal!\n");
    DFS(G,0);

    printf("\n\nPRIMS Algorithm!\n");
    old_PRIMS(G,0);

    printf("\n\nDisplaying SP Tree!\n");
    SP_Tree t = PRIMS(G,0);
    displaySPtree(t,G->n);

    dijkstra(G, 0);


    return 0;
}
