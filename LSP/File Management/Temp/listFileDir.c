#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
int main(){
	DIR *dir;
	struct dirent *entry;
	struct stat sa;
	char files[100][256];
	char dires[100][256];
	int filecount=0,dircount=0;
	dir=opendir(".");
	if(!dir){
		printf("opendir\n");
		exit(1);
	}
	printf("List files and directories:\n");
	while((entry=readdir(dir))!=NULL){
		if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0)
				continue;
		if(stat(entry->d_name,&sa)!=0){
			printf("stat failed.\n");
 			continue;
		}
		if(S_ISREG(sa.st_mode)){
			strcpy(files[filecount++],entry->d_name);
		}
		else if(S_ISDIR(sa.st_mode)){
  			strcpy(dires[dircount++],entry->d_name);
	        }
		else{
			printf("OTHERS:%s\n",entry->d_name);
		}
	}
	closedir(dir);
	int i;
	printf("\n==================== DIRECTORIES ====================\n");
        printf("%-30s | %-15s\n", "Directory Name", "Size (Bytes)");
        printf("------------------------------------------------------\n");
	for(i=0;i<dircount;i++){
		if(stat(dires[i],&sa)==0)
		printf("%-30s | %-15ld bytes\n",dires[i],sa.st_size);
	}
	printf("\n==================== FILES ====================\n");
        printf("%-30s | %-15s\n", "File Name", "Size (Bytes)");
        printf("------------------------------------------------------\n");
	for(i=0;i<filecount;i++){
		if(stat(files[i],&sa)==0)
		printf("%-30s | %-15ld bytes\n",files[i],sa.st_size);
	}

}



				
