// Implement a C program to create a thread that calculates the sum of Fibonacci numbers up to a given limit using dynamic programming with mutex locks?

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *calculate_fibonacci(void *arg) {
    int limit = *(int *)arg;
    int fib[limit + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= limit; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("Fibonacci numbers up to %d: ", limit);
    for (int i = 0; i <= limit; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
    return NULL;
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    pthread_t thread;
    pthread_create(&thread, NULL, calculate_fibonacci, &limit);
    pthread_join(thread, NULL);
    return 0;
}
