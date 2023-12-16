#include<stdio.h>
#include<stdlib.h>

void printMaxThreeNums(int arr[], int n){
    int max;
    if(n==1){
        max = arr[0];
        printf("\nThe first distinct maximum number is %d ", max);
        printf("\nThe second distinct maximum number is %d ", max);
        printf("\nThe third distinct maximum number is %d ", max);}
    else if(n==2){
        max = arr[0];
        printf("\nThe first distinct maximum number is %d ", max);
        max = arr[1];
        printf("\nThe second distinct maximum number is %d ", max);
        printf("\nThe third distinct maximum number is %d ", max);}
    else if(n>=3){
        max = arr[0];
        printf("\nThe first distinct maximum number is %d ", max);
        max = arr[1];
        printf("\nThe second distinct maximum number is %d ", max);
        max = arr[2];
        printf("\nThe third distinct maximum number is %d ", max);}
}

// Funtion of Insertion Sort in Descending Order
void insertionSort(int arr[], int n)
{
    printf("\nInsertion Sort in Descending Order");
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] <= key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    printMaxThreeNums(arr, n);
}

// Funtion of Selection Sort in Descending Order
void selectionSort(int arr[], int size){
    printf("\nSelection Sort in Descending Order");
    int temp;
    int max=0;
    for(int i=0;i<size;i++){
        for (int j=0;j<size-i;j++){
            if(arr[j]<arr[max]){
                max=j;
            }
        }
        temp=arr[max];
        arr[max]=arr[size-i-1];
        arr[size-i-1]=temp;
        max=0;
    }

    printMaxThreeNums(arr, size);
}

// Funtion of Bubble Sort in Descending Order
int bubbleSort(int arr[], int size){
    printf("\nBubble Sort in Descending Order");
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[j]<=arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printMaxThreeNums(arr, size);
}

// Function to print an array
void printArray(int arr[], int n)
{
    int i;
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr1[] = { 12, 11, 13, 5, 11, 6 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    insertionSort(arr1, n1);
    printArray(arr1, n1);


    int arr2[] = { 12, 11, 13, 5, 11, 6 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    selectionSort(arr2, n2);
    printArray(arr2, n2);


    int arr3[] = { 12, 11, 13, 5, 11, 6 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    bubbleSort(arr3, n3);
    printArray(arr3, n3);

    return 0;
}