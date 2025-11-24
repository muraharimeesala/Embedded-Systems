#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
int main(){
	char file[256];
	struct stat sa;
	printf("Enter file name:");
	scanf("%s",file);
	if(stat(file,&sa)==-1){
		perror("stat error.\n");
		exit(1);
	}
	printf("No of hardlinks:%ld\n",sa.st_nlink);
}
