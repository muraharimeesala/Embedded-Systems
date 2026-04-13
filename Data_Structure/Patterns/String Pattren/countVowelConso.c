#include<stdio.h>
#include<string.h>
int main(){
	char str[100],ch;
	int vowel=0,conso=0;
	printf("Enter string:\n");
	fgets(str,sizeof(str),stdin);
	int i=0;
	while(str[i]!='\0'){
		ch=str[i];
		if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z')){
			if((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')){
			vowel++;
			}
			else{
				conso++;
			}
		}
		i++;
	}
	printf("Vowels=%d\n",vowel);
	printf("Consonants=%d\n",conso);
}
