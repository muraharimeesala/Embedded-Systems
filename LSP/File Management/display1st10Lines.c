#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char file[256];
	int count=0;
	char line[512];
	FILE *fp;
	printf("Enter file:");
	scanf("%s",file);
	fp=fopen(file,"r");
	if(!fp){
		perror("fopen");
		exit(1);
	}
	while(fgets(line,sizeof(line),fp)&& count<10){
		printf("%s",line);
		count++;
	}
	fclose(fp);
}

