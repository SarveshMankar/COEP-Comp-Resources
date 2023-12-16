#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
} stack;

int isEmpty(stack *ptr)
{
    return (ptr->top == -1);
}
int isFull(stack *ptr)
{
    return (ptr->top == ptr->size - 1);
}

void push(stack *ptr, char val)
{
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
    else
    {
        printf("Stack overflow");
    }
}

char pop(stack *ptr)
{
    if (!isEmpty(ptr))
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    else
    {
        return -1;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '*' || ch == '-' || ch == '/')
    {
        return 1;
    }

    return 0;
}

char *infixToPostfix(char *e)
{
    stack *sp = (stack *)malloc(sizeof(stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char x;

    char *postfix = (char *)malloc((strlen(e) + 1) * sizeof(char));\
    
    int i = 0;
    while(*e != '\0')
    {
        if(isalnum(*e))
            postfix[i++] = *e;
        else if(*e == '(')
            push(sp, *e);
        else if(*e == ')')
        {
            while((x = pop(sp)) != '(')
                postfix[i++] = x;
        }
        else
        {
            while(precedence(sp->arr[sp->top]) >= precedence(*e))
                postfix[i++] = pop(sp);
            push(sp,*e);
        }
        e++;
    }

    while(sp->top != -1)
    {
        postfix[i++] = pop(sp);
    }

    postfix[i] = '\0';
    
    return postfix;
}


int main()
{
    //Enter the expression : ((4+8)(6-5))/((3-2)(2+2))
    //4 8 + 6 5 - 3 2 - 2 2 + / 
    char *infix = "((4+8)(6-5))/((3-2)(2+2))";
    printf("%s\n", infixToPostfix(infix));

    return 0;
}