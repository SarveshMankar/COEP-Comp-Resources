#include<stdio.h>
void main(){
	int n=12345;
	int flag=0; //if flag is 1 then the Position from reverse will be Even
	int sum=0;

	while(n!=0){
		if (flag==0){
			flag=1;
			sum+=(n%10);
		}else{
			flag=0;
		}
		n=n-(n%10);
		n=n/10;
	}

	printf("Sum is %d",sum);
}

