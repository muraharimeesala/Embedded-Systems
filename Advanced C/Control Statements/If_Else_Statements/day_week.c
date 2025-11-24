#include<stdio.h>
int main(){
int day;
printf("Enter Days(1-7):");
scanf("%d",&day);
if(day==1)
printf("Day 1 is Sunday\n",day);
else if(day==2)
printf("Day 2 is Monday\n",day);
else if(day==3)
printf("Day 3 is Tuesday\n",day);
else if(day==4)
printf("Day 4 is Wednesday\n",day);
else if(day==5)
printf("Day 5 is Thursday\n",day);
else if(day==6)
printf("Day 6 is Friday\n",day);
else if(day==7)
printf("Day 7 is Saturday\n",day);
else
printf("Invalid Day");
}

