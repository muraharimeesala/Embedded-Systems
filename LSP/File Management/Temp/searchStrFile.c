#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char file[256];
	char line[512];
	char search[256];
	FILE *fp;
	int line_num=0;
	int found=0;
	printf("Enter File:");
	scanf("%s",file);
	printf("Enter string to search:");
	scanf("%s",search);
	fp=fopen(file,"r");
	if(!fp){
		perror("fopen");
		exit(1);
	}
	while(fgets(line,sizeof(line),fp)){
		line_num++;
		if(strstr(line,search)){
				printf("String '%s' found at '%d' lin.\n",search,line_num);
				found=1;
		}
	}
	if(!found){
		printf("String '%s' is not found in the file.\n",search);
	}
	fclose(fp);
}
