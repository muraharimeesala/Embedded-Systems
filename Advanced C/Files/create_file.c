#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char buff[1024];
	FILE *fp;
	fp=fopen("create_file.txt","w");
	if(fp==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	printf("Enter Data:");
        fgets(buff,sizeof(buff),stdin);
        buff[strcspn(buff,"\n")]='\0';
	if(fputs(buff,fp)==EOF){
		perror("fputs");
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	printf("File created and data written successfully.\n");
}
