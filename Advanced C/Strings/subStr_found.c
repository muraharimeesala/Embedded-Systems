#include<stdio.h>
#include<string.h>
int main(){
	char str[100],sub[100];
	int i,j,found;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]!='\0';
	printf("Enter substring to search:");
	fgets(sub,sizeof(sub),stdin);
	str[strcspn(sub,"\n")]!='\0';
	int lenstr=strlen(str);
	int lensub=strlen(sub);
	found=0;
	for(i=0;i<=lenstr-lensub;i++){
		for(j=0;j<lensub;j++){
			if(str[i+j]!=sub[j]){
			break;
			}
		}
		if(j==lensub){
			found=1;
			break;
		}
	}
	if(found){
	       printf("Substring \"%s\" found in the \"%s\".\n",sub,str);
	}
	else{
	       printf("Substring \"%s\" not found in the \"%s\".\n",sub,str);
	}
}


