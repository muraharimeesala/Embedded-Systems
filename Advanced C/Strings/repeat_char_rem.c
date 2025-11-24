#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i,j,k;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++){
		for(j=i+1;str[j]!='\0';){
		if(str[i]==str[j]){
			for(k=j;str[k]!='\0';k++){
				str[k]=str[k+1];
			}
		}
			else{
				j++;

			}
		}
	}
	printf("String after removing repeated characters:%s",str);
}

