// Write a program writer and reader processes using shared memory and
// semaphores.

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

#define SIZE 1024
int main() {
  key_t key;
  int shmid;
  char *shm;
  int semid;

  key = ftok("writer_reader", 65);
  if (key == -1) {
    perror("ftok");
    exit(1);
  }
  printf("Generated Key: %d\n", key);

  shmid = shmget(key, SIZE, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }
  shm = shmat(shmid, NULL, 0);
  if (shm == (char *)-1) {
    perror("shmat");
    exit(1);
  };
  semid = semget(key, 1, 0666 | IPC_CREAT);
  if (semid == -1) {
    perror("semid");
    exit(1);
  }
  semctl(semid, 0, SETVAL, 1);
  struct sembuf lock = {0, -1, 0};
  struct sembuf unlock = {0, 1, 0};

  semop(semid, &lock, 1);
  printf("Enter Message: ");
  fgets(shm, SIZE, stdin);

  printf("Message written to shared memory\n");

  semop(semid, &unlock, 1);
  shmdt(shm);
}
