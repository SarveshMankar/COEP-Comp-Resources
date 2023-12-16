typedef struct node{
	char data;
	struct node* next;
}node;
typedef node* list;

typedef struct snode{
	list l;
	struct snode*next;
}snode;
typedef snode* list_stack;

typedef struct char_stack{
	char *A;
	int top;
	int size;
}char_stack;

void initlist(list *l);
void append(list *l , char c);
void reverselist(list *l);
int isGreater(list l1 ,list l2);
int length(list l);
void display(list l);

void init_list_stack(list_stack *s);
void list_push(list_stack *s , list l);
list list_pop(list_stack *s);
int isEmpty(list_stack s);

void init_char_stack(char_stack *s , int size);
void char_push(char_stack *s , char c);
char char_pop(char_stack *s);
int isEmptyChar(char_stack s);

list add(list l1 , list l2);
list multiply(list l1 , list l2);
list divide(list l1 , list l2);
list subtract(list l1 , list l2);
list calc(list_stack num , char_stack op);
list eval(char input[]);

