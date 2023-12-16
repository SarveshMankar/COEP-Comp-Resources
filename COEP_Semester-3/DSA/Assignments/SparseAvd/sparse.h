typedef struct Node{
	int i,j,data;
	struct Node* next;
	struct Node* down;
}Node;

typedef struct Sparse{
	int noOfRows;
	int noOfColumns;
	Node ** rows;
	Node ** columns;
}Sparse;

void initSparse(Sparse *S, char *file_name);

void display(Sparse *S);

Sparse *add_sparse(Sparse *S1, Sparse *S2);
Sparse *sub_sparse(Sparse *S1, Sparse *S2);
Sparse *transpose(Sparse *S);
