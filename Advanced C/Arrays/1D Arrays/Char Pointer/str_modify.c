#include<stdio.h>
#include<string.h>
int main(){
char *ptr="Linux";
char arr[100];
printf("String is:\n%s\n",ptr);
printf("Address of string:\n%p\n",&ptr);
strcpy(arr,ptr);
arr[2]='m';
printf("Modify string is:\n%s\n",arr);
printf("Address of modify string:\n%p\n",&ptr);
}
