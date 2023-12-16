typedef struct node
{
    int data;
    struct node* next;
} node;

typedef struct operator{
    char op;
} operator;

typedef struct LL{
    node *n1;
    operator *op;
    struct LL *next;
} LL;



void append(node **head, int data);
void evaluate(char str[], node **head1, node **head2);

//Stack Functions
void push(char x);
char pop();
int priority(char x);
char * removeBlanks(char * str);
const char *makePostfixEqation(char *exp, char *ans);

int isInValidEquation(LL *head);

void appendLL(LL **head, node *n1, operator *op);
LL *makeIt(char str[], LL *head);
node *solve(node **hhead1, node **hhead2, operator *myOperator);
void insertTheSolution(LL *head, LL *pos, node *result);
void removeLLNode(LL **head, LL *n1);
int countLLNodes(LL *head);
void displayLL(LL *head);
void displayNode(node *n1);

int isOperator(char c);
void addZeros(node *head1, node *head2);

node *add(node *head1, node *head2, node *result);

node *subtract(node *head1, node *head2,node *result);
void borrow(node **head1);

node *multiply(node *head1, node *head2, node *result);
node *makeAns(char str[], node **mAns);
node *addPlaceZeros(node *sAns, node *zeros);

node *reverse(node *head1);
node *makeList(char str[]);
int compare(node *head1, node *head2);
node *raiseTo(node *head1, node *head2);

node *removeZeros(node *head);
node *removeAllZeros(node *head);

node *divide(node *head1, node *head2);
node *halfDivide(node *head1, node *head2, node **result);
int countNodes(node *head);
int checkIfZero(node *head);
int checkIfNotZero(node *head);
int compareD(node *head1, node *head2);
node *reverseList(node **head);

node *modulus(node *head1, node *head2);

// node *greaterThan(node *hhead1, node *hhead2);

void printHeads(node *head1, node *head2);
void seperator();

void displayAnswer(node *result);
node *makeCopy(node *head);
void displayForTesting(node *head1, node *head2, node *result, char op);

void display(node *head);
node *removeInitialZeros(node *head);

void performCalculations(char exp[]);