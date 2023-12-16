#include<stdio.h>
#include<stdlib.h>

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

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[j]>arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    binarySearch(arr, 0, size, search);
}

/*int main(){
    int size = 11;
    int arr[size];

    //Populating the array using rand function
    for(int i=0; i<size; i++){
        arr[i] = rand()%100;
    }
    binarySearchSorting(arr,size);
    

    printf("\n\nFound %d at %d",arr[3], binarySearch(arr, 0, size-1, arr[3]));
    printf("\nFound %d at %d",arr[5], binarySearch(arr, 0, size-1, arr[5]));
    printf("\nFound %d at %d",arr[7], binarySearch(arr, 0, size-1, arr[7]));
    printf("\nFound %d at %d",685168, binarySearch(arr, 0, size-1, 685168));
    printf("\nFound %d at %d",-1213, binarySearch(arr, 0, size-1, -1213));

    return 0;
}*/