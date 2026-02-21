#include<stdio.h>
#include<string.h>
int main(){
        char str[1024];
        int i=0,j=0,start=0,end=0;
        printf("Enter string:\n");
        fgets(str,sizeof(str),stdin);
        str[strcspn(str,"\n")]='\0';
	while(str[i]!='\0'){
		i++;
	}
	end=i-1;
	while(str[start]==' ')
		start++;
	while(str[end]==' ')
		end--;
	for(i=start;i<=end;i++){
		str[j++]=str[i];
	}
	str[j]='\0';
	printf("Updated string:\n'%s'\n",str);
}

