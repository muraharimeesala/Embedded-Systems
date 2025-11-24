#include <stdio.h>
int main() {
    int n, result;
    printf("Enter n: ");
    scanf("%d", &n);
    result = n;
    while (n > 1) {
        --n;            // pre-decrement
        result -= n;
    }
    printf("Result = %d\n", result);
    return 0;
}

