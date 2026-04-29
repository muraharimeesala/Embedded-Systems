//Implement a C program to create a thread that generates random numbers and synchronizes access to a shared buffer?

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_function(void *arg) {
    int i;
    int *buffer = (int *)arg;
    for (i = 0; i < 10; i++) {
        buffer[i] = rand();
    }
    return NULL;
}

int main() {
    int buffer[10];
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, (void *)buffer);
    pthread_join(thread, NULL);
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
    return 0;
}

