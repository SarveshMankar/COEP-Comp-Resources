#include<stdio.h>
#include "funcs.c"

void insertionSort(int a[], int size){

    printf("Array Before Sorting! ");
    printArray(a,size);

    int key,j;
    for (int i = 1; i < size; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    printf("Array After Sorting! ");
    printArray(a,size);   

}

void main(){
    insertionSort(a,size);
}