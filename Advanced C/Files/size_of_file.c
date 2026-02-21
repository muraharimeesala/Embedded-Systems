#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char buff[1024];
	FILE *fp;
	int ch;
	fp=fopen("source.txt","r");
	if(fp==NULL){
		perror("source fopen");
		exit(EXIT_FAILURE);
	}
	long int size;
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	printf("File Size: %ld\n",size);
	fclose(fp);
}


