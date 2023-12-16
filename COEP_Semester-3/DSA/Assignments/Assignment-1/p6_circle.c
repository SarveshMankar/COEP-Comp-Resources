#include<stdio.h>
void main(){
	const float pi = 3.14;
	float r;
	printf("Enter radius of Circle:");
	scanf("%f",&r);
	
	printf("\n Circumference of Circle with radius %3f is = %f",r,2*pi*r);
	printf("\n");
	printf("\n Area of Circle with radius %3f is = %f",r,pi*r*r);
	printf("\n");
}
