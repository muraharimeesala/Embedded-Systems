#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1024   // Max size of a line

int main() {
    FILE *fp;
    char line[LINE_SIZE];

    // Open the log file in read mode
    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("---- Errors and Warnings ----\n");

    // Read the file line by line
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Check if line contains "ERROR" or "WARNING"
        if (strstr(line, "ERROR") != NULL || strstr(line, "WARNING") != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}

