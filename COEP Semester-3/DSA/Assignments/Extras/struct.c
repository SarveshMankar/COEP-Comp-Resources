#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int roll;
    float marks;
} student;

int main(){

    student s1;
    s1.roll = 1;
    s1.marks = 90.5;

    printf("Roll: %d", s1.roll);
    printf("\nMarks: %f", s1.marks);


    return 0;
}