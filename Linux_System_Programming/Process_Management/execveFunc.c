#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
int main(){
	char *argv[] = {"ls", "-l", NULL};
	char *envp[] = {NULL};
	execve("/bin/ls", argv, envp);
	return 0;
}
