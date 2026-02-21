#include<stdio.h>
struct Time{
int hours;
int min;
int sec;
}time;
int main(){
time.hours=12;
time.min=45;
time.sec=54;
printf(" Time Structure:\n");
printf("Hours: %dh Min: %dm Sec: %ds\n",time.hours,time.min,time.sec);
}
