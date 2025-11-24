#include <stdio.h>
#include <sys/stat.h>
int main() {
    struct stat s;
    char path[256];
    printf("Enter file or directory path: ");
    scanf("%255s", path);   // safe input
    if (stat(path, &s) == 0) {
        // Check file type
        if (S_ISREG(s.st_mode)){
            printf("It is a REGULAR FILE\n");
	}
        else if (S_ISDIR(s.st_mode)){
            printf("It is a DIRECTORY\n");
	}
        else if (S_ISLNK(s.st_mode)){
            printf("It is a SYMBOLIC LINK\n");
	}
        else{
            printf("It is some OTHER file type\n");
	}
        // Check owner permissions
        if (s.st_mode & S_IRUSR){ 
		printf("Owner: Read permission\n");
	}
        if (s.st_mode & S_IWUSR){ 
		printf("Owner: Write permission\n");
	}
        if (s.st_mode & S_IXUSR){
		printf("Owner: Execute permission\n");
	}
    }
    else {
        perror("stat failed");
    }
    return 0;
}

