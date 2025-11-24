#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
int main(){
	char target[256],link[256];
	struct stat sa;
	printf("Enter target file:");
	scanf("%s",target);
	printf("Enter linking file:");
	scanf("%s",link);
	if(symlink(target,link)==-1){
		perror("error symlink\n");
		exit(1);
	}
	printf("Symbolic link created sucessfully.\n");
}
