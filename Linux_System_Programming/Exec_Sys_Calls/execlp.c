#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Before exec\n");
	execlp("ls","-l",NULL);
	printf("After exec\n");
}
