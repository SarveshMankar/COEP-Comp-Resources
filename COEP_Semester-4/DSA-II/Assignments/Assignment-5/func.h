typedef struct graph {
    int n; // number of vertices
    int **A; // adjacency matrix Representation
} graph;

void initGraph(graph *G, char *filename);
void display(graph G);

void BFS(graph G, int s);
void DFS(graph G, int s);

void displayDegree(graph G);
void checkIfVertexsAreAdjacent(graph G, int u, int v);
int verifyIfGraphIsConnected(graph G);
void numberOfComponents(graph G);
void displayCycles(graph G);

int getVertices(graph G);

int *Dijkstra(graph G, int s);
void PRIMS(graph G, int s);