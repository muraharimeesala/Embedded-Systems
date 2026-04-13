// Write a program in C to merge two arrays of the same size sorted in
// descending order.

#include <stdio.h>

int main() {
  int arr1[10], arr2[10];
  int n, i, j, k;

  printf("Enter the size of the arrays: ");
  scanf("%d", &n);

  printf("Enter the elements of the first array: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr1[i]);
  }

  printf("Enter the elements of the second array: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr2[i]);
  }

  i = 0;
  j = 0;
  k = 0;

  while (i < n && j < n) {
    if (arr1[i] > arr2[j]) {
      arr2[k] = arr1[i];
      i++;
    } else {
      arr2[k] = arr2[j];
      j++;
    }
    k++;
  }

  while (i < n) {
    arr2[k] = arr1[i];
    i++;
    k++;
  }

  while (j < n) {
    arr2[k] = arr2[j];
    j++;
    k++;
  }

  printf("The sorted array is: ");
  for (i = 0; i < 2 * n; i++) {
    printf("%d ", arr2[i]);
  }

  return 0;
}
