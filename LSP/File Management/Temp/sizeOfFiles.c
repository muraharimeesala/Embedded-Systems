#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
long long totalSize=0;
void calcSize(const char *path){
	DIR *dir=opendir(path);
	if(!dir){
		perror("opendir");
		exit(1);
	}
	struct stat sa;
	struct dirent *de;
	char newpath[512];
	while((de=readdir(dir))!=NULL){
		if(strcmp(de->d_name,".")||strcmp(de->d_name,".."))
			continue;
		snprintf(newpath,sizeof(newpath),"%s%s",path,de->d_name);
		lstat(newpath,&sa);
		if(S_ISDIR(sa.st_mode)){
			calcSize(newpath);
		}
		else{
			totalSize+=sa.st_size;
		}
	}
	closedir(dir);
}
int main(){
	char dirname[256];
	printf("Enter directory name:");
	scanf("%s",dirname);
	calcSize(dirname);
	printf("Total size:%lld\n",totalSize);
}
