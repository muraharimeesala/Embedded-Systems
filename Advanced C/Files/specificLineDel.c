#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char file[256],temp[256];
	FILE *fp,*ft;
	int deleteLine,currentLine=1;
	char buff[1024];
	printf("Enter file name:");
	scanf("%s",file);
	printf("Enter line to delete:");
	scanf("%d",&deleteLine);
	fp=fopen(file,"r");
	if(!fp){
		printf("Error to open.\n");
		exit(1);
	}
	printf("Enter temparary file:");
	scanf("%s",temp);
	ft=fopen(temp,"w");
	if(!ft){
		printf("Error to fopen.\n");
		exit(1);
	}
	while(fgets(buff,sizeof(buff),fp)){
		if(currentLine!=deleteLine){
			fputs(buff,ft);
		}
		currentLine++;
	}
	fclose(fp);
	fclose(ft);
	remove(file);
	rename(temp,file);
	printf("Line '%d' is deleted sucessfully.\n",deleteLine);
}
			
