#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
	char oldname[20],newname[20];
	printf("Enter the old name:");
	fgets(oldname,sizeof(oldname),stdin);
	printf("Enter the new name:");
	fgets(newname,sizeof(newname),stdin);
	rename(oldname,newname);
	printf("File renamed successfully");
	return 0;
}
