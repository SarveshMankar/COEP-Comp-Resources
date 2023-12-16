#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct queue
{
    int f,r,s,c;
    char *arr;
} queue;

queue *createQueue(int size)
{
    queue *ptr = (queue *)malloc(sizeof(queue));
    ptr->f = ptr->r = -1;
    ptr->s = size;
    ptr->c = 0;
    ptr->arr = (char *)malloc(size * sizeof(char));
    return ptr;
}

char dequeue(queue *ptr);
void putIt(queue *q1, char val);

int isEmpty(queue *ptr)
{
    if (ptr->c == 0)
    {
        return 1;
    }
    return 0;
}

int isFull(queue *ptr)
{
    return (ptr->c == ptr->s);
}

void enqueue(queue *ptr, char val)
{
    char x;
    if (ptr->c==0){
        ptr->f=ptr->r=1;
        ptr->arr[ptr->r]=val;
        ptr->c=ptr->c+1;
        printf("%c ",ptr->arr[ptr->r]);
    }else{
            queue *q2;
            q2 = createQueue(100);

            while(ptr->c>0){
                x=dequeue(ptr);
                putIt(q2,x);
            }

            ptr->r=ptr->r+1;
            ptr->arr[ptr->r]=val;

            while(q2->c>0){
                x=dequeue(q2);
                
            }
    }
    
}

void putIt(queue *q1, char val){
    if(q1->c==0){
        q1->r=q1->f=1;
        q1->arr[q1->r]=val;
    }else{
        q1->r=q1->r+1;
        q1->arr[q1->r]=val;
    }
}

char dequeue(queue *ptr)
{
    char val = ptr->arr[ptr->f];
    ptr->c--;
    if (ptr->c==0)
    {
        ptr->f = ptr->r = -1;
    }
    else
    {
        ptr->f = ptr->f + 1;
        printf("!");
    }
    return val;
    
}

void main(){

    queue *q1;
    q1 = createQueue(100);
    
    enqueue(q1, 'a');
    enqueue(q1, 'b');
    enqueue(q1, 'c');
}