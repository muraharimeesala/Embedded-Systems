#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
int main(){
	FILE *fp;
	char file[256];
	char line[1024];
	printf("Enter filename:");
	scanf("%s",file);
	fp=fopen(file,"r");
	if(!fp){
		perror("fopen.\n");
		exit(1);
	}
	printf("Contents of the file:\n");
	while(fgets(line,sizeof(line),fp)){
		printf("%s",line);
	}
	fclose(fp);
}
