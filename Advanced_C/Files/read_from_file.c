#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
/*int main(){
	char ch;
	FILE *fp;
	size_t ret;
	fp=fopen("read_from_file.txt","r");
	if(fp==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	printf("------CONTENT OF THE FILE------\n");
	while((ch=fgetc(fp))!=EOF){
	printf("%c",ch);
	}
	fclose(fp);
}
*/
int main(){
        char ch,buff[1024];
        FILE *fp;
        size_t ret;
        fp=fopen("read_from_file.txt","r");
        if(fp==NULL){
                perror("fopen");
                exit(EXIT_FAILURE);
        }
	printf("------CONTENT OF THE FILE------\n");
	while((fgets(buff,sizeof(buff),fp))!=NULL){
		printf("%s",buff);
	}
	fclose(fp);
}
	

