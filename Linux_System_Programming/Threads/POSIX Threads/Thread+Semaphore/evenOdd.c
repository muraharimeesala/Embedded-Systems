#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>

sem_t sem;

void *evenOdd(void *arg) {
    int num = *(int *)arg;
    sem_wait(&sem);
    if (num % 2 == 0) {
        printf("%d is even\n", num);
    } else {
        printf("%d is odd\n", num);
    }
    sem_post(&sem);
    return NULL;
}

int main() {
    sem_init(&sem, 0, 1);
    pthread_t threads[5];
    int nums[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, evenOdd, &nums[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&sem);
    return 0;
}

