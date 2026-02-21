#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char buff[1024],ch;
	FILE *fp;
	int count=0;
	fp=fopen("count_char.txt","r");
	if(fp==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while((ch=fgetc(fp))!=EOF){
		count++;
	}
	printf("No of characters:%d\n",count);
	fclose(fp);
}
