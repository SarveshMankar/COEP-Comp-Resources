#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char c;
    struct node * next;
}
node;

typedef node * list;

void append(list * l, int i) {
    list t;
    t = (node * ) malloc(sizeof(node));
    t -> c = i + 'a' + 2;
    t -> next = NULL;
    if ( * l == NULL) {
        * l = t;
        return;
    }
    ( * l) -> next = t;
    return;
}

int main() {
    int i;
    list p;
    p = NULL;
    for (i = 0; i < 3; i++) {
        append( & p, i);
    }
}