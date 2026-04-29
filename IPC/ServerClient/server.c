#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

void wait_sem(int sem_id, int semnum) {
  struct sembuf sb = {semnum, -1, 0};
  semop(sem_id, &sb, 1);
}

void signal_sem(int sem_id, int semnum) {
  struct sembuf sb = {semnum, 1, 0};
  semop(sem_id, &sb, 1);
}
int main() {
  int shmid;
  int sem_id;
  char *shm;
  key_t key;

  key = ftok("file", 1);
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }
  shm = shmat(shmid, NULL, 0);
  if (shm == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  sem_id = semget(key, 2, 0666 | IPC_CREAT);
  if (sem_id == -1) {
    perror("semget");
    exit(1);
  }
  union semun {
    int val;
  };

  union semun arg;
  arg.val = 0;

  semctl(sem_id, 0, SETVAL, arg); // sem[0]
  semctl(sem_id, 1, SETVAL, arg); // sem[1]
  printf("Server started...\n");
  while (1) {
    wait_sem(sem_id, 0);
    printf("CLIENT: %s\n", shm);

    printf("SERVER: ");
    fgets(shm, SHM_SIZE, stdin);

    signal_sem(sem_id, 1);
  }

  shmdt(shm);
  shmctl(shmid, IPC_RMID, NULL);
  semctl(sem_id, 0, IPC_RMID);
}
