#include<stdio.h>
#include<stdlib.h>

#include "sorting.c"
#include "searching.c"


int main(){
    int size = 10;
    int arr[size];
    int search;

    //Populating the array using rand function
    for(int i=0; i<size; i++){
        arr[i] = rand()%100;
    }
    //Printing the array
    printf("\nArray: ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    int opt;
    printf("\n\n\t1: Linear Search \n\t2: Binary Search \n\t3: Insertion Sort \n\t4: Bubble Sort \n\t5: Selection Sort");
    printf("\n\nEnter a Valid Options from 1 to 5: ");
    scanf("%d",&opt);

    switch (opt){
    case 1:
        printf("Enter Integer to Search: ");
        scanf("%d",&search);

        linearSearch(arr, size, search);
        break;

    case 2:
        printf("Enter Integer to Search: ");
        scanf("%d",&search);

        sorting(arr, size, search);
        printf("\nFound %d at Index %d",search, binarySearch(arr, 0, size-1, search));
        break;

    case 3:
        insertionSort(arr, size);
        break;

    case 4:
        bubbleSort(arr, size);
        break;

    case 5:
        selectionSort(arr, size);
        break;
    
    default:
        printf("Invalid Option!");
        break;
    }

    return 0;
}