#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char source[1024],destination[1024];
	FILE *srcfp,*destfp;
	int pos=1,ch1,ch2;
	srcfp=fopen("source.txt","r");
	if(srcfp==NULL){
		perror("source fopen");
		exit(EXIT_FAILURE);
	}
	destfp=fopen("destination.txt","r");
	if(destfp==NULL){
		perror("destination fopen");
		exit(EXIT_FAILURE);
	}
	while(1){
		ch1=fgetc(srcfp);
		ch2=fgetc(destfp);
		if(ch1==EOF&&ch2==EOF){
			printf("Both the files are equal.\n");
			break;
		}
		if(ch1!=ch2){
			printf("Files difference at byte :%d\n",pos);
			break;
		}
		pos++;
	}
	fclose(srcfp);
	fclose(destfp);
}
