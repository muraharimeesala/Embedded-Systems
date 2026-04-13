#include <stdio.h>
#include <unistd.h>

int main(){
	fork();
	printf("Running Process ID: %d\n",getpid());
	return 0;
}
