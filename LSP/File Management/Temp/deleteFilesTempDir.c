#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
int main(){
	DIR *dir;
	struct stat sa;
	char path[512];
	struct dirent *entry;
	dir=opendir("Temp");
	if(!dir){
		perror("opendir\n");
		exit(1);
	}
	while((entry=readdir(dir))!=NULL){
		if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0)       //Skip . and ..
		continue;
		snprintf(path,sizeof(path),"Temp/%s",entry->d_name);
		stat(path,&sa);
		//Delete all files not directories
		if(S_ISREG(sa.st_mode)){
			if(remove(path)==0){
				printf("Deleted :%s\n",path);
			}
			else{
				printf("Remove\n");
			}
		}
	}
	closedir(dir);
}
	
	
