#include<stdio.h>
void main(){
	char c;
	printf("Enter a Character:");
	scanf("%c",&c);

	printf("\nNow Checking using If Else Statement\n");
	if(c==('a') || c==('e') || c==('i') || c==('o') || c==('u')){
		printf("Vowel Detected!\n");
	}else{
		printf("Consonant Detected!\n");
	}

	printf("Now Checking using Switch Case Statement\n");
	switch(c){
		case 'a':
			printf("Vowel Detected!\n");
			break;
		case 'e':
			printf("Vowel Detected!\n");
			break;
		case 'i':
			printf("Vowel Detected!\n");
			break;
		case 'o':
			printf("Vowel Detected!\n");
			break;
		case 'u':
			printf("Vowel Detected!\n");
			break;
		default:
			printf("Consonant Detected!\n");			
	}
}
