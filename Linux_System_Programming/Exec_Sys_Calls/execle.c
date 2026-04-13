#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Before exec\n");
	char *envp[] = {"PATH=/bin", "USER=test", NULL};
	execle("/bin/ls","ls","-l",NULL,envp);
	printf("After exec\n");
}
