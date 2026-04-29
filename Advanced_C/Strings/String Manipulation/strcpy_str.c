#include<stdio.h>
#include<string.h>
int main(){
	char src[100],dest[100];
	printf("Enter a string:");
	fgets(src,sizeof(src),stdin);
	src[strcspn(src,"\n")]='\0';
	printf("Bofore copying the string:%s\n",dest);
	strcpy(dest,src);
	printf("After copying the string:%s\n",dest);
}

