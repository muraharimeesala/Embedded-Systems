#include <stdio.h>
#include <stdlib.h>  // exit, system
#include <sys/ipc.h> // key_t, IPC_PRIVATE
#include <sys/sem.h> // semget, semctl, semop, semtimedop
#include <sys/shm.h> // shmget, shmat, shmdt
#include <unistd.h>  // write, read, fork, execl

#define SHM_SIZE 1024

union semun {
  int val; // Value for SETVAL
};

void sem_wait_op(int semid, int semnum) {
  struct sembuf sops = {semid, -1, 0}; // wait on semnum
  semop(semid, &sops, 1);
}
void sem_signal_op(int semid, int semnum) {
  struct sembuf sops = {semid, 1, 0}; // post semnum
  semop(semid, &sops, 1);
}
int main() {
  int shmid, semid;
  key_t key;
  char *shm;

  key = ftok(".", 's');

  shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }
  shm = shmat(shmid, NULL, 0);
  if (shm == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  semid = semget(key, 2, 0666 | IPC_CREAT);
  if (semid == -1) {
    perror("semget");
    exit(1);
  }
  printf("Server started...\n");

  while (1) {
    sem_wait_op(semid, 0);
    printf("SERVER: ");
    fgets(shm, SHM_SIZE, stdin);

    sem_signal_op(semid, 1);
    printf("CLIENT: ");
    fputs(shm, stdout);
  }
}
