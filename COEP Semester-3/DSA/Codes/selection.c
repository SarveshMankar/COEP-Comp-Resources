#include<stdio.h>

void selectionSort(int[], int);

void main(){
    int arr[5]={20,40,28,49,10};
    int size=5;
    selectionSort(arr,size);

}

void selectionSort(int arr[], int size){
    int temp;
    int max=0;
    int s=size;
    for(int i=0;i<size-1;i++){
        if (arr[i]>arr[i+1]){
            max=i;

            temp=arr[max];
            arr[max]=arr[s-1];
            arr[s-1]=temp;
        }       
    }
    
    for(int i=0; i<size;i++){
        printf("%d\t",arr[i]);
    }
}