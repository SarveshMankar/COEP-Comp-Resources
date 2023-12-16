#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"
#include"stack.h"
#include"queue.h"
#include"heap.h"

void init(graph *G, char *filename){
    //Creating Adajacency List
    FILE *fp = fopen(filename,"r");
    fscanf(fp,"%d",&G->n);
    G->A = (node**)malloc(G->n*sizeof(node*));

    for (int i = 0; i < G->n; i++){
        node *row = (node*)malloc(sizeof(node));
        row->next = NULL;
        for (int j = 0; j < G->n; j++){
            int x;
            fscanf(fp,"%d",&x);
            if (x != 100){
                node *temp = (node*)malloc(sizeof(node));
                temp->j = j;
                temp->w = x;
                temp->next = NULL;
                if (row->next == NULL){
                    row->next = temp;
                }
                else{
                    node *p = row;
                    while (p->next != NULL){
                        p = p->next;
                    }
                    p->next = temp;
                }
            }
        }
        G->A[i] = row;
    }
    
}

void print(graph *G){
    for (int i = 0; i < G->n; i++){
        node *p = G->A[i]->next;
        printf("%d: ",i);
        while (p != NULL){
            printf("%d ",p->j);
            p = p->next;
        }
        printf("\n");
    }
}

void displaySPtree(SP_Tree S, int n){

  node *temp;
//   int cost = 0;
  printf("SPANNING TREE:\n");
  for(int i = 0; i < n ; i++){
    temp = S[i];
    printf("%d : ", i);
    while(temp){
      printf("%d=> %d\t", temp->j, temp->w );
    //   cost += temp->w;
      temp = temp->next;
    }
    printf("\n");
  }
//   printf("COST => %d\n", cost);

  return;
}


void BFS(graph *G, int s){
    int *visited = (int*)calloc(G->n,sizeof(int));

    Queue *Q = (Queue*)malloc(sizeof(Queue));
    initQueue(Q);

    enqueue(Q,s);
    visited[s] = 1;

    while (!isEmpty(Q)){
        int i = dequeue(Q);
        printf("%d ",i);
        node *p = G->A[i];
        while (p != NULL){
            if (visited[p->j] == 0){
                enqueue(Q,p->j);
                visited[p->j] = 1;
            }
            p = p->next;
        }
    }

    printf("\n");
}

void DFS(graph *G, int s){
    int *visited = (int*)calloc(G->n,sizeof(int));
    
    Stack *S = (Stack*)malloc(sizeof(Stack));
    initStack(S);

    push(S,s);
    visited[s] = 1;

    while (!isEmptyS(S)){
        int i = pop(S);
        printf("%d ",i);
        node *p = G->A[i];
        while (p != NULL){
            if (visited[p->j] == 0){
                push(S,p->j);
                visited[p->j] = 1;
            }
            p = p->next;
        }
    }

    printf("\n");
}

void old_PRIMS(graph *G, int s){
    int *visited = (int*)calloc(G->n,sizeof(int));
    if(!visited) return;
    
    int *parent = (int*)malloc(G->n*sizeof(int));
    for (int i = 0; i < G->n; i++){
        parent[i] = -1;
    }
    if(!parent){
        free(visited);
        return;
    }

    int *cost = (int*)malloc(G->n*sizeof(int));
    if(!cost){
        free(visited);
        free(parent);
        return;
    }

    for (int i = 0; i < G->n; i++){
        cost[i] = INT_MAX;
    }
    cost[s] = 0;
    parent[s] = -1;

    for (int i = 0; i < G->n; i++){
        int min = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < G->n; j++){
            if (visited[j] == 0 && cost[j] < min){
                min = cost[j];
                min_index = j;
            }
        }

        visited[min_index] = 1;

        node *p = G->A[min_index]->next;
        while (p != NULL){
            if (visited[p->j] == 0 && p->w < cost[p->j]){
                cost[p->j] = p->w;
                parent[p->j] = min_index;
            }
            p = p->next;
        }
    }

    for (int i = 0; i < G->n; i++){
        printf("%d %d %d\n",i, parent[i], cost[i]);
    }
}

SP_Tree PRIMS(graph *G, int s){
    int *visited = (int*)calloc(G->n,sizeof(int));
    if(!visited) return NULL;
    
    int *parent = (int*)malloc(G->n*sizeof(int));
    for (int i = 0; i < G->n; i++){
        parent[i] = -1;
    }
    if(!parent){
        free(visited);
        return NULL;
    }

    int *cost = (int*)malloc(G->n*sizeof(int));
    if(!cost){
        free(visited);
        free(parent);
        return NULL;
    }

    for (int i = 0; i < G->n; i++){
        cost[i] = INT_MAX;
    }
    cost[s] = 0;
    parent[s] = -1;

    for (int i = 0; i < G->n; i++){
        int min = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < G->n; j++){
            if (visited[j] == 0 && cost[j] < min){
                min = cost[j];
                min_index = j;
            }
        }

        visited[min_index] = 1;

        node *p = G->A[min_index]->next;
        while (p != NULL){
            if (visited[p->j] == 0 && p->w < cost[p->j]){
                cost[p->j] = p->w;
                parent[p->j] = min_index;
            }
            p = p->next;
        }
    }

    SP_Tree t = (SP_Tree)malloc(G->n*sizeof(node*));
    for (int i = 0; i < G->n; i++){
        t[i]=NULL;
    }

    for (int i = 0; i < G->n; i++){
        if (parent[i] != -1){
            node *temp = (node*)malloc(sizeof(node));
            temp->j = i;
            temp->w = cost[i];
            temp->next = NULL;

            if (t[parent[i]] == NULL){
                t[parent[i]] = temp;
            }
            else{
                node *p = t[parent[i]];
                while (p->next != NULL){
                    p = p->next;
                }
                p->next = temp;
            }

            node *temp2 = (node*)malloc(sizeof(node));
            temp2->j = parent[i];
            temp2->w = cost[i];
            temp2->next = NULL;

            if (t[i] == NULL){
                t[i] = temp2;
            }
            else{
                node *p = t[i];
                while (p->next != NULL){
                    p = p->next;
                }
                p->next = temp2;
            }
        }
    }

    int ans=0;
    for(int i=0;i<G->n;i++){
        ans+=cost[i];
    }
    
    printf("\nCOST => %d\n", ans);

    return t;
}

void dijkstra(graph *G, int s){
    int n = G->n;
    int *cost = (int *)malloc(sizeof(int)*n);
    int *visited = (int *)calloc(n,sizeof(int));

    for(int i=0; i<n; i++){
        cost[i]=INT_MAX;
    }

    cost[s]=0;

    for(int i=0;i<n;i++){
        int mini;
        int min=INT_MAX;

        for(int j=0; j<n; j++){
            if(visited[j]!=1 && cost[j]<min){
                min=cost[j];
                mini=j;
            }
        }

        visited[mini]=1;

        for(int j=0; j<n; j++){
            node *p = G->A[mini];
            while(p!=NULL){
                if(visited[p->j]!=1 && cost[p->j]>cost[mini]+p->w){
                    cost[p->j]=cost[mini]+p->w;
                }
                p=p->next;
            }            
        }
    }    

    int ans=0;
    for(int j=0; j<n; j++){
        ans+=cost[j];
    }

    printf("\nDijkstras's Answer: %d",ans);
}