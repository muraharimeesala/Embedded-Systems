//Develop a C program to move a file from one directory to another?
#include<stdio.h>
#include<stdlib.h>
int main(){
	char src[256],dest[256];
	printf("Enter a source path:");
	scanf("%s",src);
	printf("Enter Destination path:");
	scanf("%s",dest);
	if(rename(src,dest)==0){
		printf("'%s' is moved to '%s'destination path.\n",src,dest);
	}
	else{
		printf("rename failed.\n");
	}
}

