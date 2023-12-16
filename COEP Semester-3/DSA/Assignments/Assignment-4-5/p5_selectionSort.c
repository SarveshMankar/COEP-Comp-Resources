#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[], int size){
    int temp;
    int max;
    for(int i=0;i<size;i++){
        max=0;
        for (int j=0;j<size-i;j++){
            if(arr[j]>arr[max]){
                max=j;
            }
        }
        temp=arr[max];
        arr[max]=arr[size-i-1];
        arr[size-i-1]=temp;
    }

    printf("\nSorted Array: \n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}
