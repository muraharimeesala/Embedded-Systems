#include <stdio.h>
void factorial(int *n, long long *result) {
    *result = 1;
    for (int i = 1; i <= *n; i++) {
        *result *= i;
    }
}

int main() {
    int num;
    long long fact;
    printf("Enter a number: ");
    scanf("%d", &num);
    factorial(&num, &fact);
    printf("Factorial of %d is: %lld\n", num, fact);
    return 0;
}

