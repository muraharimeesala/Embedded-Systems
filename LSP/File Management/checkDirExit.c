//Develop a C program to check if a directory named "Test" exists in the current directory? 

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat sb;
    if (stat("Test", &sb) == 0) {
        printf("Directory exists\n");
    } else {
        printf("Directory does not exist\n");
    }
    return 0;
}
