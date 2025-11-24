#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
	DIR *dir;
	struct stat sa;
	struct dirent *entry;
	dir=opendir(".");
	if(!dir){
		printf("Failed to open.\n");
		exit(1);
	}
	while((entry=readdir(dir))!=NULL){
		if(stat(entry->d_name,&sa)==0){
			if(S_ISREG(sa.st_mode)){
				printf("%s\n",entry->d_name);
			}
		}
	}
	closedir(dir);
}
