typedef struct node {
  int data;
  struct node * next;
}
node;

typedef struct stack {

  node * * arr;

  int size;

  int top;

}
stack;

struct ss {
  int size;
  int top;
  char * arr;
};

void print_LL(node * head);
node * ReverseLL(node * head);
int length(node * head);
node * add(node * first, node * second);
node * addTwoLists(node * first, node * second);
node * subtract_LL(node * head1, node * head2);
node * multiplyLL(node * head1, node * head2);
node * copy_LL(node * head);
char * check(node * head1, node * head2);
node * divide(node * head1, node * head2);
void init_stack(stack * s, int size);
int isEmpty(stack s);
void push(stack * s, node * head);
node * pop(stack * s);
int isOperator(char ch);
int isOperand(char ch);
node * evaluate(char postfix[], stack s);
int stackTop(struct ss * sp);
int isEMPTY(struct ss * ptr);

int isFULL(struct ss * ptr);
void PUSH(struct ss * ptr, char val);
char POP(struct ss * ptr);
int precedence(char ch);
char * infixToPostfix(char * infix);