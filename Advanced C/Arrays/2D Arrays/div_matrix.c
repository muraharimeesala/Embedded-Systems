#include<stdio.h>
int main(){
int rows,cols;
    int num1[2][3],num2[2][3],div[2][3],i,j;
    printf("enter first matrix elements:\n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
        printf("elements [%d][%d]:",i,j);
        scanf("%d",&num1[i][j]);
        }
    }
    printf("enter second matrix elements:\n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
        printf("elements [%d][%d]:",i,j);
            scanf("%d",&num2[i][j]);
        }
    }
        for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
        div[i][j]=num1[i][j]/num2[i][j];
        }
    }
    printf("The div of two matrix:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
        printf("%d\t",div[i][j]);
        }
        printf("\n");
    }
}
