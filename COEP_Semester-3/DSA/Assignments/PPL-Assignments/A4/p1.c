#include<stdio.h>
;
void number(int *n){
	*n=100;
}

int main(){
	int n=100;
	number(&n);
}
