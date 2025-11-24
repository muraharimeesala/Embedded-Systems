#include <stdio.h>
int main() {
    char str[200];
    int freq[256] = {0};
    int i, minFreq = 9999;
    char minChar;
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
        if (freq[i]!=0 && freq[i]<minFreq) {
            minFreq = freq[i];
            minChar = (char)i;
        }
    }
    if(minFreq!=9999){
    printf("The highest frequency character is '%c' with frequency %d.\n", minChar, minFreq);
    }
    else{
    printf("no character found in the string.\n");
    }
}

