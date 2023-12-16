#include <stdio.h>

int main() {
    int n = 153;
    int s=0;
    int i = n;
    int a;
    
    while(i>=1){
        a=i%10;
        s=s+(a*a*a);
        i=i-(i%10);
        i=i/10;
    }
    
    if(s==n){
        printf("%d is an Armstrong Number!",n);
    }else{
        printf("%d is not an Armstrong Number!",n);
    }
    
    return 0;
}