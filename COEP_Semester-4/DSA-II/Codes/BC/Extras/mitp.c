#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#include<ctype.h>

char stack[100];
int top = -1;

char *mAnsString;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

char * removeBlanks(char * str){
    int i, j;
    char * newString;

    int max_size = strlen(str);
    

    newString = (char *)malloc(max_size);

    i = 0;
    j = 0;

    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            newString[j] = ' ';
            j++;

            while(str[i] == ' ')
                i++;
        }

        newString[j] = str[i];

        i++;
        j++;
    }

    newString[j] = '\0';

    return newString;
}

int main() {
    // char *exp="(a+b)*c+(d-a)";;
    char * exp = "(100+45)*6+(45-12)";
    char * e, x, t;
    char ans[100];
    int k = 0;
    int i = 0;
    printf("\n");
    e = exp;

    while ( * e != '\0') {

        if (isalnum( * e)) {
            x = * e;
            ans[k++] = x;
        } else if ( * e == '(') {

            push( * e);
        } else if ( * e == ')') {
            while ((x = pop()) != '(') {
                ans[k++] = ' ';
                ans[k++] = x;
                ans[k++] = ' ';
            }
        } else {
            ans[k++] = ' ';
            while (priority(stack[top]) >= priority( * e)) {
                t = pop();
                ans[k++] = t;
                ans[k++] = ' ';
            }
            push( * e);
        }
        e++;
        i++;

    }

    while (top != -1) {
        x = pop();
        ans[k++] = x;
    }

    printf("\n%s", ans);
    mAnsString=removeBlanks(ans);
    printf("\n%s", mAnsString);

    return 0;
}