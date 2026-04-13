#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Before execv\n");
	char *arg[]={"ls","-l",NULL};
	execv("/bin/ls",arg);
	printf("After execv\n");
}
