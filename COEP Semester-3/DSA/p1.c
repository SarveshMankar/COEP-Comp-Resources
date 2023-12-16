#include<stdio.h>
/*
* array size is too large, filled with spaces/zeros, length of array
*/
int main() {
    char subject[20] ="Data Structures";
    int i, len;
    for(i = 0; i < 20; i++)
        printf("%c\n",subject[i]);

    for(i = 0,len=0; subject[i]!='\0'; i++, len++);
    printf("%d\n",len);
    return 0;
}