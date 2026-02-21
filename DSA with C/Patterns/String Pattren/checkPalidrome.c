#include<stdio.h>
#include<string.h>
int main(){
        char str[1024];
        int i=0,j;
	int flag=1;           //assume palindrome
        printf("Enter string:\n");
        fgets(str,sizeof(str),stdin);
	str[strcspn(str, "\n")] = '\0';
	j=strlen(str)-1;
	while(i<j){
		if(str[i]!=str[j]){
			flag=0;
			break;
		}
		i++;
		j--;
	}
	if(flag){
		printf("Its a palindrome\n");
	}
	else{
		printf("Its not a palidnrome\n");
	}
}

