#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int arr[], int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(arr[j]>arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nSorted Array: \n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}