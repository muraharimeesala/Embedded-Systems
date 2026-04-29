// Develop a program that attaches to a previously created shared memory segment using shmat and detaches using shmdt.

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(1);
    }

    void *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *)-1)
    {
        perror("shmat");
        exit(1);
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
