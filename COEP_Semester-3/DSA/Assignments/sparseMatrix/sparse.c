#include<stdio.h>
#include<stdlib.h>

#include "sf.h"
int main(){
	Sparse s,s1;
  printf("Sparse Matrix 1 : \n");
	initSparseMatrix(&s,"i1.txt");
	rowsDisplay(s);
	
  printf("\n");
  printf("Sparse Matrix 2 : \n");
	initSparseMatrix(&s1,"i2.txt");
	rowsDisplay(s1);
	
  printf("\n");
  printf("Addition of 1 and 2 : \n");
	Sparse s3 = addTwoMatrix(s,s1);
	rowsDisplay(s3);
	
  printf("\n");
  printf("Substraction of 1 and 2 : \n");
	Sparse s4 = subtractTwoMatrix(s,s1);
	rowsDisplay(s4);
	
  printf("\n");
	Sparse s5 ;
  printf("Transpose of Matrix 1 : \n");
	transposeMatrix(&s);
	rowsDisplay(s);
  printf("\n");
  printf("Transpose of Matrix 2 : \n");
	transposeMatrix(&s1);
	rowsDisplay(s1);


  printf("\n");
  printf("Sparse Matrix 3 : \n");
	Sparse x1 ;
	initSparseMatrix(&x1,"i2.txt");
  rowsDisplay(x1);
  printf("\n");

	int ans = isSymmetric(x1);
	if(ans){
		printf("\nSymmetric");
	}
	else
		printf("\nNot Symmetric");

}

