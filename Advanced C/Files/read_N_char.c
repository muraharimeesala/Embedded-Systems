#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	FILE *fp;
	long size;
	int N,ch;
	printf("Enter N character to read:");
	scanf("%d",&N);
	fp=fopen("read_N_char.txt","r");
	if(fp==NULL){
		perror("fopen file");
		exit(EXIT_FAILURE);
	}
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	if(N>size)
	N=size;
	fseek(fp,-N,SEEK_END);
	while((ch=fgetc(fp))!=EOF){
		putchar(ch);
	}
	fclose(fp);
}

