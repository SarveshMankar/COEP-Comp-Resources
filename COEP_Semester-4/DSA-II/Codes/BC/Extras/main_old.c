#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include"func.c"

void main(){
    node *head1 = (node*)malloc(sizeof(node));
    head1=NULL;

    node *head2 = (node*)malloc(sizeof(node));
    head2=NULL;

    node *result = (node*) malloc(sizeof(node));
    result = NULL; 

    node *temp = (node*) malloc(sizeof(node));
    temp = NULL;
    
    seperator();
    printf("\nAddition: ");

    char str11[]="517872+10";
    evaluate(str11,&head1,&head2);
    result = add(head1,head2,temp);
    displayForTesting(head1,head2,result,'+');

    char str12[]="10+9995444";
    evaluate(str12,&head1,&head2);
    result = add(head1,head2,temp);
    displayForTesting(head1,head2,result,'+');

    char str13[] ="0012+0000000000000000000000036";
    evaluate(str13,&head1,&head2);
    result=add(head1,head2,result);
    displayForTesting(head1,head2,result,'+');

    seperator();
    printf("\nSubtraction: ");

    char str21[]="45801-2";
    evaluate(str21,&head1,&head2);
    result = subtract(head1,head2,temp);
    displayForTesting(head1,head2,result,'-');

    char str22[]="045801-14523";
    evaluate(str22,&head1,&head2);
    result = subtract(head1,head2,temp);
    displayForTesting(head1,head2,result,'-');

    char str23[]="10000-1";
    evaluate(str23,&head1,&head2);
    result = subtract(head1,head2,temp);
    displayForTesting(head1,head2,result,'-');

    char str24[]="1100-1100";
    evaluate(str24,&head1,&head2);
    result = subtract(head1,head2,temp);
    displayForTesting(head1,head2,result,'-');

    seperator();
    printf("\nMultiplication: ");

    char str31[] = "54*67";
    evaluate(str31,&head1,&head2);
    result = multiply(head1,head2,temp);
    displayForTesting(head1,head2,result,'*');

    char str32[] = "6793*8542";
    evaluate(str32,&head1,&head2);
    result = multiply(head1,head2,temp);
    displayForTesting(head1,head2,result,'*');

    char str33[] = "123*11";
    evaluate(str33,&head1,&head2);
    result = multiply(head1,head2,temp);
    displayForTesting(head1,head2,result,'*');

    char str34[] = "16871414614687414418451341654168*148618978465413987";
    evaluate(str34,&head1,&head2);
    result = multiply(head1,head2,temp);
    displayForTesting(head1,head2,result,'*');
    //2507412405301299662484441042584002885069504047816

    seperator();
    printf("\nPower Of: ");

    char str41[] = "10^10";
    evaluate(str41,&head1,&head2);
    result=raiseTo(head1,head2);
    displayForTesting(head1,head2,result,'^');

    char str42[] = "27^45";
    evaluate(str42,&head1,&head2);
    result=raiseTo(head1,head2);
    displayForTesting(head1,head2,result,'^');
    //25785133671514281396116148947909178321838248752307264505595053707

    seperator();
    printf("\nDivision: ");

    char str51[] = "4876/13";
    evaluate(str51,&head1,&head2);
    result=divide(head1,head2);
    displayForTesting(head1,head2,result,'/');

    char str52[] = "1687894165489456541/645465476"; //2615003014
    evaluate(str52,&head1,&head2);
    result=divide(head1,head2);
    displayForTesting(head1,head2,result,'/');

    char str53[] = "100/10";
    evaluate(str53,&head1,&head2);
    result=divide(head1,head2);
    displayForTesting(head1,head2,result,'/');

    seperator();
    printf("\nModulus: ");
    char str61[] = "4876%13";
    evaluate(str61,&head1,&head2);
    result=modulus(head1,head2);
    displayForTesting(head1,head2,result,'%');

    char str62[] = "1687894165489456541%645465476";
    evaluate(str62,&head1,&head2);
    result=modulus(head1,head2);
    displayForTesting(head1,head2,result,'%');

    char str63[] = "100%10";
    evaluate(str63,&head1,&head2);
    result=modulus(head1,head2);
    displayForTesting(head1,head2,result,'%');

}

