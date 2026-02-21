#include <stdio.h>

void incrementByValue(int x) {
    x++;
}

void incrementByReference(int *x) {
    (*x)++;
}

int main() {
    int i,arr[] = {5,10,15,20,25};
    incrementByValue(arr[0]);
    printf("After value pass: %d\n", arr[0]);  // Still 5

    incrementByReference(&arr[0]);
    printf("After reference pass: %d\n", arr[0]);  // Now 6

    return 0;
}

