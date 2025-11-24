#include<stdio.h>
#include<stdlib.h>          //For exit
#include<sys/stat.h>       //For mkdir
#include<sys/types.h>     //For mode_t
int main(){
	int status;
	status=mkdir("Test",0755);
	if(status==0){
		printf("Directory 'Test' is successfully created.\n");
	}
	else{
		printf("Failed to create directory in existing directory.\n");
		exit(1);
	}
}
