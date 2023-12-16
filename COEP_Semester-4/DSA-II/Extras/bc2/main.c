#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"

int main(){
	list l;
	initlist(&l);
	int BUFFER = 100;
	char *input = (char*)malloc(sizeof(char)*BUFFER);
	char c;
	char *temp;
	int i = 0;
	while(scanf("%c" , &c)==1 && c!='\n'){
		input[i] = c;
		i++;
		if(i>=BUFFER){
			BUFFER *=2;
			temp = (char*)realloc(input , sizeof(char)*BUFFER);
			if(temp != NULL){
				input = temp;
			}
			else{
				printf("Error\n");
				return 1;
			}
		}
	}
	input[i] = '\0';
	l = eval(input);
	display(l);
	return 0;
}
