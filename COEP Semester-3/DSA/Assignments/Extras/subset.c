#include<stdio.h>

int isSubset(int a[], int b[], int sa, int sb){
    //Checking if A is Subset of B
    int i = 0;
    int j = 0;
    for (i = 0; i < sa; i++) {
        for (j = 0; j < sb; j++) {
            if (a[i] == b[j])
                break;
        }
        if (j == sb)
            return 0;
    }
    return 1;
}

int main(){
    int a[4] = {1,2,3};
    int b[5] = {1,2,3,4,5};
    int sa=sizeof(a)/sizeof(a[0]);
    int sb=sizeof(b)/sizeof(b[0]);

    if (sa>sb){
        printf("A is not a Subset of B");
    }
    else{
        int ans = isSubset(a,b,sa,sb);
        if (1){
            printf("A is Subset of B");
        }
        else{
            printf("A is not a Subset of B");
        }
    }

    return 0;
}