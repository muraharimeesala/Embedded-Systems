#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
int main(){
	char filename[256];
	struct stat sa;
	printf("Enter file name:");
	scanf("%s",filename);
	if(stat(filename,&sa)==-1){
		perror("stat");
		exit(1);
	}
	printf("Last Modified:%s",ctime(&sa.st_mtime));
}
