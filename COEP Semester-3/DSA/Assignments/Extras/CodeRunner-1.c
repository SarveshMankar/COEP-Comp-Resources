#include <stdio.h>

int Binary_Search(int A[], int s, int key){
 // write your code here   
    int mid = s/2;
 
    if (A[mid]==key){return 1;}

    if (s<=1){
        return 0;
    }

    if(key>A[mid]){
        int s1=s-mid;
        int B[s1];
        int f=0;
        for(int i=mid+1; i<s;i++){
            B[f]=A[i];
            f++;
        }
        return Binary_Search(B,s1,key);
    }
    else if(key<A[mid]){
        int s1=s-mid;
        int B[s1];
        int f=0;
        for(int i=0; i<s1;i++){
            B[f]=A[i];
            f++;
        }
        return Binary_Search(B,s1,key);
    }
    return 0;
}

int main(){
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int key = 15;
    int s = 10;
    
    int result = 0;
    result = Binary_Search(A,s,key);
    printf("%d",result);
}