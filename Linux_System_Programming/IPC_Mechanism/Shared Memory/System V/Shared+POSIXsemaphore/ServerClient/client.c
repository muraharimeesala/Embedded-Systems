#include <stdio.h>
// #include <stdlib.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
// #include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

typedef struct {
  sem_t sem;
  char buffer[SHM_SIZE];
} shared_data;

int main() {
  int shmid;
  key_t key;
  shared_data *shm;

  key = ftok("shmfile", 1);

  shmid = shmget(key, sizeof(shared_data), 0666);
  shm = (shared_data *)shmat(shmid, NULL, 0);

  printf("Client started...\n");

  while (1) {
    sem_wait(&shm->sem);

    printf("CLIENT received: %s\n", shm->buffer);

    printf("CLIENT: ");
    fgets(shm->buffer, SHM_SIZE, stdin);

    printf("Client sent\n");

    sem_post(&shm->sem);

    sleep(1);
  }
}
