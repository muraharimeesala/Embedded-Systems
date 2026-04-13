#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
int my_strlen(char str[]){
int len=0;
while(str[len]!='\0'){
len++;
}
printf("Length of the string:%d\n",len);
}
void my_strrev(char str[]){
int st=0;
int end=my_strlen(str)-1;
char temp;
while(st<end){
temp=str[st];
str[st]=str[end];
str[end]=temp;
st++;
end--;
}
}
int main(){
char str[100];
printf("Enter a string:\n");
//scanf("%s",str);
fgets(str,sizeof(str),stdin);
my_strrev(str);
printf("After reverse the string:%s\n",str);
}


