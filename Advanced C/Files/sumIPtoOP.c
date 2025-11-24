#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char ip[256],op[256];
	FILE *fp1,*fp2;
	int num,sum=0;
	printf("Enter input file:");
	scanf("%s",ip);
	fp1=fopen(ip,"r");
	if(!fp1){
		printf("input file error.\n");
		exit(1);
	}
	while(fscanf(fp1,"%d",&num)==1){
		sum+=num;
	}
	fclose(fp1);
	printf("Enter output file:");
	scanf("%s",op);
	fp2=fopen(op,"w");
	fprintf(fp2,"Sum=%d\n",sum);
	printf("Sum written to '%s' file.\n",op);
	fclose(fp2);
}



