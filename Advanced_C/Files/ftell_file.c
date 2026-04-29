#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
        char buff[1024],ch;
        FILE *fp;
        fp=fopen("ftell_file.txt","r+");
        if(fp==NULL){
                perror("fopen");
                exit(EXIT_FAILURE);
        }
        fseek(fp,0,SEEK_END);
	long int ret=ftell(fp);
	if(ret<0){
		perror("ftell");
		exit(EXIT_FAILURE);
	}
        while((ch=getc(fp))!=EOF){
		printf("%c",ch);
        }
	printf("SIZE=%ld\n",ret);
        fclose(fp);
}

