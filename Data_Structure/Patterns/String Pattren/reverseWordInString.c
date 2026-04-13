#include<stdio.h>
#include<string.h>
void reverse(char str[1024],int l,int r){
	char temp;
	while(l<r){
		temp=str[l];
		str[l]=str[r];
		str[r]=temp;
		l++;
		r--;
	}
}
int main(){
	char str[1024];
	int i=0,start=0;
	printf("Enter string:\n");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	while(1){
		if(str[i]==' ' || str[i]=='\0'){
			reverse(str,start,i-1);
			if(str[i]=='\0')
			break;
			start=i+1;
		}
		i++;
	}
	reverse(str,0,i-1);
	printf("Updated String:\n%s\n",str);
}
