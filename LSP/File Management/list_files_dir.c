//Implement a C program to list all files in the current directory?

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>       // For directory functions
int main(){
	DIR *dir;
	struct dirent *entry;
	dir=opendir(".");
	if(dir<0){
		printf("Unable to open directory.\n");
		exit(1);
	}
	printf("Files in the current directory.\n");
	while((entry=readdir(dir))!=NULL){
			if(entry->d_name[0]!='.'){
			printf("%s\n",entry->d_name);
			}
	}
	closedir(dir);
}
