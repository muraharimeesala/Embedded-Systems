//Write a C program to get the size of a file named "file.txt"?
 
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(){
	const char *filename="txt_file.txt";
	struct stat filestat;
	if(stat(filename,&filestat)<0){
		printf("Failed to getting file info.\n");
		exit(1);
	}
	printf("Size of '%s' file is:%lld bytes\n",filename,(long long)filestat.st_size);
}

