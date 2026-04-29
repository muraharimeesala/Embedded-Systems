#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    char source[100], destination[100];
    printf("Enter the source file name: ");
    scanf("%s", source);
    printf("Enter the destination directory name: ");
    scanf("%s", destination);
    if (rename(source, destination) == 0)
    {
        printf("File moved successfully\n");
    }
    else
    {
        printf("File move failed\n");
    }
    return 0;
}
