#include <stdio.h>

int main() {
  int n, i, e = 0, o = 0;
  printf("Enter Size : ");
  scanf("%d", &n);
  arr[n], even[n], odd[n];
  printf("Enter %d Elements:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      even[e++] = arr[i];
    } else {
      odd[o++] = arr[i];
    }
  }
  for (i = 0; i < e; i++) {
    printf("Even Elements: %d\n", arr[e]);
  }
  for (i = 0; i < o; i++) {
    printf("Odd Elements: %d\n", arr[o]);
  }
}
