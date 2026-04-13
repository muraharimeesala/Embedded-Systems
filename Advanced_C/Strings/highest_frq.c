#include <stdio.h>
int main() {
    char str[200];
    int freq[256] = {0};
    int i, maxFreq = 0;
    char maxChar;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    for (i = 0; i < 256; i++) {
        if (freq[i]>maxFreq) {
            maxFreq = freq[i];
            maxChar = (char)i;
        }
    }
    printf("The highest frequency character is '%c' with frequency %d.\n", maxChar, maxFreq);
}

