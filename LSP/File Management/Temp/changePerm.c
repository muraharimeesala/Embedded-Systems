#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
	char filename[256];
	int perm;
	printf("Enter filename:");
	scanf("%s",filename);
	printf("Enter permissions(444,0644,777):");
	scanf("%d",&perm);
	if(chmod(filename,perm)!=0){
		perror("chmod");
		exit(1);
	}
	printf("Permisstions of %s is changed to %d.\n",filename,perm);
}

