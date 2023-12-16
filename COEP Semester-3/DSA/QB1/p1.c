#include<stdio.h>

int main(){
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int *p = A;
    int **q = &p;

    printf("Before: %d", A[5]);

    *(q+6) = (int) 15;
    printf("\nAfter: %d", A[5]);

    return 0;
}
