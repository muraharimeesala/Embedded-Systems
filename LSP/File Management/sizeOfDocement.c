#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

long getDirSize(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char fullpath[1024];
    long total = 0;

    dir = opendir(path);
    if (!dir) return 0;

    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        stat(fullpath, &st);

        if (S_ISDIR(st.st_mode)) {
            total += getDirSize(fullpath); // recurse
        } else {
            total += st.st_size; // add file size
        }
    }

    closedir(dir);
    return total;
}

int main() {
	char dirname[512];
	printf("Enter Dirname:");
	scanf("%s",dirname);
    long size = getDirSize(dirname);
    printf("Total size of '%s': %ld bytes\n", dirname,size);
    return 0;
}

