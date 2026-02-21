#include <stdio.h>
int calculateSum(int arr[], int num) {
    int sum = 0;
    for(int i = 0; i < num; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
int num,i;
    int numbers[100];
    printf("Enter no of elements:");
    scanf("%d",&num);
    for(i=0;i<num;i++){
    printf("Element-%d:",i);
    scanf("%d",&numbers[i]);
    }
    int total = calculateSum(numbers, num);
    printf("Sum of array elements: %d\n", total);
    return 0;
}
