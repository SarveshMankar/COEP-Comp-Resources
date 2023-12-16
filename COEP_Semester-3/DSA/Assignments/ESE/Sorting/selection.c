#include<stdio.h>
#include "funcs.c"

void selectionSort(int a[], int size){

    printf("Array Before Sorting! ");
    printArray(a,size);

    int max;
    for (int i=0;i<size;i++){
        max=0;
        for(int j=0; j<size-i; j++){
            if (a[j]>a[max]){
                max=j;
            }
        }
        swap(a,size,max, size-i-1);
    }

    printf("Array After Sorting! ");
    printArray(a,size);
}


void main(){
    selectionSort(a,size);
}