#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
	char direct[256],largeFile[256]="";
	struct dirent *de;
	struct stat sa;
	char path[512];
	printf("Enter directory:");
	scanf("%s",direct);
	DIR *dr;
	dr=opendir(direct);
	if(!dr){
		perror("opendir");
		exit(1);
	}
	long largest_size=-1;
	while((de=readdir(dr))!=NULL){
		snprintf(path,sizeof(path),"%s/%s",direct,de->d_name);
		if(stat(path,&sa)==0 && S_ISREG(sa.st_mode)){
			if(sa.st_size>largest_size){
				largest_size=sa.st_size;
				strcpy(largeFile,de->d_name);
			}
		}
	}
	closedir(dr);
	if(largest_size==-1){
		printf("Largest file not found.\n");
	}
	else{
		printf("Largest file:%s(%ld bytes).\n",largeFile,largest_size);
	}
}


