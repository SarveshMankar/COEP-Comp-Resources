#include<stdio.h>

void bubbleSort(int[], int);

void main(){
    int arr[5]={20,40,28,49,10};
    int size=5;
    bubbleSort(arr,size);

}

void bubbleSort(int arr[], int size){
    int temp;
    for(int i=1;i<=size;i++){
        for(int j=0;j<size-i;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
     }
    
    for(int i=0; i<size;i++){
        printf("%d\t",arr[i]);
    }
}