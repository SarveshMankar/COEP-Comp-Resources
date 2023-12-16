#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include "func.c"

char *str;

void main(){
    //32423542387527357982375328975823758+98327582375872358723573278758347658734867348*83975823758327857382758327523/7382-385634986^2%2

    printf("bc 0.0.1");
    printf("\nDeveloped by: Sarvesh Mankar\n");

    while(1){
        char exp[10000];
        
        scanf(" %[^\n]s", exp);
        performCalculations(exp);
    }
}