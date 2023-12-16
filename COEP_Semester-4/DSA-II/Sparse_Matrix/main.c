#include<stdio.h>
#include<stdlib.h>
#include "sparse.h"

int main(){
    sparse *s1 = (sparse *) malloc(sizeof(sparse));
    init_Sparse(&s1, "data.txt");
    insert_Sparse(&s1, "data.txt");

    sparse *s2 = (sparse *) malloc(sizeof(sparse));
    init_Sparse(&s2, "data1.txt");
    insert_Sparse(&s2, "data1.txt");

    printf("\nAddition of two sparse matrices:\n");
    sparse *addition = (sparse *)malloc(sizeof(sparse));
    addition = add_Sparse(s1, s2);
    display_Sparse(addition);

    printf("\nSubtraction of two sparse matrices:\n");
    sparse *subtraction = (sparse *)malloc(sizeof(sparse));
    subtraction = sub_Sparse(s1, s2);
    display_Sparse(subtraction);

    sparse *s3 = (sparse *) malloc(sizeof(sparse));
    init_Sparse(&s3, "data2.txt");
    insert_Sparse(&s3, "data2.txt");
    printf("\nSymmetricity of sparse matrix: %d\n", ifSymmetric(s3));

    printf("\nTranspose of sparse matrix:\n");
    sparse *transpose = (sparse *)malloc(sizeof(sparse));
    transpose = transpose_Sparse(s3);
    display_Sparse(transpose);

    return 0;
}