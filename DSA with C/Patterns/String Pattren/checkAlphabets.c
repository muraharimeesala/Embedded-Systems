#include<stdio.h>
#include<string.h>
int main(){
        char str[100];
        int i=0;
	int isalpha=1;
        printf("Enter string:\n");
        fgets(str,sizeof(str),stdin);
        while(str[i]!='\0'){
		if(str[i]=='\n'){
		i++;
		continue;
		}
		if(!((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))){
			isalpha=0;
			break;
		}
		i++;
	}
	if(isalpha){
		printf("String contains only alphabets\n");
	}
	else{
		printf("Striing contains non-alphabets\n");
	}
}


