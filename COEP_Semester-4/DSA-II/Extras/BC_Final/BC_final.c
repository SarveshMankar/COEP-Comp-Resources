#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

#include "myFuncs.c"

int main() {

  // char infix[25]={'\0'};
  char infix[100];

  printf("Enter infix expression\n");

  scanf("%s", infix);

  printf("Printing infix expression\n");

  printf("%s\n", infix);

  printf("Printing postfix expression\n");

  char * postfix = infixToPostfix(infix);

  printf("%s\n", postfix);

  stack s;

  init_stack( & s, 100);

  node * head = evaluate(postfix, s);

  printf("Result:\n");

  print_LL(head);

  printf("\n");

  return 0;

}