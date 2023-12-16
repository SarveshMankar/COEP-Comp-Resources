typedef struct graph {
    int n; // number of vertices
    int **A; // adjacency matrix Representation
} graph;

void initGraph(graph *G, char *filename);
void display(graph G);

void BFS(graph G, int s);
void DFS(graph G, int s);