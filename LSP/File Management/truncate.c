#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
	char file[256];
	long len;
	struct stat sa;
	printf("Enter file name:");
	scanf("%s",file);
	if(stat(file,&sa)==-1){
		perror("stat");
		exit(1);
	}
	long original_size=sa.st_size;
	printf("Original size of the file:%ld\n",original_size);
	printf("Enter length to truncate:");
	scanf("%ld",&len);
	if(truncate(file,len)==-1){
		perror("truncate\n");
		exit(1);
	}
	if(stat(file,&sa)==-1){
		perror("stat");
		exit(1);
	}
	long new_size=sa.st_size;
	printf("File '%s' is truncated to '%ld' bytes.\n",file,len);
	printf("New size of the file:%ld\n",new_size);
}
