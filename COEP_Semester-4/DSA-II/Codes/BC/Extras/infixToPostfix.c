#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
    printf(" ");
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main(){
    // char *exp="(a+b)*c+(d-a)";;
    char *exp="(100+45)*6+(45-12)";;
    char *e, x, t;

    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e)){
            x=*e;
            printf("%c",x);
        }
        else if(*e == '('){
            push(*e);
        }
        else if(*e == ')'){
            while((x = pop()) != '(')
                printf(" %c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e)){
                t=pop();
                printf(" %c ",t);
            }
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }
    
    return 0;
}
