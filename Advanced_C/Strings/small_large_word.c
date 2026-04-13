#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char str[200];
    char word[50], smallest[50], largest[50];
    int i = 0, j = 0, len;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    str[strcspn(str, "\n")] = '\0';
    len = strlen(str);
    int firstWord = 1;
    while (i <= len) {
        if (isalpha(str[i])) {
            word[j++] = str[i];
        } else {
            if (j != 0) {
                word[j] = '\0';
                if (firstWord) {
                    strcpy(smallest, word);
                    strcpy(largest, word);
                    firstWord = 0;
                } else {
                    if (strlen(word) < strlen(smallest))
                        strcpy(smallest, word);
                    if (strlen(word) > strlen(largest))
                        strcpy(largest, word);
                }
                j = 0; // reset word
            }
        }
        i++;
    }

    printf("Smallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);

    return 0;
}

