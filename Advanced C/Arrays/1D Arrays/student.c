#include<stdio.h>
int main(){
int num,i;
float total=0,avg;
printf("Enter the no of students:");
scanf("%d",&num);
float marks[num];
printf("Enter marks for %d students:\n",num);
for(i=0;i<num;i++){
printf("Student-%d:",i+1);
scanf("%f",&marks[i]);
total+=marks[i];
}
avg=total/num;
printf("Total marks:%.2f\n",total);
printf("Average marks:%.2f\n",avg);
printf("\n Marks for all students:\n");
for(i=0;i<num;i++){
printf("Student %d:%.2f\n",i+1,marks[i]);
}
}
