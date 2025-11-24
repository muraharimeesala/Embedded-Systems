#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sigint_handler(int signo,siginfo_t *info,void *context) {
    printf("\nReceived signal %d from PID: %d, UID: %d\n",
           signo,info->si_pid,info->si_uid);
}

int main(){
    struct sigaction action;
    sigemptyset(&action.sa_mask);
    action.sa_sigaction=sigint_handler;
    action.sa_flags=SA_SIGINFO; // Use advanced handler

    if(sigaction(SIGINT,&action,NULL)==-1){
        perror("sigaction");
        return 1;
    }
    printf("Press Ctrl+C to trigger SIGINT (Advanced handler)\n");
    while(1){
        printf("Waiting...\n");
        sleep(2);
    }
}

