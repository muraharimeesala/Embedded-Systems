// Implement a C program to create a thread that performs selection sort on an array of integers? 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *selectionSort(void *arg) {
    int *arr = (int *)arg;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    return NULL;
}

int main() {
    int arr[] = {5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    pthread_t thread;
    pthread_create(&thread, NULL, selectionSort, (void *)arr);
    pthread_join(thread, NULL);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
