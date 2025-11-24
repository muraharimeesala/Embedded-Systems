#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char filename[256];
	char text[256];
	FILE *fp;
	printf("Enter file name:");
	scanf("%s",filename);
	getchar();
	printf("Enter text:");
	fgets(text,sizeof(text),stdin);
	fp=fopen(filename,"a");
	if(!fp){
		perror("fopen");
		exit(1);
	}
	fputs(text,fp);
	fclose(fp);
	printf("Text Appened Sucessfully to %s\n",filename);
}
