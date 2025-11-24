#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){
	char oldname[256],newname[256];
	printf("Enter oldname:");
	scanf("%s",oldname);
	printf("Enter new name:");
	scanf("%s",newname);
	if(rename(oldname,newname)==0){
		printf("file '%s' is renamed to '%s'.\n",oldname,newname);
	}
	else{
		printf("Error renaming file.\n");
	}
}
