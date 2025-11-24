#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char filename[100];
	FILE *fp;
	int lines=0;
	char ch;
	printf("Enter file name:");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	if(!fp){
		perror("opendir\n");
		exit(1);
	}
	while((ch=fgetc(fp))!=EOF){
		if(ch=='\n'){
			lines++;
		}
	}
	fclose(fp);
	printf("Total lines in %s: %d\n",filename,lines);
}
