#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	char buff[1024],ch;
	FILE *fp;
	fp=fopen("fseek_file.txt","r+");
	if(fp==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fseek(fp,6,SEEK_SET);
	fputs("Hi",fp);
	while((ch=getc(fp))!=EOF){
		printf("%c",ch);
	}
	fclose(fp);
}
/*
        char buff[1024],ch;
        FILE *fp;
        fp=fopen("fseek_file.txt","r");
        if(fp==NULL){
                perror("fopen");
                exit(EXIT_FAILURE);
        }
        fseek(fp,-6,SEEK_CUR);
        while((ch=getc(fp))!=EOF){
                printf("%c",ch);
        }
        fclose(fp);
}
*//*
char buff[1024],ch;
        FILE *fp;
        fp=fopen("fseek_file.txt","r");
        if(fp==NULL){
                perror("fopen");
                exit(EXIT_FAILURE);
        }
        fseek(fp,-6,SEEK_END);
        while((ch=getc(fp))!=EOF){
                printf("%c",ch);
        }
        fclose(fp);
}
*/

