#include<stdio.h>
int main(){
int days,month,year,flag=1,isleap=0;
printf("Enter data(dd/mm/yyyy):");
scanf("%d%d%d",&days,&month,&year);
if((year%4==0)&&(year%100!=0)||(year%400==0))
isleap=1;
if(year<2000 || year>2025 || month<1 || month>12 || days<1 || days>31)
flag=0;
else if(month==2){
if(days==31 || days==30 || days==29 && !isleap)
flag=0;
}
else if(month==2 || month==4 || month==6 || month==9)
{
if(days=31)
flag=0;
}
if(flag==0)
printf("Not valid date\n");
else
printf("Valid date\n");
}
