#include <stdio.h>
int stack[20];
int top = -1;

void push(int x)
{
	stack[++top] = x;
}

int pop()
{
	return stack[top--];
}

int main()
{
	char exp[20];
	char *expre;
	int num1,num2,num3,num;
	printf("Enter the expression: ");
	scanf("%s",exp);
	expre = exp;
	while(*expre != '\0')
	{
		if(isdigit((*expre)))
		{
			num = *expre- 48;
			push(num);
		}
		else
		{
			num1 = pop();
			num2 = pop();
			switch(*expre
			      )
			{
				case '+':
					{
						num3 = num1 + num2;
						break;
					}
				case '-':
					{
						num3 = num2 - num1;
						break;
					}
				case '*':
					{
						num3 = num1 * num2;
						break;
					}
				case '/':
					{
						num3 = num2 / num1;
						break;
					}
			}
			push(num3);
		}
		expre++;
	}
	printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
	return 0;
}
