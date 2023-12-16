typedef struct node
{
    int row,col,val;
    struct node *next;
    struct node *down;
}node;


typedef struct sparse{
    int row,col;
    node **rows;
    node **cols;
}sparse;

void init_Sparse(sparse **s, char *filename);
void insert_Sparse(sparse **s, char *filename);

void insert_Node(sparse **s, int row, int col, int val);

void display_Sparse(sparse *s);

sparse *add_Sparse(sparse *s1, sparse *s2);
sparse *sub_Sparse(sparse *s1, sparse *s2);

int ifSymmetric(sparse *s);
sparse *transpose_Sparse(sparse *s);