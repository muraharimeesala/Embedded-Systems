#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Before exec\n");
	char *arg[]={"ls","-l",NULL};
	execvp("ls",arg);
	printf("After exec\n");
}
