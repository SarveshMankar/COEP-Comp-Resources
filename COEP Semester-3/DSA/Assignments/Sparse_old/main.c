#include <stdio.h>
#include <stdlib.h>
#include "sparse.h"


int main(){
  Sparse *S1, *S2;

  S1 = (Sparse *) malloc(sizeof(Sparse));
  S2 = (Sparse *) malloc(sizeof(Sparse));

  initSparse(S1, "./input");
  display(S1);

  initSparse(S2, "./input1");

  Sparse *sum12 = sub_sparse(S1, S2);

  Sparse *transposes = transpose(S1);
  display(transposes);

  Sparse *sd = transposewon(S1);
  display(sd);

}
