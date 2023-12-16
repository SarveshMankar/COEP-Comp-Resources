#include<stdio.h>
#include<stdlib.h>

//Postfix Expression Evaluation using Stack
typedef struct stack
{
    int top;
    int size;
    int *s;
} stack;

void create(stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void push(stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow");
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int operation(int x, int y, char op)
{
    if (op == '+')
        return x + y;
    else if (op == '-')
        return x - y;
    else if (op == '*')
        return x * y;
    else
        return x / y;
}

int evaluate(char *postfix)
{
    stack st;
    create(&st);
    int i = 0;
    int x1, x2, r;
    while (postfix[i] != '\0')
    {
        if (isOperand(postfix[i]))
            push(&st, postfix[i] - '0');
        else
        {
            x2 = pop(&st);
            x1 = pop(&st);
            r = operation(x1, x2, postfix[i]);
            push(&st, r);
        }
        i++;
    }
    return pop(&st);
}

int main()
{
    char *postfix = "234*+82/-";
    printf("Result is %d", evaluate(postfix));
    return 0;
}
