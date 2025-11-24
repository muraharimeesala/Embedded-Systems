//write a program to count the frequency of each character in a string.
#include <stdio.h>
#include <string.h>
int main() {
    char str[200];
    int freq[256] = {0};
    int i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);             // Remove newline if present
    str[strcspn(str, "\n")] = '\0';
    // Count frequencies
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    printf("\nCharacter frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}

