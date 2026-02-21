#include<stdio.h>
#include<string.h>
int main(){
        char str[100];
        int i=0;
        printf("Enter string:\n");
        fgets(str,sizeof(str),stdin);
        while(str[i]!='\0'){
                if(str[i]>='A' && str[i]<='Z'){
                        str[i]=str[i]+32;
                }
                i++;
        }
        printf("LowerCase:\n%s",str);
}

