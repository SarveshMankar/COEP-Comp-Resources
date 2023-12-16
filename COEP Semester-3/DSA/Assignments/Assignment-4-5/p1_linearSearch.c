#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[], int size, int key){
    int i;
    int result = -1;
    for(i=0; i<=size; i++){
        if(arr[i] == key){
            result=i;
            break;
        }
    }

    if(result == -1){
        printf("\nElement is not present in array");
    }
    else{
        printf("\nElement is present at index %d", result);
    }
}
