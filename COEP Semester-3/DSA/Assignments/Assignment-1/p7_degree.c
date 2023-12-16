#include<stdio.h>
void main(){
	float f;
	printf("Enter Temperature in Fahrenheit: ");
	scanf("%f",&f);
	
	printf("\nDegree into Celsius is: %f",((f-32)*5)/9);
}
