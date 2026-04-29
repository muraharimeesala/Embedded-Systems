//Write a C program to recursively list all files and directories in a given directory? 

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char path[1024];

    if (getcwd(path, sizeof(path)) == NULL) {
        perror("getcwd");
        return 1;
    }

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        printf("%s/\n", entry->d_name);

        if (stat(path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            printf("%s/\n", entry->d_name);
        } else {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}
