#include<stdio.h>
int main(){
char str[100];
int i=0,j,isPalindrome=1;
printf("Enter a string:");
scanf("%s",str);
for(j=0;str[j]!='\0';j++);
j--;
while(i<j){
if(str[i]!=str[j]){
isPalindrome=0;
break;
}
i++;
j--;
}
if(isPalindrome){
printf("Its a palindrome.\n");
}
else{
printf("Its not a palindrome.\n");
}
}
