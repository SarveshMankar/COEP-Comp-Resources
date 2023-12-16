typedef struct node
{
    int j,w;
    struct node *next;
} node;

typedef struct graph
{
    node **A;
    int n;
} graph;

typedef node **SP_Tree;

void init(graph *G, char *filename);
void print(graph *G);
void displaySPtree(SP_Tree S, int n);
void BFS(graph *G, int s);
void DFS(graph *G, int s);

SP_Tree PRIMS(graph *G, int s);
void old_PRIMS(graph *G, int s);

void dijkstra(graph *G, int s);