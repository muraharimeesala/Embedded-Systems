#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	char src[256],dest[256];
	FILE *fp1,*fp2;
	int ch;
	printf("Enter source file:");
	scanf("%s",src);
	printf("Enter destination file:");
	scanf("%s",dest);
	fp1=fopen(src,"r");
	if(!fp1){
		perror("fopen");
		exit(1);
	}
	fp2=fopen(dest,"w");
	while((ch=fgetc(fp1))!=EOF){
		fputc(ch,fp2);
	}
	printf("Contents are moved from '%s' to '%s' sucessfully.\n",src,dest);
	fclose(fp1);
	fclose(fp2);
}
