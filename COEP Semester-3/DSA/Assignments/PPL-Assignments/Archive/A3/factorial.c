#include <stdio.h>

int factorial(int n)
{
    if (n >= 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main()
{

    int num = 6;
    int fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);
    return 0;
}