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
  char *shm;
  int shm_id;
  int sem_id;
  key_t key;

  key = ftok("file", '1');

  if ((shm_id = shmget(key, SHM_SIZE, 0666)) == -1) {
    perror("shmget");
    exit(1);
  }
  if ((shm = shmat(shm_id, NULL, 0)) == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  sem_id = semget(key, 2, 0666);
  if (sem_id == -1) {
    perror("semget");
    exit(1);
  }
  printf("Client started...\n");

  while (1) {
    printf("CLIENT: ");
    fgets(shm, SHM_SIZE, stdin);

    signal_sem(sem_id, 0);

    wait_sem(sem_id, 1);
    printf("SERVER: %s\n", shm);
  }
}
