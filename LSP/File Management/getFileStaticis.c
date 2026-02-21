#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>
int main(){
	struct stat s;
	if(stat("getFileStaticis.txt",&s)==-1){
		perror("stat");
		exit(1);
	}
	printf("File: getFileStaticis\n");
	printf("Inode:%ld\n",s.st_ino);
	printf("Bytes:%ld\n",s.st_size);
	printf("File Type:%o\n",s.st_mode && 0777);
	printf("Owner User ID:%d\n",s.st_uid);
	printf("Owner Group ID:%d\n",s.st_gid);
	printf("Modified Time:%s\n",ctime(&s.st_mtime));
}
