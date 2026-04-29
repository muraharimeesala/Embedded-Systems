#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t lock;   // global mutex
int shared = 0;
void* thread_func1(void* arg) {
    printf("Thread 1: Trying to lock...\n");
    pthread_mutex_lock(&lock);      // Acquire lock
    printf("Thread 1: Locked\n");
    shared += 10;
    printf("Thread 1: shared = %d\n", shared);
    sleep(5);   // Hold lock for demonstration
    printf("Thread 1: Unlocking...\n");
    pthread_mutex_unlock(&lock);    // Release lock
    return NULL;
}
void* thread_func2(void* arg) {
    sleep(5);   // Ensure thread 1 locks first
    printf("Thread 2: Trying TRYLOCK...\n");
    if (pthread_mutex_trylock(&lock) == 0) {
        printf("Thread 2: Trylock SUCCESS (unexpected)\n");
        shared += 20;
        printf("Thread 2: shared = %d\n", shared);
        pthread_mutex_unlock(&lock);
    } else {
        printf("Thread 2: Trylock FAILED (mutex is busy)\n");
        printf("Thread 2: Waiting using pthread_mutex_lock...\n");
        pthread_mutex_lock(&lock);   // Now wait for actual lock
        printf("Thread 2: Lock acquired\n");
        shared += 30;
        printf("Thread 2: shared = %d\n", shared);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
int main() {
    pthread_t t1, t2;
    // Initialize mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("pthread_mutex_init");
        exit(EXIT_FAILURE);
    }
    printf("Main: Creating threads...\n");
    pthread_create(&t1, NULL, thread_func1, NULL);
    pthread_create(&t2, NULL, thread_func2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Main: Final value of shared = %d\n", shared);
    // Destroy mutex
    pthread_mutex_destroy(&lock);
    return 0;
}

