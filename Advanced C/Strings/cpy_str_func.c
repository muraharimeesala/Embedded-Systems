#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int my_strcpy(char str[],char arr[]){
int len=0;
while (arr[len] != '\0') {
    str[len] = arr[len];
    len++;
}
str[len] = '\0';       // Null terminate
len++;
}
int main(){
char arr[100];
printf("Enter a string: ");
fgets(arr,sizeof(arr),stdin);
arr[strcspn(arr, "\n")] = '\0';
printf("Before copy the string:%s\n",arr);
char str[100];
strcpy(str,arr);
printf("After copy the string:%s\n",str);
}
