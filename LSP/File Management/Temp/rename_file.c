//Develop a C program to rename a file from "oldname.txt" to "newname.txt"?

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(){
	char oldpath[256],newpath[256];
	struct stat sa;
	printf("Enter old path:");
	scanf("%s",oldpath);
	printf("Enter new path:");
	scanf("%s",newpath);
	if(stat(oldpath,&sa)!=0){
		printf("'%s' is not exists.\n",oldpath);
	}
	if(rename(oldpath,newpath)==0){
		printf("File renamed successfully.\n");
	}	
	else{
		printf("rename failed.\n");
	
	}
}
