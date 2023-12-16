#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"func.h"





typedef struct node
{
    int data;
    struct node* next;
} node;

void append(node **head, int data);
void evaluate(char str[], node **head1, node **head2);
int isOperator(char c);
void addZeros(node *head1, node *head2);

node *add(node *head1, node *head2, node *result);

node *subtract(node *head1, node *head2,node *result);
void borrow(node **head1);

node *multiply(node *head1, node *head2, node *result);
node *makeAns(char str[], node **mAns);
node *makeMulAns(node **head, int data);
node *addPlaceZeros(node *sAns, node *zeros);

node *reverse(node *head1);
node *makeList(char str[]);
int compare(node *head1, node *head2);
node *raiseTo(node *head1, node *head2);

node *removeZeros(node *head);
node *removeAllZeros(node *head);

node *divide(node *head1, node *head2);
node *halfDivide(node *head1, node *head2, node **result);
int takeDivident(node *head, int c, int *r1);
int countNodes(node *head);
int convertToInt(node *head);
int checkIfZero(node *head);
void equateDigits(node **head1, node **head2);
int compareD(node *head1, node *head2);
node *reverseList(node **head);

node *modulus(node *head1, node *head2);

void printHeads(node *head1, node *head2);
void seperator();

void displayAnswer(node *result);
node *makeCopy(node *head);
void displayForTesting(node *head1, node *head2, node *result, char op);





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

void display(node *head){
    while (head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}

int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^'){
        return 1;
    }else{
        return 0;
    }
}

node *removeZeros(node *head){
    /*printf("\nHead:");
    display(head);
    seperator();*/

    node *rhead=(node *)malloc(sizeof(node));
    rhead=reverse(head);
    /*printf("\nReversed Head:");
    display(rhead);
    seperator();*/

    node *rtemp = (node *)malloc(sizeof(node));
    rtemp=rhead;
    if(rtemp->next!=NULL && rtemp->next->next!=NULL && rtemp->data==0 && rtemp->next->data==0){
        while (rtemp->next->next!=NULL && rtemp->next->next->data==0){
            rtemp=rtemp->next;
        }   
        rhead=rtemp->next;
    }


    /*printf("\nAns Head:");
    display(rhead);
    seperator();*/

    rhead=reverse(rhead);
    /*printf("\nReturn Ans Head:");
    display(rhead);
    seperator();*/  

    return rhead;
}

node *removeAllZeros(node *head){
    /*printf("\nHead:");
    display(head);
    seperator();*/

    node *rhead=(node *)malloc(sizeof(node));
    rhead=reverse(head);
    /*printf("\nReversed Head:");
    display(rhead);
    seperator();*/

    node *rtemp = (node *)malloc(sizeof(node));
    rtemp=rhead;
    if(rtemp->next!=NULL){
        while (rtemp->next!=NULL && rtemp->next->data==0)
        {
            rtemp=rtemp->next;
        }   
    }

    rhead=rtemp->next;

    /*printf("\nAns Head:");
    display(rhead);
    seperator();*/

    rhead=reverse(rhead);
    /*printf("\nReturn Ans Head:");
    display(rhead);
    seperator();*/

    return rhead;
}

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

node *add(node *hhead1, node *hhead2, node *result){
    result=NULL;
    node *head1 = (node *)malloc(sizeof(node));
    head1=makeCopy(hhead1);
    node *head2 = (node *)malloc(sizeof(node));
    head2=makeCopy(hhead2);

    addZeros(head1,head2);
    //printHeads(head1,head2);

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

void borrow(node **head1){
    node *temp = (node *)malloc(sizeof(node));
    temp = *head1;
    if(temp->next->data-1<0){
        borrow(&temp->next);
    }
    temp->next->data=temp->next->data-1;
    temp->data=temp->data+10;
}

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

node *makeAns(char str[], node **mAns){
    int len = strlen(str);
    int i=len-1;

    for(i;i>=0;i--){
        append(&(*mAns),str[i]-'0');
    }
    return *mAns;
}

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
    while (zt1->next!=NULL)
    {
        zt1=zt1->next;
        //printf("S");
    }
    
    zt1->next=tempn;
    return nn;
}

node *multiply(node *head1, node *head2, node *result){
    addZeros(head1,head2);
    node *temp1 = (node *)malloc(sizeof(node));
    node *temp2 = (node *)malloc(sizeof(node));
    temp2=head2;

    int ans;
    char str[100];
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
            //printf("%s\t",str);

            mAns = makeAns(str, &mAns);

            if(mCarry==NULL){
                //printf("\nAnswer:");
                //display(mAns);
                //printf("\nMultiplication Ans= %d",mAns->data);
                append(&sAns,mAns->data);
                mCarry = mAns->next;
            }else{
                tempAns = add(mAns,mCarry,tempAns);
                // printf("\nAnswer has Carry:");
                // display(tempAns);
                //printf("\nMultiplication Ans has Carry= %d",tempAns->data);
                append(&sAns,tempAns->data);
                mCarry=NULL;
                mCarry = tempAns->next;
            }

            //mCarry = mAns->next;
            // printf("\nCarry:");
            // display(mCarry);

            temp1=temp1->next;
            mAns=NULL;
            tempAns=NULL;
        }

        if(zAns==NULL){
            append(&zAns,0);
            // printf("Zeros: ");
            // display(zAns);
        }else{
            sAns = addPlaceZeros(sAns,zAns);
            // printf("Zeros: ");
            // display(zAns);
            append(&zAns,0);
        }

        if(pAns==NULL){
            pAns=sAns;
        }else{
            nAns=add(pAns,sAns,nAns);
            pAns=nAns;
            // printf("\nAdd Ans: ");
            // display(nAns);
            nAns=NULL;
        }
        
        sAns=NULL;
        temp2=temp2->next;
        // seperator();
    }
    // printf("My Main Multiplication Answer: ");
    removeAllZeros(pAns);
    // display(pAns);

    
    return pAns;
}

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

node *makeList(char str[]){
    int len = strlen(str);

    node *mn = (node *)malloc(sizeof(node));
    mn=NULL;

    for(int i=0;i<len;i++){
        append(&mn,str[i]-'0');
    }

    return mn;
}

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

    //printf("\nHead 1: Function Reversed: ");
    //display(rhead1);
    rhead1=reverse(rhead1);

    //printf("\nHead 2: Function Reversed: ");
    //display(rhead2);
    rhead2=reverse(rhead2);

    //printf("\nHead 1: Function Proper: ");
    //display(rhead1);

    //printf("\nHead 2: Function Proper: ");
    //display(rhead2);

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
    //printf("Flag=%d",flag);
    return flag;
}

node *raiseTo(node *hhead1, node *hhead2){
    node *head1 = (node *)malloc(sizeof(node));
    head1=makeCopy(hhead1);
    node *head2 = (node *)malloc(sizeof(node));
    head2=makeCopy(hhead2);

    node *c = (node *)malloc(sizeof(node));
    c=NULL;
    c=makeList("1");

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

int convertToInt(node *head){
    //Using atoi() function
    char str[100];
    int i=0;
    node *temp = (node *)malloc(sizeof(node));
    temp=head;
    while (temp!=NULL){
        str[i]=temp->data+'0';
        temp=temp->next;
        i++;
    }
    str[i]='\0';
    int num = atoi(str);
    return num;
}

node *halfDivide(node *hhead1, node *hhead2, node **s){
    node *head1 = (node *)malloc(sizeof(node));
    head1=NULL;
    node *head2 = (node *)malloc(sizeof(node));
    head2=NULL;

    //printHeads(hhead1,hhead2);

    while (hhead1!=NULL){
        append(&head1,hhead1->data);
        hhead1=hhead1->next;
    }
    while (hhead2!=NULL){
        append(&head2,hhead2->data);
        hhead2=hhead2->next;
    }
    
    //addZeros(head1,head2);

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

    //seperator();

    head1=reverse(head1);
    head2=reverse(head2);

    // printf("\nHead 1: Function Proper: ");
    // display(head1);
    // printf("\nHead 2: Function Proper: ");
    // display(head2);

    // seperator();

    if(compare(head1,head2)==0 || compare(head1,head2)==1){
        while (compare(head1,c)==1){
            t=NULL;
            c=add(c,head2,t);
            t=NULL;
            //printf("\nFunction Half Divide answer: ");
            //display(*c);
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

    //ans=reverse(ans);
    c=reverse(c);

    *s=c;
    // seperator();
    // printf("\nMain Function Half Divide answer: ");
    // display(ans);
    // printf("\nMain Function Half Divide c: ");
    // display(c);
    // seperator();
    return ans;
}

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

int takeDivident(node *head, int c, int *r1){
    node *nn = (node *)malloc(sizeof(node));
    nn=NULL;
    node *ntemp = (node *)malloc(sizeof(node));
    ntemp=head;

    int n=0;
    int cnodes= countNodes(head);
    while (ntemp!=NULL){
        if(n==cnodes-1){
            *r1=1;
            //printf("True");
        }
        if(n==c+1){
            //append(&nn,ntemp->data);
            return ntemp->data;
        }
        ntemp=ntemp->next;
        n++;
    }

    //return nn;    
}

int compareD(node *head1, node *head2){
    node *rhead1 = (node *)malloc(sizeof(node));
    rhead1=head1;
    node *rhead2 = (node *)malloc(sizeof(node));
    rhead2=head2;

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
    //printf("Flag=%d",flag);
    return flag;
}

/*void equateDigits(node **head1, node **head2){
    int c1=0;
    node *temp = (node*) malloc(sizeof(node));
    temp=*head1;
    while (temp!=NULL){
        c1++;
        temp=temp->next;
    }

    int c2=0;
    temp=*head2;
    while (temp!=NULL){
        c2++;
        temp=temp->next;
    }
    
    node *ztemp = (node*) malloc(sizeof(node));
    ztemp=NULL;

    for(int i=0;i<abs(c1-c2);i++){
        append(&ztemp,0);
    }
    if(c1>c2){
        ztemp->next=*head2;
        *head2=ztemp;
    }else{
        ztemp->next=*head1;
        *head1=ztemp;
    }

}*/

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

node *divide(node *hhead1, node *hhead2){
    node *head1 = (node *)malloc(sizeof(node));
    head1=makeCopy(hhead1);
    node *head2 = (node *)malloc(sizeof(node));
    head2=makeCopy(hhead2);

    head1=reverse(head1);
    // seperator();
    // display(head1);

    head2=reverse(head2);
    // seperator();
    // display(head2);
    
    node *h1 = (node *)malloc(sizeof(node));
    h1=makeCopy(head1);
    node *h2 = (node *)malloc(sizeof(node));
    h2=makeCopy(head2);

    // seperator();
    // display(h1);
    // seperator();
    // display(h2);

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
        // seperator();
        // printf("Temp: ");
        // temp1=number;
        // display(temp1);
        // printf("\t");
        // display(number);
        // printf("\n");

        rem=NULL;
        q=halfDivide(number,h2,&rem);
        number=rem;

        // printf("Remainder: ");
        // display(rem);
        // printf("\n");
        // printf("Quotient: ");
        // display(q);
        // seperator();

        append(&mq,q->data);
    }
    
    // printf("Final Quotient: ");
    // display(mq);
    // printf("\n");
    // printf("Final Remainder: ");
    // display(rem);
    mq=reverse(mq);
    return mq;
}

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
    
    // printf("Final Quotient: ");
    // display(mq);
    // printf("\n");
    // printf("Final Remainder: ");
    // display(rem);
    rem=reverse(rem);
    return rem;
}

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

void printHeads(node *head1, node *head2){
    printf("\n");
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
}

void seperator(){
    printf("\n-----------------------------\n");
}

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
