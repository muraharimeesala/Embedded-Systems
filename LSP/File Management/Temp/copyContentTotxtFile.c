#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
	char dir[256],file[256];
	char buff[1024];
	struct dirent *de;
	int out,in;
	size_t n;
	printf("Enter directory:");
	scanf("%s",dir);
	DIR *dr=opendir(dir);
	if(!dr){
		printf("Error opendir.\n");
		exit(1);

	}
	printf("Enter filename:");
	scanf("%s",file);
	out=open(file,O_RDONLY|O_WRONLY|O_TRUNC,0644);
	if(out<0){
		printf("Error file.\n");
		exit(1);
	}
	while((de=readdir(dr))!=NULL){
		if(!strstr(de->d_name,".txt"))
		continue;
	char path[512];
	snprintf(path,sizeof(path),"%s%s",dir,de->d_name);
	in=open(dir,O_RDONLY);
	if(in<0){
		printf("Error file.\n");
		continue;
	}
	while((n=read(in,buff,sizeof(buff)))>0){
		write(out,buff,n);
	}
	close(in);
	}
	closedir(dr);
	close(out);
	printf("All text files are copied successfully.\n");
}


