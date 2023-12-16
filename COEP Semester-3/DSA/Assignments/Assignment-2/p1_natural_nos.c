#include<stdio.h>
void main(){
	int n;
	int i=0;
	int sum=0;
	printf("Enter a Natural Number:");
	scanf("%d",&n);
	
	printf("\n Calculating Sum of %d Natural Numbers using While Loop: ",n);
	while(i<=n){
		sum+=i;
		i++;
	}
	printf("%d", sum);

	printf("\n Calculating Sum of %d Natural Numbers using For Loop: ",n);
	sum=0;
	for (i=0;i<=n;i++){
		sum+=i;
	}
	
	printf("%d\n", sum);
}
