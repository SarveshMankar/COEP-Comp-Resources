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

void initSparse(Sparse *s);
void display(Sparse s);
