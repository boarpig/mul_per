#include<limits.h>
#include<stdint.h>
#include<stdio.h>

int count_steps(long n) {
    char str[20];
    int product = 1;
    int i = 0;
    int steps = 0;
    while(n > 9) {
        sprintf(str, "%ld", n);
        i = 0;
        product = 1;
        while(str[i] != 0) {
            product *= (str[i] - '0');
            i++;
        }
        n = product;
        steps++;
    }
    return steps;
}

int main(){
    int steps = 0;
    int max_steps = 0;
    long max_i = 0;
    long i = 38;
    printf("10 1\n25 2\n");
    while(steps < 11 && i < LONG_MAX) {
        i++;
        steps = count_steps(i);
        if (steps > max_steps) {
            max_steps = steps;
            max_i = i;
            printf("%ld %d\n", max_i, max_steps);
        }
    }
    return 0;
}
