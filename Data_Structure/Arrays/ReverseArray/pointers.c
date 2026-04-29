#include <stdio.h>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr;
  ptr = arr + 5 - 1;
  printf("Array Elements: ");
  while (ptr >= arr) {
    printf("%d ", *ptr);
    ptr--;
  }
  return 0;
}
