#include <stdio.h>
#include <string.h>
void leftRotate(char str[], int k) {
    int n = strlen(str);
    char temp[100];
    strcpy(temp, str + k);
    strncat(temp, str, k);  //append to last 
    strcpy(str, temp);
}
int main() {
    char str[100];
    int k;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Enter value of k: ");
    scanf("%d", &k);
    leftRotate(str, k);
    printf("String after left rotation: %s\n", str);
    return 0;
}

