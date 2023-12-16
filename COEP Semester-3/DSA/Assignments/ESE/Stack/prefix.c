//    char *p2 = "321+*71+-33+/";
#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int top;
    int size;
    int *s;
} stack;

void push(stack *myStack, int data){
    myStack->top=myStack->top+1;
    myStack->s[myStack->top]=data;
}

int pop(stack *myStack){
    int n1=myStack->s[myStack->top];
    myStack->top=myStack->top-1;
    return n1;        
}

void display(stack *myStack, int top){
    printf("---------\n");
    while(top>=0){
        printf("%d\t",myStack->s[top]);
        top--;
    }
    printf("\n---------\n");
}

int operate(stack *myStack,int x, char op, int y){
    if (op == '+')
        return x + y;
    else if (op == '-')
        return x - y;
    else if (op == '*')
        return x * y;
    else
        return x / y;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int evaluate(char *prefix)
{
    stack *st=(stack*)malloc(sizeof(stack));
    
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));

    int i = 0;
    int sp=0;
    while (prefix[i] != '\0'){
        sp++;
        i++;
    }
    printf("%d",sp);

    i=0;
    while (prefix[i] != '\0'){

        if(isOperand(prefix[sp-1-i])){
            push(st,prefix[sp-1-i]-'0');
            display(st, st->top);

        }else{
            int n1 = pop(st);
            int n2 = pop(st);
            int ans = operate(st,n1,prefix[sp-1-i],n2);
            printf("%d\n",ans);

            push(st,ans);
            display(st, st->top);
        }
        i++;
        
    }
    return pop(st);
}

int main()
{
    char *prefix = "/+33-+47*+123";
    printf("Result is %d", evaluate(prefix));
    return 0;
}
