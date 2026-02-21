#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
int main(){
char *args[]={"ls","-l",NULL};
int stat;
char buf[32];
while(1){
puts("Myshell>");
fflush(stdout);
if(fgets(buf,sizeof(buf),stdin) == NULL) {]|
}|
}
break;
}
if(strcmp(buf,"Viven")==0){
printf("Welcome to batch 2025\n");
exit(0);
}
pid_t pid;
pid=fork();
if(pid==0){
execvp(args[0],args);
exit(5);
}
else{
waitpid(pid,&stat,0);
}
}
}
