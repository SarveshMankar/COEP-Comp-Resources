#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include"func.h"

// Old Append Function
void append(node **head, int data){
    node *nn = (node *)malloc(sizeof(node));
    nn->data=data;
    nn->next=NULL;

    if(*head==NULL){
        *head=nn;
    }else{
        node *temp = (node *)malloc(sizeof(node));
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }
}

// Old Evaluate Function
void evaluate(char str[], node **head1, node **head2){
    *head1=*head2=NULL;

    int len=strlen(str);
    int j=0;
    while (!(isOperator(str[j])))
        j++;
    //printf("Operator Index=%d",j);
    
    int i=j-1;
    for(i;i>=0;i--){
        if (isOperator(str[i])){
            break;
        }else{
            append(&(*head1),str[i]-'0');
        }
    }

    i=len-1;
    for(i;i>=j;i--){
        if (isOperator(str[i])){
            break;
        }else{
            append(&(*head2),str[i]-'0');
        }
    }
}

//Check if Equation is Valid
int isInValidEquation(LL *head){
    LL *temp = (LL*)malloc(sizeof(LL));
    temp=head;
    int operators=0;
    int operands=0;
    while (temp)
    {
        if(temp->n1!=NULL){
            operands++;
        }else if (temp->op!=NULL){
            operators++;
        }
        
        temp=temp->next;
    }

    if(operators+1==operands){
        return 0;
    }else{
        return 1;
    }
}


//Postfix Evaluation

char stack[10000];
int top = -1;

char *mAnsString;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/' || x=='%')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

char * removeBlanks(char * str){
    int i, j;
    char * newString;

    int max_size = strlen(str);
    

    newString = (char *)malloc(max_size);

    i = 0;
    j = 0;

    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            newString[j] = ' ';
            j++;

            while(str[i] == ' ')
                i++;
        }

        newString[j] = str[i];

        i++;
        j++;
    }

    newString[j] = '\0';

    return newString;
}


//Create Postfix Equation
const char *makePostfixEqation(char *exp, char *ans){
    char * e, x, t;
    int k = 0;
    int i = 0;
    e = exp;

    while ( * e != '\0') {

        if (isalnum( * e)) {
            x = * e;
            ans[k++] = x;
        } else if ( * e == '(') {

            push( * e);
        } else if ( * e == ')') {
            while ((x = pop()) != '(') {
                ans[k++] = ' ';
                ans[k++] = x;
                ans[k++] = ' ';
            }
        } else {
            ans[k++] = ' ';
            while (priority(stack[top]) >= priority( * e)) {
                t = pop();
                ans[k++] = ' ';
                ans[k++] = t;
                ans[k++] = ' ';
            }
            push( * e);
        }
        e++;
        i++;

    }

    while (top != -1) {
        x = pop();
        ans[k++] = ' ';
        ans[k++] = x;
        ans[k++] = ' ';
    }

    top = -1;

    return ans;
}


//Append Function for LL

void appendLL(LL **head, node *n1, operator *op){
    if (n1 == NULL && op == NULL){
        // printf("Both are NULL so nothing to append");
        return;
    }else{
        LL *newNode = (LL *)malloc(sizeof(LL));
        newNode->n1 = n1;
        newNode->op = op;
        newNode->next = NULL;

        if(*head == NULL){
            *head = newNode;
        }
        else{
            LL *temp = *head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}


//Display Function for LL
void displayLL(LL *head){
    LL *temp = head;
    while(temp != NULL){
        if (temp->n1 != NULL){
            displayNode(temp->n1);
            // printf("\n");
        }
        if (temp->op != NULL){
            // printf("%c", temp->op->op);
            // printf("\n");
        }
        temp = temp->next;
    }
}

//Display Function for Node
void displayNode(node *n1){
    node *temp = n1;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}


//Create Postfix Equation
LL *makeIt(char str[], LL *head){
    int len = strlen(str);

    node *n1 = (node *)malloc(sizeof(node));
    n1=NULL;    

    for(int i=0; i<len; i++){
        if(!(isOperator(str[i]))){
            if(str[i]!=' '){
                append(&n1, str[i]-'0');
            }
            if (str[i]==' '){
                operator *op = (operator *)malloc(sizeof(operator));
                op=NULL;
                n1=reverse(n1);
                appendLL(&head, n1, op);
                n1=NULL;
            }
        }
        if(isOperator(str[i])){
            operator *op = (operator *)malloc(sizeof(operator));
            op->op = str[i];
            n1=NULL;
            appendLL(&head, n1, op);
            op=NULL;
        }
    }

    return head;
}


//Count the number of nodes in LL
int countLLNodes(LL *head){
    int count = 0;
    LL *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}


// Insert the solution node in the LL
void insertTheSolution(LL *head, LL *pos, node *result){
    LL *newNode = (LL *)malloc(sizeof(LL));
    newNode->n1 = result;
    newNode->op = NULL;
    newNode->next = pos->next;
    pos->next = newNode;
}


// Remove the node from the LL
void removeLLNode(LL **head, LL *n1){
    LL *temp = (LL *)malloc(sizeof(LL));
    temp = *head;
    if (temp == n1){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp->next != n1){
        temp = temp->next;
    }
    temp->next = n1->next;
    free(n1);
}


//Solve the equation
node *solve(node **hhead1, node **hhead2, operator *myOperator){
    node *head1 = (node *)malloc(sizeof(node));
    head1 = makeCopy(*hhead1);

    node *head2 = (node *)malloc(sizeof(node));
    head2 = makeCopy(*hhead2);

    node *temp=(node *)malloc(sizeof(node));
    temp=NULL;

    node *result=(node *)malloc(sizeof(node));
    result=NULL;

    char op = myOperator->op;

    addZeros(head1,head2);

    if (op=='+'){
        result=add(head1,head2,temp);
    }else if(op=='-'){
        result=subtract(head1,head2,temp);
    }else if(op=='*'){
        result=multiply(head1,head2,temp);
    }else if(op=='/'){
        result=divide(head1,head2);
    }else if(op=='^'){
        result=raiseTo(head1,head2);
    }else if(op=='%'){
        result=modulus(head1,head2);
    }
    return result;
}


//Remove the initial zeros from the node
node *removeInitialZeros(node *head){
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    if(checkIfNotZero(temp)){
        while(temp->data == 0){
            temp = temp->next;
        }
    }
    return temp;
}


// Display the final answer
void display(node *head){
    while (head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}


// Check if the character is an operator
int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^'){
        return 1;
    }else{
        return 0;
    }
}


// Remove Zeroes
node *removeZeros(node *head){
    node *rhead=(node *)malloc(sizeof(node));
    rhead=reverse(head);

    node *rtemp = (node *)malloc(sizeof(node));
    rtemp=rhead;
    if(rtemp->next!=NULL && rtemp->next->next!=NULL && rtemp->data==0 && rtemp->next->data==0){
        while (rtemp->next->next!=NULL && rtemp->next->next->data==0){
            rtemp=rtemp->next;
        }   
        rhead=rtemp->next;
    }

    rhead=reverse(rhead);

    return rhead;
}


// Remove all the zeroes
node *removeAllZeros(node *head){
    node *rhead=(node *)malloc(sizeof(node));
    rhead=reverse(head);

    node *rtemp = (node *)malloc(sizeof(node));
    rtemp=rhead;
    if(rtemp->next!=NULL){
        while (rtemp->next!=NULL && rtemp->next->data==0)
        {
            rtemp=rtemp->next;
        }   
    }

    rhead=rtemp->next;
    rhead=reverse(rhead);

    return rhead;
}


// Add extra zeros to match the number of digits
void addZeros(node *head1, node *head2){
    int c1=0;
    node *temp = (node*) malloc(sizeof(node));
    temp=head1;
    while (temp!=NULL){
        c1++;
        temp=temp->next;
    }

    int c2=0;
    temp=head2;
    while (temp!=NULL){
        c2++;
        temp=temp->next;
    }
    
    int i;
    if (c1>c2){
        for(i=c2;i<c1;i++){
            append(&(head2),0);
        }
    }else{
        for(i=c1;i<c2;i++){
            append(&(head1),0);
        }
    }
    append(&(head1),0);
    append(&(head2),0);
}


// Add the two numbers
node *add(node *hhead1, node *hhead2, node *result){
    result=NULL;
    node *head1 = (node *)malloc(sizeof(node));
    head1=makeCopy(hhead1);
    node *head2 = (node *)malloc(sizeof(node));
    head2=makeCopy(hhead2);

    addZeros(head1,head2);

    int carry=0;
    char c1[2];
    int ans;

    while(head1!=NULL){
        ans=head1->data+head2->data+carry;
        if(ans>=10){
            carry=1;
            ans=ans-10;
        }else{
            carry=0;
        }
        append(&result,ans);

        head1=head1->next;
        head2=head2->next;
    }
    result=removeZeros(result);

    return result;
}


// Borrow from the next node
void borrow(node **head1){
    node *temp = (node *)malloc(sizeof(node));
    temp = *head1;
    if(temp->next->data-1<0){
        borrow(&temp->next);
    }
    temp->next->data=temp->next->data-1;
    temp->data=temp->data+10;
}


// Subtract the two numbers
node *subtract(node *hhead1, node *hhead2, node *result){
    result=NULL;
    node *head1 = (node *)malloc(sizeof(node));
    head1=makeCopy(hhead1);
    node *head2 = (node *)malloc(sizeof(node));
    head2=makeCopy(hhead2);

    addZeros(head1,head2);

    while (head1!=NULL){
        if(head1->data-head2->data<0){
            borrow(&head1);
        }
        append(&result,head1->data-head2->data);

        head1=head1->next;
        head2=head2->next;
    }
    result=removeZeros(result);
    return result;
}


// Make answer
node *makeAns(char str[], node **mAns){
    int len = strlen(str);
    int i=len-1;

    for(i;i>=0;i--){
        append(&(*mAns),str[i]-'0');
    }
    return *mAns;
}


//Add place value zeros for multiplication
node *addPlaceZeros(node *sAns, node *zeros){
    node *nn = (node *)malloc(sizeof(node));
    nn=NULL;
    node *tempn = (node *)malloc(sizeof(node));
    tempn=sAns;
    sAns=nn;
    while (zeros!=NULL){
        append(&nn,zeros->data);
        zeros=zeros->next;
    }

    node *zt1 = (node *)malloc(sizeof(node));
    zt1=nn; 
    while (zt1->next!=NULL){
        zt1=zt1->next;
    }
    
    zt1->next=tempn;
    return nn;
}


// Multiply the two numbers
node *multiply(node *head1, node *head2, node *result){
    addZeros(head1,head2);
    node *temp1 = (node *)malloc(sizeof(node));
    node *temp2 = (node *)malloc(sizeof(node));
    temp2=head2;

    int ans;
    char str[10000];
    node *mCarry = (node *)malloc(sizeof(node));
    mCarry=NULL;
    node *mAns = (node *)malloc(sizeof(node));
    mAns=NULL;
    node *sAns = (node *)malloc(sizeof(node));
    sAns=NULL;
    node *tempAns = (node *)malloc(sizeof(node));
    tempAns=NULL;
    node *zAns = (node *)malloc(sizeof(node));
    zAns=NULL;
    node *pAns = (node *)malloc(sizeof(node));
    pAns=NULL;
    node *nAns = (node *)malloc(sizeof(node));
    nAns=NULL;

    while (temp2!=NULL){
        temp1=head1;
        mCarry=NULL;
        mAns=NULL;  
        tempAns=NULL;  
        while (temp1!=NULL){
            ans=temp1->data*temp2->data;
            sprintf(str, "%d", ans);

            mAns = makeAns(str, &mAns);

            if(mCarry==NULL){
                append(&sAns,mAns->data);
                mCarry = mAns->next;
            }else{
                tempAns = add(mAns,mCarry,tempAns);
                append(&sAns,tempAns->data);
                mCarry=NULL;
                mCarry = tempAns->next;
            }

            temp1=temp1->next;
            mAns=NULL;
            tempAns=NULL;
        }

        if(zAns==NULL){
            append(&zAns,0);
        }else{
            sAns = addPlaceZeros(sAns,zAns);
            append(&zAns,0);
        }

        if(pAns==NULL){
            pAns=sAns;
        }else{
            nAns=add(pAns,sAns,nAns);
            pAns=nAns;
            nAns=NULL;
        }
        sAns=NULL;
        temp2=temp2->next;
    }
    removeAllZeros(pAns);
    
    return pAns;
}


//Reverse the node
node * reverse(node *head1){
    node *temp = (node *)malloc(sizeof(node));
    temp=head1;

    node *prev= NULL;
    node *curr= temp;
    node *next= NULL;

    while (curr != NULL) {
        next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }
    temp = prev;

    return temp;
}


// Make a Node
node *makeList(char str[]){
    int len = strlen(str);

    node *mn = (node *)malloc(sizeof(node));
    mn=NULL;

    for(int i=0;i<len;i++){
        append(&mn,str[i]-'0');
    }

    return mn;
}


// Compare the two numbers
int compare(node *head1, node *head2){
    
    node *rtemp = (node *)malloc(sizeof(node));

    rtemp=head1;
    node *rhead1 = (node *)malloc(sizeof(node));
    rhead1=NULL;
    while (rtemp!=NULL){
        append(&rhead1,rtemp->data);
        rtemp=rtemp->next;
    }
    
    rtemp=head2;
    node *rhead2 = (node *)malloc(sizeof(node));
    rhead2=NULL;
    while (rtemp!=NULL){
        append(&rhead2,rtemp->data);
        rtemp=rtemp->next;
    }

    addZeros(rhead1,rhead2);

    rhead1=reverse(rhead1);
    rhead2=reverse(rhead2);

    int flag = 0;
    //head1>head2 -> flag=1
    //head2>head1 -> flag=-1
    //head1=head2 -> flag=0

    while (rhead1!=NULL){
        if(rhead1->data>rhead2->data){
            flag=1;
            break;
        }else if (rhead2->data>rhead1->data){
            flag=-1;
            break;
        }
        rhead1=rhead1->next;
        rhead2=rhead2->next;
    }
    return flag;
}


// Raise the number to the power
node *raiseTo(node *hhead1, node *hhead2){
    node *head1 = (node *)malloc(sizeof(node));
    head1=makeCopy(hhead1);
    node *head2 = (node *)malloc(sizeof(node));
    head2=makeCopy(hhead2);

    node *c = (node *)malloc(sizeof(node));
    c=NULL;
    c=makeList("1");

    if(checkIfZero(hhead2)){
        return c;
    }

    node *o = (node *)malloc(sizeof(node));
    o=makeList("1");
    node *t = (node *)malloc(sizeof(node));
    t=NULL;

    node *tAns = (node *)malloc(sizeof(node));
    tAns=NULL;
    node *ans = (node *)malloc(sizeof(node));
    ans=head1;

    while (compare(head2,c)){
        c=add(c,o,t);
        ans=multiply(ans,head1,tAns);
    }

    return ans;
}


// Count Nodes
int countNodes(node *head){
    node *temp = (node *)malloc(sizeof(node));
    temp=head;
    int c=0;
    while (temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}


// Divide digit by digit
node *halfDivide(node *hhead1, node *hhead2, node **s){
    node *head1 = (node *)malloc(sizeof(node));
    head1=NULL;
    node *head2 = (node *)malloc(sizeof(node));
    head2=NULL;

    while (hhead1!=NULL){
        append(&head1,hhead1->data);
        hhead1=hhead1->next;
    }
    while (hhead2!=NULL){
        append(&head2,hhead2->data);
        hhead2=hhead2->next;
    }
    
    node *ans = (node *)malloc(sizeof(node));
    ans=NULL;
    ans=makeList("0");

    node *l = (node *)malloc(sizeof(node));
    l=NULL;
    l=makeList("1");

    node *a = (node *)malloc(sizeof(node));
    a=NULL;
    a=head1;

    node *b = (node *)malloc(sizeof(node));
    b=NULL;
    b=head2;

    node *c = (node *)malloc(sizeof(node));
    c=NULL;
    c=makeList("0");

    node *t = (node *)malloc(sizeof(node));
    t=NULL;

    *s=makeList("0");

    head1=reverse(head1);
    head2=reverse(head2);

    if(compare(head1,head2)==0 || compare(head1,head2)==1){
        while (compare(head1,c)==1){
            t=NULL;
            c=add(c,head2,t);
            t=NULL;
            ans=add(ans,l,t);
        }
    }

    if(compare(c,head1)==1){
        t=NULL;
        ans=subtract(ans,l,t);
        t=NULL;
        c=subtract(c,head2,t);
        t=NULL;
        c=subtract(head1,c,t);
    }else if (compare(c,head1)==0){
        t=NULL;
        c=subtract(head1,c,t);
    }else if (compare(head2,c)==1)
    {
        c=head1;
    }
    

    ans=removeZeros(ans);
    c=removeZeros(c);
    c=reverse(c);

    *s=c;

    return ans;
}


// Check if the number is zero
int checkIfZero(node *head){
    node *temp = (node *)malloc(sizeof(node));
    temp=head;
    while (temp!=NULL){
        if(temp->data!=0)
            return 0;
        temp=temp->next;
    }
    return 1;
}


node *reverseD(node **head1){
    node *temp = (node *)malloc(sizeof(node));
    temp=*head1;

    node *prev= NULL;
    node *curr= temp;
    node *next= NULL;

    while (curr != NULL) {
        next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }
    temp = prev;

    return temp;
}


// Check if the number is not zero
int checkIfNotZero(node *head){
    node *temp = (node *)malloc(sizeof(node));
    temp=head;
    while (temp!=NULL){
        if(temp->data!=0)
            return 1;
        temp=temp->next;
    }
    return 0;
}


// Divide the number
node *divide(node *hhead1, node *hhead2){
    node *head1 = (node *)malloc(sizeof(node));
    head1=makeCopy(hhead1);
    node *head2 = (node *)malloc(sizeof(node));
    head2=makeCopy(hhead2);

    head1=reverse(head1);
    head2=reverse(head2);

    node *h1 = (node *)malloc(sizeof(node));
    h1=makeCopy(head1);
    node *h2 = (node *)malloc(sizeof(node));
    h2=makeCopy(head2);

    node *number = (node *)malloc(sizeof(node));
    number=NULL;
    node *temp1 = (node *)malloc(sizeof(node));
    temp1=NULL;

    node *rem = (node *)malloc(sizeof(node));
    rem=head1;
    node *q = (node *)malloc(sizeof(node));
    q=head1;
    
    node *mq = (node *)malloc(sizeof(node));
    mq=NULL;

    node *temp = (node *)malloc(sizeof(node));
    temp=head1;

    while (temp!=NULL){
        append(&number,temp->data);
        temp=temp->next;

        rem=NULL;
        q=halfDivide(number,h2,&rem);
        number=rem;

        append(&mq,q->data);
    }
    
    mq=reverse(mq);
    mq=removeZeros(mq);
    return mq;
}


// Modulo the number
node *modulus(node *hhead1, node *hhead2){
    node *head1 = (node *)malloc(sizeof(node));
    head1=makeCopy(hhead1);
    node *head2 = (node *)malloc(sizeof(node));
    head2=makeCopy(hhead2);

    head1=reverse(head1);
    head2=reverse(head2);

    node *h1 = (node *)malloc(sizeof(node));
    h1=makeCopy(head1);
    node *h2 = (node *)malloc(sizeof(node));
    h2=makeCopy(head2);
    
    node *number = (node *)malloc(sizeof(node));
    number=NULL;
    node *temp1 = (node *)malloc(sizeof(node));
    temp1=NULL;

    node *rem = (node *)malloc(sizeof(node));
    rem=head1;
    node *q = (node *)malloc(sizeof(node));
    q=head1;
    
    node *mq = (node *)malloc(sizeof(node));
    mq=NULL;

    node *temp = (node *)malloc(sizeof(node));
    temp=head1;

    while (temp!=NULL){
        append(&number,temp->data);
        temp=temp->next;

        rem=NULL;
        q=halfDivide(number,h2,&rem);
        number=rem;

        append(&mq,q->data);
    }
    
    rem=reverse(rem);
    return rem;
}


// Make a copy of the number
node *makeCopy(node *head){
    node *temp = (node *)malloc(sizeof(node));
    temp=head;
    node *ret = (node *)malloc(sizeof(node));
    ret=NULL;
    while (temp!=NULL){
        append(&ret,temp->data);
        temp=temp->next;
    }
    return ret;
}


// Display the Answer (Used for testing only)
void displayAnswer(node *result){
    node *temp = (node *)malloc(sizeof(node));
    temp=result;

    node *prev= NULL;
    node *curr= temp;
    node *next= NULL;

    while (curr != NULL) {
        next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }
    temp = prev;

    while (temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    
}


// Display the Numbers (Used for testing only)
void printHeads(node *head1, node *head2){
    printf("\n");
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
}


// Seperator (Used for testing only)
void seperator(){
    printf("\n-----------------------------\n");
}


// Display the Whole Equation (Used for testing only)
void displayForTesting(node *head1, node *head2, node *result, char op){
    seperator();
    head1 = reverse(head1);
    display(head1);
    printf("%c",op);
    head2 = reverse(head2);
    display(head2);
    printf("=");
    display(result);
    printf("->");
    result = reverse(result);
    display(result);
    seperator();
}

void  performCalculations(char exp[]){

    int flag=0;
    char *str;

    // Create a new string to store the postfix equation
    char *ans = malloc (sizeof (char) * 10000);
    makePostfixEqation(exp,ans);  

    // Remove Extra Spaces
    str=removeBlanks(ans);

    // Make the Linked List
    LL *head = NULL;
    LL *n1,*n2,*n3;

    head = makeIt(str, head);

    node *result=(node *)malloc(sizeof(node));
    result=NULL;

    LL *traverse = (LL *)malloc(sizeof(LL));
    traverse = head; 

    // if(isInValidEquation(head)==1){
    //     // flag=1;
    //     printf("Invalid Equation! (Hint: Check the Operators!)\n");
    //     continue;
    // }

    //Solve the Euqation
    while(countLLNodes(head)!=1){
        if(traverse->n1!=NULL && traverse->next->n1!=NULL && traverse->next->next->op!=NULL){
            result=NULL;

            if(traverse->next->next->op->op=='/'){
                if(checkIfZero(traverse->next->n1)){
                    printf("Runtime error (func=(main), adr=9): Divide by zero\n");
                    flag=1;
                    break ; 
                }
            }

            result=solve(&traverse->n1, &traverse->next->n1, traverse->next->next->op);

            //Nodes which have been solved
            n1=traverse;
            n2=traverse->next;
            n3=traverse->next->next;

            //Insert the solution
            insertTheSolution(traverse, n3, result);

            //Remove the solved nodes
            removeLLNode(&head, n1);
            removeLLNode(&head, n2);
            removeLLNode(&head, n3);

            traverse=head;
        }else{
            // Get the next small equation
            traverse=traverse->next;
        }
    }

    // Display the result
    if(flag==1){
        flag=0;
    }else{
        node *mainOutput = (node *) malloc(sizeof(node));
        mainOutput = reverse(head->n1);
        mainOutput = removeInitialZeros(mainOutput);
        display(mainOutput);
        printf("\n");
        // free(mainOutput);
    }

    free(ans);
    free(result);
    free(traverse);
}