#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
int main(){
	char buff[1024];
	FILE *fp;
	int ch,words=0;
	fp=fopen("count_words.txt","r");
	if(fp==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while((ch=fgetc(fp))!=EOF){
		if(isspace(ch)){
			words++;
		}
	}
	printf("No of words:%d\n",words);
	fclose(fp);
}
