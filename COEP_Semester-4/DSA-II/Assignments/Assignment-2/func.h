typedef struct node
{
    int *A;
    int s;
}aBST;

void initBST(aBST *t);
void insertBST(aBST *t, int k);

int height(aBST *t);

int countLeafNodes(aBST *t);

int isComplete(aBST *t);

void levelOrder(aBST *t);
void inOrder(aBST *t);
void inOrder2(aBST *t, int i);

void printABST(aBST *t);
