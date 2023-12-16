#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"functions.h"

void initlist(list *l){
	*l = NULL;
	return;
}

void append(list *l , char c){
	node *nn = (node*)malloc(sizeof(node));
	if(!nn)
		return;
	nn->data = c;
	nn->next = NULL;
	if(!(*l)){
		*l = nn;
		return;
	}
	node *p = *l;
	while(p->next)
		p = p->next;
	p->next = nn;
	return;
}

void reverselist(list *l){
	if(!(*l) || !((*l)->next)) return;
        node *p , *q , *temp;
        p = *l;
        q = p->next;
        temp = NULL;
        p->next = NULL;
        while(q){
                temp = q->next;
                q->next = p;
                p = q;
                q = temp;
        }
        *l = p;
        return;
}

int isGreater(list l1 ,list l2){
	if(l1->data == '-'){
		if(length(l1->next) > length(l2))
			return 1;
		else if(length(l1->next) == length(l2)){
			node *p = l1->next;
                	node *q = l2;
                	while(p&&q){
                        	if((p->data - '0')<(q->data - '0'))
                                	return 0;
                        	else if((p->data - '0')>(q->data - '0'))
                                	return 1;
                        	p = p->next;
                        	q = q->next;
                	}
		}
		else
			return 0;
	}
	if(l2->data == '-'){
		if(length(l1) > length(l2->next))
                        return 1;
                else if(length(l1) == length(l2->next)){
                        node *p = l1;
                        node *q = l2->next;
                        while(p&&q){
                                if((p->data - '0')<(q->data - '0'))
                                        return 0;
                                else if((p->data - '0')>(q->data - '0'))
                                        return 1;
                                p = p->next;
                                q = q->next;
                        }
                }
                else
                        return 0;
	}
}

int length(list l){
	int i = 0;
	if(!l)
		return 0;
	node *p = l;
	while(p){
		p = p->next;
		i+=1;
	}
	return i;
}

void display(list l){
	if(!l)
		return;
	node *p = l;
	while(p){
		printf("%c" , p->data);
		p = p->next;
	}
	return;
}

void init_list_stack(list_stack *s){
	*s = NULL;
	return;
}

int isEmpty(list_stack s){
	if(s==NULL)
		return 1;
	return 0;
}

void list_push(list_stack *s , list l){
	snode *nn = (snode*)malloc(sizeof(snode));
	if(!nn)
		return;
	nn->l = l;
	nn->next = NULL;
	if(!s){
		*s = nn;
		return;
	}
	nn->next = *s;
	*s = nn;
	return;
}

list list_pop(list_stack *s){
	if(!(*s))
		return NULL;
	snode *p = *s;
	list l;
	initlist(&l);
	l = p->l;
	*s = p->next;
	//free(p);
	return l;
}

void init_char_stack(char_stack *s , int size){
	s->A = (char *)malloc(sizeof(char)*size);
	s->size = size;
	s->top = -1;
	return;
}

int isEmptyChar(char_stack s){
	return (s.top == -1);
}

void char_push(char_stack *s , char c){
	if(s->top == (s->size-1))
		s->A = (char *)realloc(s->A , sizeof(char)*s->size);
	s->top++;
	s->A[s->top] = c;
	return;
}

char char_pop(char_stack *s){
	if(isEmptyChar(*s))
		return '\0';
	char c = s->A[s->top];
	s->top--;
	return c;
}

list add(list l1 , list l2){
	list l3;
	initlist(&l3);
	if(!l1 && !l2) return l3;
	if(l1->data == '-'){
		l3 = subtract(l2,l1->next);
		return l3;
	}
	if(l2->data == '-'){
		l3 = subtract(l1 , l2->next);
		return l3;
	}
	reverselist(&l1);
	reverselist(&l2);
	node *p = l1;
	node *q = l2;
	int sum;
	int carry = 0;
	while(p && q){
		sum = ((p->data - '0') + (q->data - '0')+ carry)/10;
		carry = ((p->data - '0') + (q->data - '0')+ carry)%10;
		append(&l3 , sum + '0');
		p = p->next;
		q = q->next;
	}
	while(p){
		sum = ((p->data - '0') + carry)/10;
		carry = ((p->data - '0') + carry)%10;
		append(&l3 , sum + '0');
		p = p->next;
	}
	while(q){
		sum = ((q->data - '0') + carry)/10;
                carry = ((q->data - '0') + carry)%10;
                append(&l3 , sum + '0');
                q = q->next;
	}
	reverselist(&l1);
	reverselist(&l2);
        reverselist(&l3);
        return l3;
}

list multiply(list l1 , list l2){
	list l3;
	list l4;
	list l5;
	initlist(&l3);
	initlist(&l4); 
	initlist(&l5);
	int carry = 0;
	int product;
	if(!l1 || !l2) return l3;
	if(l1->data == '-'){
		l3 = multiply(l1->next , l2);
		reverselist(&l3);
		append(&l3 , '-');
		reverselist(&l3);
		return l3;
	}
	if(l2->data == '-'){
		l3 = multiply(l1,l2->next);
                reverselist(&l3);
                append(&l3 , '-');
                reverselist(&l3);
                return l3;
	}
	reverselist(&l1);
	reverselist(&l2);
	node *p = l1;
	node *q = l2;
	while(q){
		while(p){
			product = ((q->data - '0')*(p->data - '0') + carry)%10;
			carry = ((q->data - '0')*(p->data - '0') + carry)/10;
			append(&l4 , product + '0');
			p = p->next;
		}
		if(carry!=0){
			while(carry>=10){
				append(&l4 , (carry%10) + '0');
				carry = carry/10;
			}
			append(&l4 , carry + '0');
			carry = carry/10;
		}
		p = l1;
		l3 = add(l3 , l4);
		l4 = NULL;
		append(&l5 , '0');
		l4 = l5;
		q = q->next;
	}
	reverselist(&l1);
	reverselist(&l2);
	reverselist(&l3);
	return l3;
}

list divide(list l1 , list l2){
	list l3;
	initlist(&l3);
	if(l1->data == '-'){
		l3 = divide(l1->next , l2);
                reverselist(&l3);
                append(&l3 , '-');
                reverselist(&l3);
                return l3;
	}
	if(l2->data == '-'){
		l3 = divide(l1 , l2->next);
                reverselist(&l3);
                append(&l3 , '-');
                reverselist(&l3);
                return l3;
	}
	if(!l2 || (length(l2)==1 && l2->data == 0 + '0')){
		printf("Division by Zero!!!");
		return NULL;
	}
	node *p = l1;
	node *q = l2;
	list l4;
	initlist(&l4);
	append(&l4 , 1 + '0');
	while(isGreater(p,q)==1){
		p = subtract(p,q);
		l3 = add(l3 , l4);
	}
	return l3;
}

list subtract(list l1 , list l2){
	list l3;
	initlist(&l3);
	if(l1->data == '-'){
		l3 = add(l1->next , l2);
                reverselist(&l3);
                append(&l3 , '-');
                reverselist(&l3);
                return l3;
	}
	if(l2->data == '-'){
		l3 = add(l1 , l2->next);
		return l3;
	}
	if(isGreater(l2,l1) == 1){
		l3 = subtract(l2,l1);
                reverselist(&l3);
                append(&l3 , '-');
                reverselist(&l3);
                return l3;
	}
	reverselist(&l1);
	reverselist(&l2);
	node *p = l1;
	node *q = l2;
	int diff = 0;
	int borrow = 0;
	while(p&&q){
		if(borrow == 1)
			p->data = (((p->data - '0')-1) + '0');
		if(p->data >= q->data){
			diff = (p->data - '0')-(q->data - '0');
			borrow = 0;
			append(&l3 , diff + '0');
		}
		else{
			diff = ((p->data - '0') + 10) - (q->data - '0');
			borrow = 1;
			append(&l3 , diff + '0');
		}
		p = p->next;
		q = q->next;
	}
	while(p){
		if(borrow == 1){
			p->data = (((p->data - '0')-1) + '0');
		}
		borrow = 0;
		append(&l3 , p->data);
		p = p->next;
	}
	reverselist(&l1);
	reverselist(&l2);
	reverselist(&l3);
	return l3;
}

int precedence(char c){
	switch(c){
		case '^':
			return 3;
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
	}
	return -1;
}

list calc(list_stack num , char_stack op){
	list l1;
	list l2;
	char ope;
	initlist(&l1);
	initlist(&l2);
	l1 = list_pop(&num);
	l2 = list_pop(&num);
	ope = char_pop(&op);
	switch(ope){
		case '+':
			return add(l1,l2);
		case '-':
			return subtract(l2,l1);
		case '*':
			return multiply(l1,l2);
		case '/':
			return divide(l2,l1);
	}
	return NULL;
}

list eval(char input[]){
	long len = strlen(input);
	list_stack num;
	init_list_stack(&num);
	char_stack op;
	init_char_stack(&op , 100);
	list l1;
	initlist(&l1);
	long i;
	if(input[0] == '+' || input[0] == '*' || input[0] == '/'){
		printf("Syntax Error !!!!!\n");
		return NULL;
	}
	if(input[0] == '-'){
		append(&l1 , '-');
	}
	for(i = 0 ; i<len ; i++){
		if(isdigit(input[i])){
			while(isdigit(input[i])){
				append(&l1 , input[i]);
				i++;
			}
			list_push(&num , l1);
			//free(l1);
		}
		if(!isdigit(input[i]) && i!=0){
			if(input[i] == '+' ||input[i] == '-' ||input[i] == '*' ||input[i] == '/'){
				while(!isEmptyChar(op) && precedence(op.A[op.top])>=precedence(input[i])){
					l1 = calc(num,op);
					list_push(&num,l1);
					//free(l1);
				}
				char_push(&op,input[i]);
			}
			if(input[i] == '(')
				char_push(&op , input[i]);
			if(input[i] == ')'){
				while(op.A[op.top]!='('){
					l1 = calc(num,op);
					list_push(&num,l1);
					//free(l1);
				}
				char_pop(&op);
			}
		}
		while(!isEmptyChar(op)){
			l1 = calc(num,op);
			list_push(&num,l1);
			//free(l1);
		}

	}
	return list_pop(&num);
}

