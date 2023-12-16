typedef struct stack{
	int *A;
	int s;
	int top;
} stack;

// void initStack(stack **s, int size);
void initStack(stack *S);

void push(stack *s, int data);
int pop(stack *s);

int isEmptyS(stack *s);
int isFullS(stack *s);

void peekS(stack *s);
