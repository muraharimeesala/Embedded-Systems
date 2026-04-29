// Implement a C program to create a thread that generates a random string?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define SIZE 10
void *genRandomString(void *arg) {
    char *str = (char *)arg;
    int SIZE = strlen(str);
    int i;
    for (i = 0; i < SIZE; i++) {
        str[i] = 'a' + rand() % 26;
    }
    return NULL;
}

int main() {
    char str[100]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    pthread_t thread;
    pthread_create(&thread, NULL, genRandomString, str);
    pthread_join(thread, NULL);
    printf("Generated random string: %s\n", str);
    return 0;
}
