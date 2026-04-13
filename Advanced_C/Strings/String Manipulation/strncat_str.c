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
	printf("Before concatnate strings:\n");
	printf("%s\n",src);
	strncat(src,dest,4);
	printf("After concatnate strings:\n");
	printf("%s\n",src);
}
	


