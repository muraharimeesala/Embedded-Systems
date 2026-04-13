#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[]){
	char buff1[1024],buff2[1024];
	int fd1,fd2,pos=1;
	char c1,c2;
	size_t ret;
	if(argc!=3){
		printf("Usage:%s <file1><file2>.\n",argv[0]);
		exit(1);
	}
	char *file1=argv[1];
	char *file2=argv[2];
	printf("Enter content of file1:\n");
	fgets(buff1,sizeof(buff1),stdin);
	fd1=open(file1,O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd1<0){
		perror("open file1");
		exit(1);
	}
	write(fd1,buff1,sizeof(buff1));
	close(fd1);
	printf("Enter content of file2:\n");
        fgets(buff2,sizeof(buff2),stdin);
	fd2=open(file2,O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd2<0){
                perror("open file1");
                exit(1);
        }
	write(fd1,buff1,sizeof(buff1));
        close(fd2);
        fd1=open(file1,O_RDONLY);
        if(fd1<0){
                perror("open file");
                exit(1);
        }
	fd2=open(file2,O_RDONLY);
        if(fd2<0){
                perror("open file");
                exit(1);
        }
	// -------- Compare byte by byte --------
    while (read(fd1, &c1, 1) > 0 && read(fd2, &c2, 1) > 0) {
        if (c1 != c2) {
            printf("Files differ at byte %d\n", pos);
            close(fd1);
            close(fd2);
            return 0;
        }
        pos++;
    }

    // check if file sizes differ
    if (read(fd1, &c1, 1) != read(fd2, &c2, 1)) {
        printf("Files differ in size at byte %d\n", pos);
    } else {
        printf("Files are identical\n");
    }
}



