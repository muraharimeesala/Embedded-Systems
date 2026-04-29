#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
int main(){
        FILE *srcfp,*destfp;
        int ch;
        srcfp=fopen("uppercase.txt","r");
        if(srcfp==NULL){
                perror("fopen file");
                exit(EXIT_FAILURE);
        }
        destfp=fopen("input.txt","w");
        if(destfp==NULL){
                perror("fopen file");
                exit(EXIT_FAILURE);
        }
        while((ch=fgetc(srcfp))!=EOF){
                fputc(tolower(ch),destfp);
        }
        printf("Data is converted into uppercase and written to another file.\n");
        fclose(srcfp);
        fclose(destfp);
}

