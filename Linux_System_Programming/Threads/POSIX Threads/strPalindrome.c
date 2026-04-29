// Write a C program to create a thread that checks if a given string is a palindrome using dynamic programming with mutex locks?

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *checkPalindrome(void *arg) {
    char *str = (char *)arg;
    int len = strlen(str);
    int i=0, j=len-1;
    pthread_mutex_lock(&mutex);
    while (i < j) {
        if (str[i] != str[j]) {
            printf("%s is not a palindrome\n", str);
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        i++;
        j--;
    }
    printf("%s is a palindrome\n", str);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    pthread_t thread;
    pthread_create(&thread, NULL, checkPalindrome, (void *)str);
    pthread_join(thread, NULL);
    return 0;
}
