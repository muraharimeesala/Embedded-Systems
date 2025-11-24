#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i,k,j,start=0,len=0,frq[256];
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++){
		for(k=0;k<256;k++)     // reset frq array of each i loop
			frq[k]=0;
		for(j=i;str[j]!='\0';j++){
			unsigned char ch=str[j];
			if(frq[ch]==1)          //repeated char found it will break
				break;
			frq[ch]=1;
			if(j-i+1>len){           //updates the sub str length
                len=j-i+1;
                start=i;
		}
		}
	}
	for(i=start;i<start+len;i++){
		printf("%c",str[i]);
	}
}
