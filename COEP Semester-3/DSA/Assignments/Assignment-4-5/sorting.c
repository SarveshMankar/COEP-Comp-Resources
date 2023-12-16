#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int size){
    int temp,k;
    for(int j=1;j<size;j++){
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





int bubbleSort(int arr[], int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
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





void selectionSort(int arr[], int size){
    int temp;
    int max=0;
    for(int i=0;i<size;i++){
        for (int j=0;j<size-i;j++){
            if(arr[j]>arr[max]){
                max=j;
            }
        }
        temp=arr[max];
        arr[max]=arr[size-i-1];
        arr[size-i-1]=temp;
        max=0;
    }

    printf("\nSorted Array: \n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}
