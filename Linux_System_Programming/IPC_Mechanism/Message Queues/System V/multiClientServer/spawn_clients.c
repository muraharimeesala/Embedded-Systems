#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    for(int i=0;i<3;i++)
    {
        if(fork()==0)
        {
            execl("./client","client",NULL);
        }
    }

    sleep(5);
    return 0;
}
