#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int file1 = open("src.txt", O_RDONLY);
	int file2 = open("dest.txt", O_WRONLY);
	char buffer[100];
	int n;
	while((n = read(file1, buffer, 100)) > 0)
	{
		write(file2, buffer, n);
	}
	return 0;
}
