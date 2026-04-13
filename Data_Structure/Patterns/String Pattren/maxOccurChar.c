#include<stdio.h>
#include<string.h>
int main(){
        char str[100];
        int freq[256]={0};
        int i=0,max=0;
	char result;
        printf("Enter string:\n");
        fgets(str,sizeof(str),stdin);
        while(str[i]!='\0'){
                if(str[i]!='\n')
                freq[(unsigned char)str[i]]++;
                i++;
        }
	while(i<256){
		if(freq[i]>max){
			max=freq[i];
			result=i;
		}
		i++;
	}
	printf("Maximum oucurs character:%c=%d\n",result,max);
}
