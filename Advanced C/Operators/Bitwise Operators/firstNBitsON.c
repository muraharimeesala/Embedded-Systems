#include <stdio.h>
void printBinary(int x) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}
int main() {
    int x, n;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("\nOriginal number:\n");
    printBinary(x);
    int mask = (1 << n) - 1;
    printf("Mask (%d bits):\n", n);
    printBinary(mask);
    x = x|mask;
    printf("\nAfter TOGGLELING first %d bits:\n", n);
    printBinary(x);
    return 0;
}

