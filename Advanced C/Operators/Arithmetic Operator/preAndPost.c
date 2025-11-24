#include <stdio.h>
int main() {
    int n;
    printf("Enter a num: ");
    scanf("%d", &n);
    printf("Original Value: %d\n", n);
    printf("Post Increment (n++): %d\n", n++);
    printf("Value After Post Increment: %d\n", n);
    printf("Pre Increment (++n): %d\n", ++n);
    printf("Post Decrement (n--): %d\n", n--);
    printf("Value After Post Decrement: %d\n", n);
    printf("Pre Decrement (--n): %d\n", --n);
    printf("Final Value: %d\n", n);
    return 0;
}

