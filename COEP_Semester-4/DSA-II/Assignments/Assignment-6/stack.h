typedef struct Stack{
	int *A;
	int s;
	int top;
} Stack;

void initStack(Stack *S);

void push(Stack *s, int data);
int pop(Stack *s);

int isEmptyS(Stack *s);
int isFullS(Stack *s);

void peekS(Stack *s);
