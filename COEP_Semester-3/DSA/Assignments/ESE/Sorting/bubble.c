#include <stdio.h>
#include "funcs.c"

void bubbleSort(int a[], int size){
    printf("Array Before Sorting! ");
    printArray(a,size);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if (a[j]>a[i]){
                swap(a,size,i,j);
            }
        }
    }
    printf("Array After Sorting! ");
    printArray(a,size);
}

void main(){
    bubbleSort(a,size);
}