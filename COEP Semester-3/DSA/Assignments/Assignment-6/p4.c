#include<stdio.h>
#include<stdlib.h>

typedef struct test {
    struct test ** a;
}
test;

int main() {
    test * m;
    int i;
    m = (test * ) malloc(sizeof(test));
    m -> a = (test ** ) malloc(sizeof(test * ) * 3);
    for (i = 0; i < 2; i++) {
        m -> a[i] = (test * ) malloc(sizeof(test));
    }
    m -> a[2] = (test * ) malloc(3 * sizeof(test));
    m = f( & (m -> a));
}

test * f(test ** * ppp) {
    test * p, ** pp;
    pp = * ppp;
    p = * pp;
    * pp = (test * ) malloc(2 * sizeof(test));
    return pp[1];
}