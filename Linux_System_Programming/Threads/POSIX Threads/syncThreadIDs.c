//Develop a C program to create two threads that print their thread IDs and synchronize their output?

#include <pthread.h>
#include <stdio.h>

void *print_thread_id(void *arg) {
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu\n", thread_id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, print_thread_id, NULL);
    pthread_create(&thread2, NULL, print_thread_id, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
