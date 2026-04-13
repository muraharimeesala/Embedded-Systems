#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

void sem_wait_op(int semid, int semnum) {
  struct sembuf op = {semid, -1, 0};
  semop(semid, &op, 1);
}

void sem_post_op(int semid, int semnum) {
  struct sembuf op = {semid, 1, 0};
  semop(semid, &op, 1);
}

int main() {
  int shmid, semid;
  char *shm;
  key_t key;

  key = ftok(".", 's');
  shmid = shmget(key, SHM_SIZE, 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }
  shm = shmat(shmid, NULL, 0);
  if (shm == (char *)-1) {
    perror("shmat");
    exit(1);
  }
  semid = semget(key, 1, 0666);
  if (semid == -1) {
    perror("semget");
    exit(1);
  }
  printf("Client started..\n");

  while (1) {
    sem_wait_op(semid, 1);

    printf("SERVER: %s\n", shm);
    sleep(1);
    printf("CLIENT: %s\n", shm);
    fgets(shm, SHM_SIZE, stdin);

    sem_post_op(semid, 1);
  }
}
