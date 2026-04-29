#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
/*int main(){
	char buff[1024];
	FILE *fp;
	fp=fopen("write_to_file.txt","w");
	if(fp==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	printf("Enter data:");
	fgets(buff,sizeof(buff),stdin);
	buff[strcspn(buff,"\n")]='\0';
	fputs(buff,fp);
	printf("------CONTENT------\n%s\n",buff);
	fclose(fp);
}
*/
/*int main(){
        char ch;
        FILE *fp;
        fp=fopen("write_to_file.txt","w");
        if(fp==NULL){
                perror("fopen");
                exit(EXIT_FAILURE);
        }
	printf("Enter character:");
	scanf("%c",&ch);
	fputc(ch,fp);
	printf("File created and data written successfully,\n");
	printf("-----CONTENT OF FILE------\n%c\n",ch);
	fclose(fp);
}
*/
int main(){
        char ch,buff[1024];
	int a;
	float b;
        FILE *fp;
        fp=fopen("write_to_file.txt","w");
        if(fp==NULL){
                perror("fopen");
                exit(EXIT_FAILURE);
        }
	printf("Enter string:");
	fgets(buff,sizeof(buff),stdin);
	buff[strcspn(buff,"\n")]='\0';
	printf("Enter character:");
	scanf("%c",&ch);
	printf("Enter integer:");
	scanf("%d",&a);
	printf("Enter float value:");
	scanf("%f",&b);
	fprintf(fp,"%s\n%c\n%d\n%.2f",buff,ch,a,b);
	printf("File created and data written successfully.\n");
	printf("------CONTENT OF FILE------\n%s\n%c\n%d\n%.2f\n",buff,ch,a,b);
	fclose(fp);
}

