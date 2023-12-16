#include<stdio.h>
void main(){

    int n1,n2,maxNum;
    printf("Enter a First Number: ");
    scanf("%d",&n1);
    printf("Enter a Second Number: ");
    scanf("%d",&n2);

    maxNum=(n1>n2)?n1:n2;

    int lcm=0;
    int m1,m2;

    for(int i=1; i<=maxNum;i++){
        m1=n1*i;
        for(int j=1;j<=maxNum;j++){
            m2=n2*j;
            if (m1==m2){
                lcm=m1;
                break;
            }
        }
        if(lcm!=0){
            break;
        }
    }
    printf("LCM of %d and %d is %d\n",n1,n2,lcm);



    int gcd=0;
    for(int i=maxNum;i>=1;i--){
        if ((n1%i==0) && (n2%i==0)){
            gcd=i;
            break;
        }
    }
    printf("GCD of %d and %d is %d\n",n1,n2,gcd);

}