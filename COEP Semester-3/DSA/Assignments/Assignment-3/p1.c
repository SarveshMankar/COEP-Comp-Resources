#include<stdio.h>
#define size 10

void arrayPrint(int arr[size]){
    printf("\nThe Original array is: ");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}

void main(){
    int arr1[size] = {30,55,22,70,85};
    arrayPrint(arr1);
    printf("\n");

    //Question 1 : Reverse the array
    for(int i=0;i<5;i++){
        printf("%d ",arr1[4-i]);
    }
    printf("\n");

    //Question 2 : Find Greatest and Smallest
    int maxNo=arr1[0];
    int minNo=arr1[0];
    for(int j=0;j<5;j++){
        if (arr1[j]>maxNo){
            maxNo=arr1[j];
        }
        if (arr1[j]<minNo){
            minNo=arr1[j];
        }
    }
    printf("\nMax: %d",maxNo);
    printf("\nMin: %d\n",minNo);

    int arr2[size] = {20,500,60,100,40};
    arrayPrint(arr2);
    printf("\n");

    //Question 3 : Descending Pyramid
    int n=5;
    for(int i=0;i<5;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr2[j]);
        }
        n-=1;
        printf("\n");
    }

    //Question 4 : Sum of Even Elements
    int arr3[size] = {30,55,22,70,85};
    arrayPrint(arr3);
    printf("\n");

    int sum=0;
    for(int i=0;i<5;i++){
        if(arr3[i]%2==0){
            sum+=arr3[i];
        }
    }
    printf("Sum of Even Elements: %d",sum);
}