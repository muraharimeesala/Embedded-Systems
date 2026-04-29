#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
void *threadFunc(void *arg){
	char *str=(char*)arg;
	int flag=1;
	printf("ThreadFunc: Received string:\n%s",str);
	printf("ThreadFunc: Checking string is palidrome or not.....\n");
	int i=0;
	int j=strlen(str)-1;
	if (str[j] == '\n') {
        str[j] = '\0';
        j--;
	}
	printf("Thread: Received string: %s\n", str);
        printf("Thread: Checking palindrome...\n");
	while(i<j){
		if(str[i]!=str[j]){
			flag=0;
			break;
		}
		i++;
		j--;
	}
	if(flag){
		printf("%s is a Palindrome\n",str);
	}
	else{
		printf("%s is NOT a palindrome\n",str);
	}
	return NULL;
}
int main(){
	pthread_t tid;
	char str[100];
	printf("Enter a string:\n");
	fgets(str,sizeof(str),stdin);
	printf("Main: Input string:%s\n",str);
	printf("Main: Creating thread for checking string is palinrome or not...\n");
	if(pthread_create(&tid,NULL,threadFunc,str)==-1){
		perror("pthread_create");
		exit(1);
	}
	printf("Main: Thread created continue program execution..\n");
	if(pthread_join(tid,NULL)==-1){
		perror("pthread_join");
		exit(1);
	}
	printf("Main: Thread execution completed\n");
	printf("Main: exiting program\n");
	return 0;
}
