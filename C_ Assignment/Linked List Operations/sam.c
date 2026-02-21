#include <stdio.h>

/* Function to check prime */
int isPrime(int num) {
    int i;
    if (num <= 1)
        return 0;

    for (i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

/* Subroutine to return nth prime number */
int nthPrime(int n) {
    int count = 0;
    int num = 1;

    while (count < n) {
        num++;
        if (isPrime(num)) {
            count++;
        }
    }
    return num;
}

/* Driver program */
int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("The %dth prime number is: %d\n", n, nthPrime(n));

    return 0;
}
