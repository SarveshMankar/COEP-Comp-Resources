#include<stdio.h>
void main(){
	int a = 97;
	float b = 97.53;
	int c[] = {1,2,3,4,5,6,7,8,9,0}; // This is an Array
	char d[] = "Sarvesh";

	printf("Size of Integer: %ld\n",sizeof(a));
	printf("Size of Float: %ld\n",sizeof(b));
	printf("Size of Array: %ld\n", sizeof(c));
	printf("Size of String: %ld\n",sizeof(d));
}
