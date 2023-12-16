#include<stdio.h>
void main(){
	int n1=10;
	int n2=20;
	int n3=30;
	int big;

	big = n1>n2?(n1>n3?n1:n3) : (n2>n3?n2:n3);

	printf("Biggest Number is %d",big);
}
