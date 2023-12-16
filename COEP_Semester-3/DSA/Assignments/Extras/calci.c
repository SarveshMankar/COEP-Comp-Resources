#include<stdio.h>

int main(){
    int n1=10;
    int n2=5;
    int ans=0;

    char opt;
    printf("Enter the operator: ");
    scanf("%c",&opt);

    switch (opt)
    {
    case '+':
        ans=n1+n2;
        break;
    case '-':
        ans=n1-n2;
        break;
    case '*':
        ans=n1*n2;
        break;
    case '/':
        ans=n1/n2;
        break;
    case '%':
        ans=n1%n2;
        break;
    case '|':
        ans=n1|n2;
        break;

    default:
        printf("Invalid Option!");
    }

    printf("Answer: %d",ans);

    return 0;
}