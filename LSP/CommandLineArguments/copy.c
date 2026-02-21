#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	char msg[1024],buff[1024];
	int fd1,fd2;
	size_t ret;
	if(argc!=3){
		printf("Usage:%s <src><dest>\n",argv[0]);
		exit(1);
	}
	char *src=argv[1];
	char *dest=argv[2];
	printf("Enter content of source file:\n");
	fgets(msg,sizeof(msg),stdin);
	fd1=open(src,O_WRONLY|O_CREAT,0664);
        if(fd1<0){
                perror("open");
                exit(1);
	}
	write(fd1,msg,sizeof(msg));
	close(fd1);
	fd1=open(src,O_RDONLY);
	if(fd1<0){
		perror("open");
		exit(1);
	}
	fd2=open(dest,O_WRONLY|O_CREAT,0664);
	if(fd2<0){
		perror("open");
		exit(1);
	}
	while((ret=read(fd1,buff,sizeof(buff)))>0){
		write(fd2,buff,ret);
		buff[ret]='\0';
	}
	close(fd1);
	close(fd2);
	printf("-----SOURCE-----\n%s",msg);
	printf("File '%s' contents are copied to '%s'file.\n",src,dest);
	printf("-----DESTINATION-----\n%s",buff);
}

