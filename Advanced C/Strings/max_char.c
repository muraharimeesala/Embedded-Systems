#include<stdio.h>
#include<stdlib.h>
int main(){
	char str[100],frq[256]={0},maxChar;
	int i,max=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	for(i=0;i<str[i]!='\0';i++){
		if(str[i]!='\0'){
			frq[(unsigned char)str[i]]++;
		}
	}
	for(i=0;i<256;i++){
		if(frq[i]>max){
			max=frq[i];
			maxChar=i;
		}
	}
	printf("Maximum occers character:%c\n",maxChar);
	printf("Frequncy:%d\n",max);
}

