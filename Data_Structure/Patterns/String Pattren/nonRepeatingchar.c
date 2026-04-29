#include<stdio.h>
#include<string.h>
int main(){
        char str[100];
        int freq[256]={0};
        int i=0,found=0;
        printf("Enter string:\n");
        fgets(str,sizeof(str),stdin);
        while(str[i]!='\0'){
                if(str[i]!='\n')
                freq[(unsigned char)str[i]]++;
                i++;
        }
	printf("First non repeating characters:");
        for(i=0;str[i]!='\0';i++){
                if(str[i]!='\n' && freq[(unsigned char)str[i]]==1){
                        printf("%c",str[i]);
			found=1;
                }
        }
	if(!found){
		printf("There is no non repeating characters\n");
	}
	printf("\n");
}

