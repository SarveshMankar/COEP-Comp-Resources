#include<stdio.h>

int factorial(int n){
    if (n<=1){
        return 1;
    }
    return n*factorial(n-1);
}

void main(){
    int a=6;
    printf("\nFactorial of %d is %d",a,factorial(a));
}