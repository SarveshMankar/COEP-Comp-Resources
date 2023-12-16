#include<stdio.h>
void main(){
	int sal;
	printf("Enter the Salary:");
	scanf("%d",&sal);
	printf("\nDA = ");
	if ((sal>=10000) && (sal<=20000)){
		printf("\n%f",0.1*sal);
	}else if ((sal>20000) && (sal<=50000)){
		printf("\n%f",0.15*sal);
	}else if ((sal>50000) && (sal<=100000)){
		printf("\n%f",0.2*sal);
	}else if (sal>100000){
		printf("\nDA Not Given:");
	}
	printf("\n");
	
}
