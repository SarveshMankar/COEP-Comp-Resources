#include"../func.h"

typedef struct stack{
    node *data;
    struct stack *next;
    struct stack *top;
}stack;

void initStack(stack *s);
void push(stack *s,node *data);
node *pop(stack *s);
stack *destroyStack(stack *s);
int isEmptyStack(stack *s);