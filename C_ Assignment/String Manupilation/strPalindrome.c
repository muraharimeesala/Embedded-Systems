#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i,j,flag=1;
	printf("Enter string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++);
	i=0;
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
		printf("Its a palidndrome.\n");
	}
	else{
		printf("Its not a palindrome.\n");
	}
}


