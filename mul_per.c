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
    steps = count_steps(29384739);
    printf("%d\n", steps);
    return 0;
}
