// Develop a C program to get the last modified timestamp of a file ?

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main()
{
    struct stat s;
    stat("test.txt", &s);
    printf("Last modified: %s", ctime(&s.st_mtime));    
    return 0;
}
