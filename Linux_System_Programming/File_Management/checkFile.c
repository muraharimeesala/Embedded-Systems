#include<stdio.h>
#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
int main()
{
	char filename[20];
	printf("Enter the filename: ");
	scanf("%s",filename);
	struct stat st;
	if(stat(filename,&st)==0)
	{
		printf("File exists\n");
	}
	else
	{
		printf("File does not exist\n");
	}
}
