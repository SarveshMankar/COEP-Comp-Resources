#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int size){
    int temp,k;
    for(int j=0;j<size;j++){
        temp = arr[j];
        k = j-1;
        while(k>=0 && temp<arr[k]){
            arr[k+1] = arr[k];
            k--;
        }
        arr[k+1] = temp;
    }

    printf("\nSorted Array: \n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

