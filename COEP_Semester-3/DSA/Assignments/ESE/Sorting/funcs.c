#include<stdio.h>

int a[10]={24,24125,251252,12,2,51,52};
int size = 7;

void printArray(int array[],int size){
    printf("\n-------------------\n");
    for(int i=0; i<size; i++){
        printf(" %d ",array[i]);
    }
    printf("\n-------------------\n");
}

void swap(int a[], int size, int pos1, int pos2){
    int temp;
    temp = a[pos1];
    a[pos1]=a[pos2];
    a[pos2]=temp;
}