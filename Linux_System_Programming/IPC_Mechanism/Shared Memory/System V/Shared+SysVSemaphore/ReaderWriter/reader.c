#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

#define SIZE 1024
int main() {
  key_t key;
  char *shm;
  int shmid;
  int semid;

  key = ftok("writer_reader", 65);
  if (key == -1) {
    perror("ftok");
    exit(1);
  }
  shmid = shmget(key, SIZE, 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }
  shm = shmat(shmid, NULL, 0);
  if ((char *)shm == (char *)-1) {
    perror("shmat");
    exit(1);
  }
  semid = semget(key, 1, 0666);
  if (semid == -1) {
    perror("semget");
    exit(1);
  }
  struct sembuf lock = {0, -1, 0};
  struct sembuf unlock = {0, 1, 0};

  semop(semid, &lock, 1);
  printf("Message from shared memory: %s\n", shm);

  semop(semid, &unlock, 1);
  shmdt(shm);
}
