#include<stdio.h>

int main(){
    int n = 15251;
    int temp = n;
    int rev = 0;
    int r;
    while (n>0){
        r=n%10;    
        rev=(rev*10)+r;    
        n=n/10; 
    }

    if (rev==temp){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
}