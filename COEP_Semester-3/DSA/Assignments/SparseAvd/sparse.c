#include <stdlib.h>
#include <stdio.h>
#include "sparse.h"


void createNode(Sparse *S, int i, int j, int data){
  Node *temp, *sdtemp, *prev;
  temp = (Node *)malloc(sizeof(Node));
  temp->i = i;
  temp->j = j;
  temp->data = data;


  if (S->rows[i] == NULL){
    S->rows[i] = temp;
  }

  else{
  sdtemp = S->rows[i];
  prev = S->rows[i];
    while(sdtemp != NULL){
      prev = sdtemp;
      sdtemp = sdtemp->next;
    }
    prev->next = temp;
  }

  if (S->columns[j] == NULL){

    S->columns[j] = temp;
  }
  else{
    sdtemp = S->columns[j];
    prev = S->columns[j];
    while(sdtemp!= NULL){
      prev = sdtemp;
      sdtemp = sdtemp->down;
    }
    prev->down = temp;
  }
}

Sparse *createSparse(Sparse *sum, int rows, int columns){
  sum = (Sparse *) malloc(sizeof(Sparse));
  sum->noOfRows = rows;
  sum->noOfColumns = columns;
  
  sum->rows = (Node **)malloc(sizeof(Node *) * rows);
  sum->columns = (Node **)malloc(sizeof(Node *) * columns);
  
  for (int i = 0; i < sum->noOfRows; i++) {
    sum->rows[i] = NULL;
  }
  for (int i = 0; i < sum->noOfColumns; i++) {
    sum->columns[i] = NULL;
  }
  return sum;
}

Sparse *sub_sparse(Sparse *S1, Sparse *S2){

  if (S1->noOfRows != S2->noOfRows || S1->noOfColumns != S2->noOfColumns){
    return ;
  }
  Sparse *sum;
  sum = createSparse(sum, S1->noOfRows, S1->noOfColumns);
  int rowi = 0, columni = 0, data ;

  Node *s1n, *s2n;

  for (int i = 0; i< S1->noOfRows; i++){
    s1n = S1->rows[i];
    s2n = S2->rows[i];

    for (int j = 0; j< S1->noOfColumns; j++){
      data = 0;
      if (s1n->j == j){
        data += s1n->data;
        s1n = s1n->next;
      }
      if (s2n->j == j){
        data -= s2n->data;
        s2n = s2n->next;
      }

      createNode(sum, i, j, data);
    }
  }

  return sum;

}

Sparse *add_sparse(Sparse *S1, Sparse *S2){

  if (S1->noOfRows != S2->noOfRows || S1->noOfColumns != S2->noOfColumns){
    return ;
  }
  Sparse *sum;
  sum = createSparse(sum, S1->noOfRows, S1->noOfColumns);
  int rowi = 0, columni = 0, data ;

  Node *s1n, *s2n;

  for (int i = 0; i< S1->noOfRows; i++){
    s1n = S1->rows[i];
    s2n = S2->rows[i];

    for (int j = 0; j< S1->noOfColumns; j++){
      data = 0;
      if (s1n->j == j){
        data += s1n->data;
        s1n = s1n->next;
      }
      if (s2n->j == j){
        data += s2n->data;
        s2n = s2n->next;
      }

      createNode(sum, i, j, data);

    }


  }

  return sum;

}




void display(Sparse *S){

  for (int i = 0; i < S->noOfRows; i++){
    Node *sdtemp = S->rows[i];
    while(sdtemp != NULL){
      printf("%d\t", sdtemp->data);
      sdtemp = sdtemp->next;
    }
    printf("\n");
  }
}



void initSparse(Sparse *S, char *file_name){

  FILE* ptr;
  int data;
  ptr = fopen(file_name, "r");
  fscanf(ptr,"%d %d", &S->noOfRows , &S->noOfColumns);

  S->rows = (Node **)malloc(sizeof(Node* )*S->noOfRows);
  S->columns = (Node **)malloc(sizeof(Node* )*S->noOfColumns);

  for(int i = 0 ; i<S->noOfRows ; i++){
    S->rows[i] = NULL;
  }
  for(int i = 0 ; i<S->noOfColumns; i++){
    S->columns[i] = NULL;
  }

  for(int i = 0; i < S->noOfRows; i++){
    for(int j = 0; j < S->noOfColumns; j++){
      fscanf(ptr, " %d ", &data);
      if (data != 0){
        createNode(S, i, j, data);
      }
    }
  }

  fclose(ptr);
}



Sparse *transpose(Sparse *S){
  Sparse *tS;

  tS = createSparse(tS, S->noOfColumns, S->noOfRows);

  for (int i = 0; i < S->noOfRows; i++){

    Node *sdtemp = S->rows[i];
    while(sdtemp != NULL){
      createNode(tS, sdtemp->j, sdtemp->i, sdtemp->data);
      sdtemp = sdtemp->next;
    }
  }

  return tS;

}


Sparse *transposewon(Sparse *S){
    int temp = S->noOfRows;
    S->noOfRows = (int)S->noOfColumns;
    S->noOfColumns = (int) temp;

//   Node **tempr = S->rows;
//   S->rows = S->columns;
//   S->columns = tempr;

    return S;
}
