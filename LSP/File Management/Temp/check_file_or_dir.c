#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
int main(){
	char path[200];
	struct stat pathStat;
	printf("Enter a path:");
	scanf("%s",path);
	if(access(path,F_OK)!=0){
		printf("Path doesn't exit.\n");
		exit(1);
	}
	if(stat(path,&pathStat)==-1){
		printf("Stat failed.\n");
		exit(1);
	}
	if(S_ISREG(pathStat.st_mode)){
		printf("The given path is FILE.\n");
	}
	else if(S_ISDIR(pathStat.st_mode)){
		printf("The given path is DIR.\n");
	}
	else{
		printf("The given path is either regular file or directory.\n");
	}
}


