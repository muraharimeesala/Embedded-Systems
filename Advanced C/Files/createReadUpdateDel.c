#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int createFile(){
	char name[256],data[512];
	FILE *fp;
	printf("Enter file name:");
	scanf("%s",name);
	fp=fopen(name,"w");
	if(!fp){
		printf("Error fopen.\n");
		exit(1);
	}
	printf("Enter contents:\n");
        getchar();
        int c; 
	while((c=getchar())!='~'){
		fputc(c,fp);
	}
	fclose(fp);
	printf("File created successfully,\n");
}
int readFile(){
	char name[256];
	FILE *fp;
	printf("Enter filename:");
	scanf("%s",name);
	fp=fopen(name,"r");
	if(!fp){
		printf("Error fopen.\n");
		exit(1);
	}
	int c;
	printf("\n-----Contents-----\n");
	while((c=fgetc(fp))!=EOF){
		putchar(c);
	}
	printf("-------------------");
	fclose(fp);
}
int updateFile(){
	char name[256],data[512];
	FILE *fp;
	printf("Enter file name to update:");
	scanf("%s",name);
	fp=fopen(name,"a");
	if(!fp){
		printf("Update error.\n");
		exit(1);
	}
	printf("Enter contents to update:");
	getchar();
	int c;
	while((c=getchar())!='~'){
		fputc(c,fp);
	}
	fclose(fp);
	printf("Contents updated.\n");
}
int deleteFile(){
	char name[256];
	printf("Enter file to delete:");
	scanf("%s",name);
	if(remove(name)==0){
		printf("'%s' File is deleted successfully.\n",name);
	}
	else{
		printf("Error to delete.\n");
	}
}
int main(){
	int choice;
	while(1){
		printf("\n---FILE MANAGEMENT MENU---\n");
		printf("1.Create\n2.Read\n3.Update\n4.Delete\n5.exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:createFile();
			       break;
		        case 2:readFile();
			       break;
		        case 3:updateFile();
			       break;
			case 4:deleteFile();
			       break;
			case 5:exit(0);
			       break;
			default:
			       printf("Invalid choice.\n");
		}
	}
}

