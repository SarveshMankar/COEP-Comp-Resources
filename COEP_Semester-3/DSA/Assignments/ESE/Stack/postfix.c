#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int top;
    int size;
    int *s;
} stack;

int operate(stack *myStack,int x, char op, int y);
int isOperand(char x);

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

int evaluate(char *postfix)
{
    stack *st=(stack*)malloc(sizeof(stack));
    
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
    
    int i = 0;

    while (postfix[i] != '\0'){

        if(isOperand(postfix[i])){
            push(st,postfix[i]-'0');
            display(st, st->top);

        }else{
            if (postfix[i]!='(' && postfix[i]!=')'){
                int n2 = pop(st);
                int n1 = pop(st);
                int ans = operate(st,n1,postfix[i],n2);
                printf("%d\n",ans);

                push(st,ans);
                display(st, st->top);
            }
        }
        i++;
        
    }
    return pop(st);
}

int operate(stack *myStack,int x, char op, int y){
    if (op == '+')
        return x + y;
    else if (op == '-')
        return x - y;
    else if (op == '*')
        return x * y;
    else if (op == '/')
        return x / y;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x=='(' || x==')')
        return 0;
    else
        return 1;
}

int main()
{
    char *postfix = "5(5/(2*1))2*+10-";
    //char *postfix = "2(4*3)+";
    printf("Result is %d", evaluate(postfix));
    return 0;
}
