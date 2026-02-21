#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char src[1024],dest[1024];
	FILE *srcfp,*destfp;
	int ch;
	srcfp=fopen("source.txt","r");
	if(srcfp==NULL){
		perror("source fopen");
		exit(EXIT_FAILURE);
	}
	destfp=fopen("destination.txt","w");
	if(destfp==NULL){
		perror("destination fopen");
		exit(EXIT_FAILURE);
	}
	while((ch=fgetc(srcfp))!=EOF){
		fputc(ch,destfp);
	}
	printf("CONTENT OF DEST FILE\n%s\n",dest);
	fclose(srcfp);
	fclose(destfp);
}
