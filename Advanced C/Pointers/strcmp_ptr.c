#include<stdio.h>
#include<string.h>
int main(){
	char src[100],dest[100];
	char *p1,*p2;
	printf("Enter first string:");
	fgets(src,sizeof(src),stdin);
	printf("Enter second string:");
	fgets(dest,sizeof(dest),stdin);
	src[strcspn(src,"\n")]='\0';
	dest[strcspn(dest,"\n")]='\0';
	p1=src;
	p2=dest;
	int res=strcmp(p1,p2);
	if(res==0){
	printf("Src and Dest are same.\n");
	}
	else if(res<0){
	printf("Src is smaller than dest.\n");
	}
	else{
	printf("Src is bigger than dest.\n");
	}
}
