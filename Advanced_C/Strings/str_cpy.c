#include<stdio.h>
#include<string.h>
int main(){
char arr[100];
printf("Enter a string: ");
fgets(arr,sizeof(arr),stdin);
printf("Before copy the string:%s ",arr);
char str[100];
strcpy(str,arr);
printf("After copy the string:%s ",str);
}
