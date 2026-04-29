#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{
	char dir[100];
	printf("Enter the directory name: ");
	scanf("%s",dir);
	mkdir(dir,0777);
	printf("Directory created\n");
	return 0;
}
