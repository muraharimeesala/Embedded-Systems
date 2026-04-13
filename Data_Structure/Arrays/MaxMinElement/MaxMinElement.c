#include <stdio.h>

int main() {
  int n, i, min, max;
  int arr[100];
  printf("Enter Array Size: ");
  scanf("%d", &n);
  printf("Enter %d Elements: \n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  max = min = arr[0];
  for (i = 0; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    } else if (arr[i] > max) {
      max = arr[i];
    } else {
      printf("Invalid Input\n");
    }
  }
  printf("Maximum Number: %d\n", max);
  printf("Minimum Number: %d\n", min);
}
