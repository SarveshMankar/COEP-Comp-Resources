#include<stdio.h>
#include<string.h>
void main(){
    char word[100];
    printf("Enter a Word: ");
    scanf("%s",&word);
    
    printf("In Upper Case: %s\n",strupr(word));
    printf("In Lower Case: %s\n",strlwr(word));

}