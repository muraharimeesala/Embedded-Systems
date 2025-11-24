#include <stdio.h>
#include <ctype.h>
int main() {
    char str[100];
    int i = 0, pos;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter choice (1 = lowercase→UPPERCASE, 2 = UPPERCASE→lowercase): ");
    scanf("%d", &pos);
    for (i = 0; str[i] != '\0'; i++) {
        if (pos == 1 && islower(str[i])) {
            str[i] = toupper(str[i]);
        }
        else if (pos == 2 && isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    printf("After converting the string: %s\n", str);
    return 0;
}

