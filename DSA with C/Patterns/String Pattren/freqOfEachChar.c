#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int freq[256]={0};
	int i=0;
	printf("Enter string:\n");
	fgets(str,sizeof(str),stdin);
	while(str[i]!='\0'){
		if(str[i]!='\n')
		freq[(unsigned char)str[i]]++;
		i++;
	}
	for(i=0;i<256;i++){
		if(freq[i]>0){
			printf("%c=%d times\n",i,freq[i]);
		}
	}
}

