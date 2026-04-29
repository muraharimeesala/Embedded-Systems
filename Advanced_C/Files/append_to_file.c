#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char buff[1024];
	FILE *fp;
	fp=fopen("append_to_file.txt","a");
	if(fp==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	printf("Enter string to append:");
	fgets(buff,sizeof(buff),stdin);
	fputs(buff,fp);
	printf("Data appended successfully.\n");
	printf("------CONTENT OF THE FILE------\n");
	printf("%s",buff);
	fclose(fp);
}
