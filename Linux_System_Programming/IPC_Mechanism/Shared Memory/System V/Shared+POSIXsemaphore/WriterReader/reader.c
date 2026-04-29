#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

#define SEM_NAME "/semfile"
#define SIZE 1024

int main() {
  key_t key;
  char *shm;
  int shmid;

  key = ftok("myshared", 65);
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
  sem_t *sem = sem_open(SEM_NAME, 0);
  if ((char *)sem == (char *)-1) {
    perror("sem_open");
    exit(1);
  }

  sem_wait(sem);

  printf("Message received from shared memory: %s\n", shm);

  sem_post(sem);
}
