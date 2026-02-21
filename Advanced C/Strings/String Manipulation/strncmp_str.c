#include<stdio.h>
#include<string.h>
int main(){
	char src[100],dest[100];
	printf("Enter first string:");
	fgets(src,sizeof(src),stdin);
	printf("Enter second string:");
	fgets(dest,sizeof(dest),stdin);
	src[strcspn(src,"\n")]='\0';
	dest[strcspn(dest,"\n")]='\0';
	int res=strncmp(src,dest,6);
	if(res==0){
	printf("Src and Dest are same.\n");
	}
	else if(res<0){
	printf("Src is smaller thaan dest.\n");
	}
	else{
	printf("Src is bigger than dest.\n");
	}
}
