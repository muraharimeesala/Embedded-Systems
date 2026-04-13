#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char str[200];
    char word[50];
    int i = 0, j = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Words in the string:\n");
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            word[j++] = str[i];
        } else {
            if (j > 0) {  // end of a word
                word[j] = '\0';
                printf("%s\n", word);
                j = 0;
            }
        }
        i++;
    }
    // Print the last word if exists
    if (j > 0) {
        word[j] = '\0';
        printf("%s\n", word);
    }

    return 0;
}

