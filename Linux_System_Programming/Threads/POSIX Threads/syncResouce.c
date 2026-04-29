//Develop a C program to create a thread that reads input from the user and synchronizes access to shared resources? 

#include <stdio.h>
#include <pthread.h>

void *read_input(void *arg) {
    char input[100];
    printf("Enter some text: ");
    scanf("%s", input);
    printf("You entered: %s\n", input);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, read_input, NULL);
    pthread_join(thread, NULL);
    return 0;
}
