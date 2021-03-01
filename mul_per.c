#include<limits.h>
#include<stdint.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/sysinfo.h>
#include<threads.h>

int count_steps(long n);
int test_loop(void *arguments);

struct arg_struct {
    int skip;
    int offset;
    long max_i[11];
};

int num_threads;
mtx_t thread_num_mutex;

int main(){
    int procs = get_nprocs();
    thrd_t threads[procs];
    num_threads = procs;
    mtx_init(&thread_num_mutex, mtx_plain);
    struct arg_struct args[procs];
    struct arg_struct *args_p = args;
    printf("Starting %d threads.\n", procs);
    for(int t = 0; t < procs; t++) {
        args[t].skip = procs;
        args[t].offset = t;
        thrd_create(&threads[t], test_loop, (void *)&args_p[t]);
    }
    while(num_threads > 0){
        sleep(1);
    };
    long smallest_i = 0;
    for (int i = 1; i < 11; i++) {
        smallest_i = args[0].max_i[i];
        for (int thread = 0; thread < procs; thread++) {
            if (args[thread].max_i[i] < smallest_i && args[thread].max_i[i] != 0) {
                smallest_i = args[thread].max_i[i];
            }
        }
        printf("%02d %ld\n", i, smallest_i);
    }
    return 0;
}

int test_loop(void *arguments) {
    struct arg_struct *args = (struct arg_struct *)arguments;
    long i = 9 + args->offset - args->skip;
    int max_steps = 0;
    int steps = 0;
    for (int k = 0; k < 11; k++) {
        args->max_i[k] = 0;
    }
    while(steps < 10 && i < LONG_MAX) {
        i += args->skip;
        steps = count_steps(i);
        if (steps > max_steps) {
            max_steps = steps;
            args->max_i[steps] = i;
        }
    }
    mtx_lock(&thread_num_mutex);
    num_threads -= 1;
    mtx_unlock(&thread_num_mutex);
    return 0;
}

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
