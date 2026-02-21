#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
int main(){
	struct sigaction old_sa,ign_sa;
	ign_sa.sa_handler=SIG_IGN;            /* ignore handler */
	ign_sa.sa_flags=0;
	sigemptyset(&ign_sa.sa_mask);
	/* Save current action for SIGCHLD */
	if(sigaction(SIGCHLD,NULL,&old_sa)==-1){       
		perror("sigaction(GET)");
		exit(1);
	}
	printf("Temporarily IGNORING CHILD for 5 seconds...\n");
	if(sigaction(SIGCHLD,&ign_sa,NULL)==-1){
		printf("sigaction(SET)");
		exit(1);
	}
	pid_t pid=fork();
	if(pid==-1){
		perror("fork");
		exit(1);
	}
	else if(pid==0){
		  /* child */
		printf("Child PID:%d sleeping 1sec then exiting.\n",getpid());
		sleep(1);
		exit(0);
	}
	else{     /* child */
		printf("Parent PID:%d\nspawned Child:%d\n",getpid(),pid);
		/* During ignore window the child will not produce a zombie (POSIX: implementing SIG_IGN for SIGCHLD may reap children). */
		sleep(5);
		exit(0);
		/* Restore previous action */
		if(sigaction(SIGCHLD,&old_sa,NULL)==-1){
			perror("sigaction(RESTORE)");
			exit(0);
		}
		printf("Restored previous SIGCHLD action,now waitpid() to reap any children if needed.\n");
		/* Try to reap any exited children to avoid zombies */
		int status;
		pid_t w;
		while((w=waitpid(-1,&status,WNOHANG))>0){
			printf("Reaped child :%d\n",w);
		}
	}
}
