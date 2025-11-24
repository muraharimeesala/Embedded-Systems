#include<stdio.h>
int strCopy(char *src,char *dest){
	while(*src!='\0'){
		*dest=*src;
		src++;
		dest++;
	}
	*dest='\0';
}
int main(){
	char str1[100],str2[100];
	printf("Enter a string:");
	fgets(str1,sizeof(str1),stdin);
	int i=0;
	while(str1[i]!='\0'){
		if(str1[i]=='\n'){
			str1[i]='\0';
			break;
		}
		i++;
	}
	strCopy(str1,str2);
	printf("Original String:%s\n",str1);
	printf("Copying String:%s\n",str2);
}


