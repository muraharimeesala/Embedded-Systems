//Write a C program to check if a file named "path" exists in the current directory?

#include<stdio.h>
#include<stdlib.h>        //For access
#include<unistd.h>       //For exit
#include<sys/stat.h>
int main(){
	char path[256];
	struct stat sa;
	printf("Enter a path:");
	scanf("%s",path);
	if(stat(path,&sa)==0){
		printf("'%s' is exists.\n",path);
		if(S_ISREG(sa.st_mode)){
			printf("'%s' is Regular File.\n",path);
		}
		else if(S_ISDIR(sa.st_mode)){
			printf("'%s' is Directory.\n",path);
		}
		else{
			printf("'%s' is another type of file.\n",path);
		}
	}
	else{
		printf("Stat Failed.\n");
	}
}
