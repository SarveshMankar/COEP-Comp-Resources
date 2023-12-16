#include<stdio.h>
#include<stdlib.h>

#define PI 22 / 7.0

float fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    return (float) n * fact(n - 1);
}

float toThePower(float n, int m) {
    float ans = 1;
    for (int i = 1; i < m; i++)
        ans *= n;
    return ans;
}

int main(int argc, char * argv[]) {

    int n = atoi(argv[1]);
    int c = 0;
    float x = 30 * (PI / 180.0);

    //Part-1
    float cosX = 1;

    for (int i = 2; i <= n; i = i + 2) {
        if (c % 2 == 0) {
            cosX -= toThePower(x, i) / fact(i);
        } else {
            cosX += toThePower(x, i) / fact(i);
        }
        c++;
    }
    printf("cosX = %f", cosX);


    //Part-2
    float sinX = x;
    c = 0;

    for (int i = 3; i <= n; i = i + 2) {
        sinX -= toThePower(x, i) / fact(i);
    }

    printf("\nsinX = %f", sinX);


    //Part-3
    float e_raised_to_x = 1 + x;
    c = 0;

    for (int i = 2; i <= n; i++) {
        e_raised_to_x += toThePower(x, i) / fact(i);
    }

    printf("\ne^x = %f", e_raised_to_x);
	
	return 0;
}