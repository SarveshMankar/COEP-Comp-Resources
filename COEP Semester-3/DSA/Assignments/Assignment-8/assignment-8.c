#include<stdio.h>
#include<stdlib.h>

void newLine(){
    printf("\n");
}

void push(char stack[], int *top, int size, char data){
    if(*top == size-1){
        printf("\nStack Overflow\n");}
    else{
        *top = *top + 1;
        stack[*top] = data;
    }
}

int pop(char stack[], int *top){
    if(*top == -1){
        printf("\nStack Underflow\n");
        return -1;
    }
    else{
        int data = stack[*top];
        *top = *top - 1;
        return data;
    }
}

int isPalindrome(char stack[], int top){
    if (top==-1){
        printf("Stack Underflow");
    }
    else{
        for(int i = top; i >= 0; i--){
            if (stack[i]!=stack[top-i-1]){
                return 0;
            }
        }
        return 1;
    }
}

int popDisplay(char stack[], int top){
    if(top == -1){
        printf("\nStack Underflow\n");
        return -1;
    }
    else{
        int data = stack[top];
        printf("%c ", data);
        return data;
    }
}


void display(char stack[], int top){
    if(top == -1){
        printf("\nStack is Empty\n");
    }
    else{
        for(int i = top; i >= 0; i--){
            printf("%c", stack[i]);
        }
    }
}

int main()
{
    printf("Enter the size of Stack: ");
    int size;
    scanf("%d", &size);
    char stack[size];
    int top = -1;

    char string[size];
    printf("Enter the string: ");
    scanf("%s", string);

    int stringSize = 0;
    for(int i = 0; string[i] != '\0'; i++){
        stringSize++;
    }

    for(int i = 0; i <= stringSize; i++){
        push(stack, &top, size, string[i]);
    }

    printf("\nReverse of String: ");
    display(stack, top);

    newLine();
    if (isPalindrome(stack,top)){
        printf("String is Palindrome!");
    }else{
        printf("String is not Palindrome!");
    }

    return 0;
}