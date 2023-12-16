typedef struct stack{
    int *A;
    int top;
    int size;
} stack;

void initStack(stack **s, int size);

void push(stack *s, int data);
int pop(stack *s);

int isEmptyS(stack *s);
int isFullS(stack *s);

void peekS(stack *s);
