#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
        //char buff[1024];
        FILE *fp;
        int ch;
        fp=fopen("source.txt","r");
        if(fp==NULL){
                perror("source fopen");
                exit(EXIT_FAILURE);
        }
        long int size;
	int N=20;
        fseek(fp,0,SEEK_END);
	size=ftell(fp);
	if(N>size)
	N=size;
	fseek(fp,-N,SEEK_END);
	printf("Last %d characters:\n",N);
	while((ch=fgetc(fp))!=EOF){
		putchar(ch);
	}
        fclose(fp);
}

