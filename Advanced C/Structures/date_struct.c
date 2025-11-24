#include<stdio.h>
struct Date{
int day;
int month;
int year;
}m;
int main(){
m.day=13;
m.month=10;
m.year=2000;
printf("Date of birth:\n");
printf("%d/%d/%d\n",m.day,m.month,m.year);
}
