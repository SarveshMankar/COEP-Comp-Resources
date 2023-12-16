typedef struct heap
{
    int *A;
    int s, c;
} heap;

void init(heap *h);
void insert(heap *h, int data);

void delete(heap *h);

void swap(int *a, int *b);

void heapify(heap *h);
void heapifydel(heap *h);

void display(heap *h);