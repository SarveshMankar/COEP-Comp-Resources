#include<stdio.h>
#include<limits.h>

int main(){
    unsigned int a = INT_MIN;
    int b = INT_MAX;
    int c;
    printf("The minimum value of int is %d", a);
    printf("\nThe maximum value of int is %d", b);
    printf("\n%d",c);
    printf("\n%ld", sizeof(c));
}