#include<stdio.h>
void main(){
	char alphas[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i=0;i<52;i++){
		printf("%c = %d\n",alphas[i],alphas[i]);
	}
}
