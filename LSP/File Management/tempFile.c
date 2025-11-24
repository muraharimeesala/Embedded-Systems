#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
int main(){
	FILE *fp;
	char tempfile[L_tmpnam];
	char data[256];
	printf("Enter data to tempararoy file:");
	fgets(data,sizeof(data),stdin);
	tmpnam(tempfile);
	fp=fopen(tempfile,"w");
	if(!fp){
		perror("fopen");
		exit(1);
	}
	fputs(data,fp);
	fclose(fp);
	printf("Data writed successfully to %s Tempfile.\n",tempfile);
}

