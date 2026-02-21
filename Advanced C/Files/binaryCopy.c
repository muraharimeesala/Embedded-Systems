#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char src[256],dest[256];
	FILE *fp1,*fp2;
	unsigned char buff[1024];
	size_t n;
	printf("Enter source file:");
	scanf("%s",src);
	printf("Enter destination file:");
	scanf("%s",dest);
	fp1=fopen(src,"rb");
	if(!fp1){
		printf("Error open.\n");
		exit(1);
	}
	fp2=fopen(dest,"wb");
	if(!fp2){
		printf("Error open.\n");
		exit(1);
	}
	while((n=fread(buff,1,n,fp1))>0){
		fwrite(buff,1,n,fp2);
	}
	printf("Enter file copied sucessfully.\n");
	fclose(fp1);
	fclose(fp2);
}
