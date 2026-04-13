// Implement a C program to create a thread that prints prime numbers up to a given limit with mutex locks?

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printPrimes(void *arg) {
    int limit = *(int *)arg;
    int i, j;
    for (i = 2; i <= limit; i++) {
        int isPrime = 1;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return NULL;
}
int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    pthread_t thread;
    pthread_create(&thread, NULL, printPrimes, &limit);
    pthread_join(thread, NULL);
    return 0;
}
