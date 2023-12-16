#include<stdio.h>

void main(){
	int dayNo;
	printf("Enter a Number of Day in Week\n");
	scanf("%d",&dayNo);
	
	switch(dayNo){
		case 1:
			printf("Monday");
			break;
		case 2:
			printf("Tuesday");
			break;
		case 3:
			printf("Wednesday");
			break;
		case 4:
			printf("Thursday");
			break;
		case 5:
			printf("Friday");
			break;
		case 6:
			printf("Saturday");
			break;
		case 7:
			printf("Sunday");
			break;
		default:
			printf("There are only 7 days in a Week!");
	}
	printf("\n");
}
