// Develop a C program to create a thread that calculates the average of numbers from 1 to 100?

#include <stdio.h>
#include <pthread.h>

void *avg(void *arg) {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("Average: %d\n", sum / 100);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, avg, NULL);
    pthread_join(thread, NULL);
    return 0;
}
