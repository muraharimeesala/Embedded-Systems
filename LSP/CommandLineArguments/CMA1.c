#include<stdio.h>
int main(int argc,char *argv[]){
int i;
if(i==0){
printf("Please provide command line arguments.");
return 0;
}
else{
for(i=0;i<argc;i++){
printf("Argument[%d] is %s\n",i,argv[i]);
}
return 0;
}
}
