//Implement a C program to delete a file named "delete_me.txt"? 
#include<stdio.h>
#include<stdlib.h>       //For exit
#include<unistd.h>      //For unlink
#include<sys/stat.h>    // For stat
int main(){
	struct stat sa;
	char path[256];
	printf("Enter a path:");a
	scanf("%s",path);
	if(stat(path,&sa)!=0){
		printf("Stat Failed.\n");
		return 1;
	}
	if(S_ISREG(sa.st_mode)){
		printf("'%s' is a Regular file.\n",path);
		if(unlink(path)==0){
		printf("%s Regular file deleted successfully.\n",path);
		}
		else{
			printf("Error in unlink.\n");
		}
	}
	else if(S_ISDIR(sa.st_mode)){
		printf("'%s' is a Directory.\n",path);
		if(rmdir(path)==0){
			printf("'%s' Directory is deleted seccessfully.\n",path);
		}
		else{
			printf("Error in rmdir.\n");
		}
	}
	else{
		printf("Unsupported file can't delete.\n");
	}
}
