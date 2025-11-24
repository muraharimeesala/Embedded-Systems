#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
int main(){
	char file[512];
	FILE *fp;
	int c,words=0,inword=0;
	printf("Enter file:");
	scanf("%s",file);
	fp=fopen(file,"r");
	if(!fp){
		printf("fopen error.\n");
		exit(1);
	}
	while((c=fgetc(fp))!=EOF){
		if(isspace(c)){
			inword=0;
		}
		else if(inword==0){
				inword=1;
				words++;
		}
	}
	printf("File '%s' contains '%d' words\n",file,words);
	fclose(fp);
}


