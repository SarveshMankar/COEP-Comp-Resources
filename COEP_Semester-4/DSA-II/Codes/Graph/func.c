#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"func.h"
#include"queue.h"
#include"stack.h"


void initGraph(graph *G, char *filename){
    FILE *fp;
    fp = fopen(filename, "r");

    fscanf(fp, "%d", &G->n);
    G->A = (int**)malloc(G->n*sizeof(int*));

    for(int i = 0; i < G->n; i++){
        G->A[i] = (int*)malloc(G->n*sizeof(int));
        if(!G->A[i]){
            printf("Not enough memory!\n");
            exit(0);
        }
        for(int j = 0; j < G->n; j++){
            fscanf(fp, "%d", &G->A[i][j]);
        }
    }   

    fclose(fp);
}

void display(graph G){
    for(int i = 0; i < G.n; i++){
        for(int j = 0; j < G.n; j++){
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
}

void BFS(graph G, int s){
    int *visited = (int*)calloc(G.n,sizeof(int));
    // // printf("\nVISITED: ");
    // for(int i = 0; i < G.n; i++){
    //     printf("%d ", visited[i]);
    // }
    printf("\n");

    Queue Q;
    initQueue(&Q);

    enqueue(&Q, s);
    visited[s] = 1;
    int v;

    while (!isEmpty(&Q)){
        v = dequeue(&Q);
        // printf("\nDequeued: %d\n", v);
        printf("%d ", v);

        for(int i = 0; i < G.n; i++){
            if(G.A[v][i] != 0 && visited[i] == 0){
                enqueue(&Q  , i);
                visited[i] = 1;
            }
        }
    }

    // printf("\nVISITED: ");
    // for(int i = 0; i < G.n; i++){
    //     printf("%d ", visited[i]);
    // }
    printf("\n"); 
}

void DFS(graph G, int s){
    int *visited = (int*)calloc(G.n,sizeof(int));
    int n=G.n;

    stack *ms;
    initStack(&ms,100);
    push(ms,s);

    visited[s]=1;
    int v;
    while (!isEmptyS(ms)){
        v=pop(ms);
        printf("%d\n",v);
        for (int i = 0; i < n; i++){
            if (G.A[v][i]!=0 && visited[i] == 0){
                push(ms,i);
                printf("Ok");
            }
            visited[i]=1;            
        }
        
    }

    while (!isEmptyS(ms)){
        v=pop(ms);
        printf("%d\n",v);
    }
    
    

}