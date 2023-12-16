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





int binarySearch(int arr[], int l, int r, int search){

    int mid = (l+r)/2;
    if(l>r || l<0 || r<0){
        return -1;
    }
    if (arr[mid] == search){
        return mid;
    }else if(arr[mid] > search){
        return binarySearch(arr, l, mid-1, search);
    }else{
        return binarySearch(arr, mid+1, r, search);
    }

}

void sorting(int arr[], int size, int search){
    int temp;

    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            if(arr[j]>arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    binarySearch(arr, 0, size, search);
}
