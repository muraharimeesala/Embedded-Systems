#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	char filename[20];
	printf("Enter the file name to be deleted\n");
	scanf("%s",filename);

	if(remove(filename)==0)
	{
		printf("File deleted successfully\n");
	}
	else
	{
		printf("File deletion failed\n");
	}
	return 0;
}
