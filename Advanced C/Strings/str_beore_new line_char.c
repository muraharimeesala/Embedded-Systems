#include <stdio.h>
int main() {
    char str[200];
    int i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("String before newline: ");
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            break;
        }
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}

