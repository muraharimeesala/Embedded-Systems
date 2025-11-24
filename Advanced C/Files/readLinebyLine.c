#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char file[256],line[256];
	FILE *fp;
	int lineNum=1;
	printf("Enter file name:");
	scanf("%s",file);
	fp=fopen(file,"r");
	if(!fp){
		printf("error fopen'\n");
		exit(1);
	}
	while(fgets(line,sizeof(line),fp)){
		printf("%d:%s",lineNum,line);
		lineNum++;
	}
	fclose(fp);
}
