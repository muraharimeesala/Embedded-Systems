// Implement a C program to create a thread that performs bubble sort on an array of integers?

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int n;
void *bubbleSort(void *arg) {
    int *arr = (int *)arg;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return NULL;
}
int main(){
    int n,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    pthread_t thread;
    pthread_create(&thread, NULL, bubbleSort,arr);
    pthread_join(thread, NULL);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
