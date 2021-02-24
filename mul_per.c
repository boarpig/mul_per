#include<stdio.h>
#include<stdint.h>

int count_steps(int n) {
    char str[20];
    int product = 1;
    int i = 0;
    int steps = 0;
    while(n > 9) {
        sprintf(str, "%d", n);
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
    long i = 0;
    int max_steps = 0;
    int max_i = 0;
    for(i = 11; i < 3000000000000000; i++) {
        if (i % 2 == 1) {
            steps = count_steps(i);
            if (steps > max_steps) {
                max_steps = steps;
                max_i = i;
                printf("New record: %d %d\n", max_i, max_steps);
            }
        }
    }
    printf("final record: %d %d\n", max_i, max_steps);
    return 0;
}
