typedef struct heap
{
    int *A;
    int s, c;
} heap;



void initHeap(heap *h);
void swap(int *a, int *b);
void display(heap h);


void maxheap_insert(heap *h, int data);
void maxheap_heapify(heap *h);

void maxheap_delete(heap *h);
void maxheap_heapifydel(heap *h);


void minheap_insert(heap *h, int data);
void minheap_heapify(heap *h);

void minheap_delete(heap *h);
void minheap_heapifydel(heap *h);
