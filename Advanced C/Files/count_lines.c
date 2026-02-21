#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
int main(){
	char line[1000];
        char largest_line[1000];
	FILE *fp;
	int count=0,words=0,ch;
	int max_length = 0;

	fp=fopen("count_lines.txt","r");
	if(fp==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while((ch=fgetc(fp))!=EOF){
		if(ch=='\n'){
		count++;
		}
		if(isspace(ch)){
			words++;
		}
		int len = strlen(ch);
		if (len > max_length) {
			max_length = len;
		       	strcpy(largest_line,len);
		}
        }

	printf("No of lines:%d\n",count);
	printf("No of Words:%d\n",words);
	printf("Largest Line:%s\n",largest_line);
}

