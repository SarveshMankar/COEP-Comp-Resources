typedef struct Node {
    int i,j,value;
    struct Node *next;
    struct Node *down;
}Node ;

typedef struct Sparse{
    int nrows,ncols;
    Node ** rows;
    Node ** cols;
} Sparse;

void sparse_init(Sparse *s);
