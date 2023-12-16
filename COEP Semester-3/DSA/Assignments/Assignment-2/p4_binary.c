#include<stdio.h>
void main(){
    int n;
    int c=0;
    printf("Enter a Decimal Number: ");
    scanf("%d",&n);
    
    while (n!=0){
        if (n%2==1){
            c+=1;
        }
        n=n-(n%2);
        n=n/2;
    }

    printf("Number of 1's is: %d",c);
}