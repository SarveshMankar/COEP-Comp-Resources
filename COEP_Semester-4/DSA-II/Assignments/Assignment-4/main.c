#include<stdio.h>
#include<stdlib.h>
#include "func.h"

int main(){
    heap *h = (heap*) malloc(sizeof(heap));
    init(h);

    int type;
    printf("\n1. Max Heap\n2. Min Heap\n");
    scanf("%d",&type);

    FILE *fp;
    fp = fopen("data.txt","r");
    if (fp==NULL){
        printf("\nFile not found\n");
        return 0;
    }

    int n;

    if (type==1){
        while(!feof(fp)){
            int data;
            fscanf(fp,"%d",&data);
            maxheap_insert(h, data);
            printf("\nInserted: ");
            display(*h);
        }     

        printf("\nData: ");
        display(*h);

        int t=1;
        while(t){
            printf("\n1. Insert\n2. Delete\n3. Display\n4. Sort in Ascending Order\n5. Sort in Descending Order \n6. Reset \n7. Exit\n\n");
            int ch;
            scanf("%d",&ch);

            switch (ch){
            case 1:
                printf("\nEnter data: ");
                int data;
                scanf("%d",&data);
                maxheap_insert(h, data);
                printf("\nAfter Insert:");
                display(*h);
                break;
            case 2:
                maxheap_delete(h);
                printf("\nAfter Delete: ");
                display(*h);
                break;
            case 3:
                printf("\nDisplay: ");
                display(*h);
                break;
            case 4:
                maxheap_ascendingSortUsingHeap(h);
                printf("\nAfter Sorting in Ascending Order: ");
                display(*h);
                break;
            case 5:
                maxheap_descendingSortUsingHeap(h);
                printf("\nAfter Sorting in Descending Order: ");
                display(*h);
                break;
            case 6:
                init(h);
                printf("\nResetting! ");
                rewind(fp);
                while(!feof(fp)){
                    int data;
                    fscanf(fp,"%d",&data);
                    maxheap_insert(h, data);
                }  
                break;
            case 7:
                t=0;
                break;
            default:
                break;
            }
        }
    }else if (type==2){
        while(!feof(fp)){
            int data;
            fscanf(fp,"%d",&data);
            minheap_insert(h, data);
            printf("Inserted: ");
            display(*h);
        }

        printf("\nData: ");
        display(*h);

        int t=1;
        while(t){
            printf("\n1. Insert\n2. Delete\n3. Display\n4. Sort in Ascending Order\n5. Sort in Descending Order \n6. Reset \n7. Exit\n\n");
            int ch;
            scanf("%d",&ch);

            switch (ch){
            case 1:
                printf("\nEnter data: ");
                int data;
                scanf("%d",&data);
                minheap_insert(h, data);
                printf("\nAfter Insert:");
                display(*h);
                break;
            case 2:
                minheap_delete(h);
                printf("\nAfter Delete: ");
                display(*h);
                break;
            case 3:
                printf("\nDisplay: ");
                display(*h);
                break;
            case 4:
                minheap_ascendingSortUsingHeap(h);
                printf("\nAfter Sorting in Ascending Order: ");
                display(*h);
                break;
            case 5:
                minheap_descendingSortUsingHeap(h);
                printf("\nAfter Sorting in Descending Order: ");
                display(*h);
                break;
            case 6:
                init(h);
                printf("\nResetting! ");
                rewind(fp);
                while(!feof(fp)){
                    int data;
                    fscanf(fp,"%d",&data);
                    minheap_insert(h, data);
                }
                break;
            case 7:
                t=0;
                break;
            default:
                break;
            }
        }
    }else{
        printf("\nInvalid Choice\n");
    } 

    return 0;
    
}