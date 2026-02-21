#include<stdio.h>
#include<string.h>
int main(){
char  str1[100],str2[100];
int i=0,j=0;
printf("Enter first string:");
fgets(str1,sizeof(str1),stdin);
printf("Enter second string:");
fgets(str2,sizeof(str2),stdin);
i=0;
while(str1[i]!='\0'){
if(str1[i]=='\n'){
str1[i]='\0';
break;
}
i++;
}
j=0;
while(str2[j]!='\0'){
if(str2[j]=='\n'){
str2[j]='\0';
break;
}
j++;
}
i=0;
while(str1[i]!='\0'){
i++;
}
j=0;
while(str2[j]!='\0'){
str1[i]=str2[j];
i++;
j++;
}
str1[i]='\0';
printf("After string concetenated:%s\n",str1);
}

