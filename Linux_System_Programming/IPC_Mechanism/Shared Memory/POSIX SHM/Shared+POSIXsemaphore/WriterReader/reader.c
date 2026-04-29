#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHM_NAME "/myshared"
#define SEM_NAME "/semfile"

#define SIZE 1024

int main() {
  int shmfd;
  char *shm;

  shmfd = shm_open(SHM_NAME, O_RDONLY, 0666);
  if (shmfd == -1) {
    perror("shm_open");
    exit(1);
  }
  ftruncate(shmfd, SIZE);

  shm = mmap(0, SIZE, PROT_READ, MAP_SHARED, shmfd, 0);
  if ((char *)shm == (char *)-1) {
    perror("mmap");
    exit(1);
  }

  sem_t *sem = sem_open(SEM_NAME, 0666);
  if ((char *)sem == (char *)-1) {
    perror("sem_open");
    exit(1);
  }
  sem_wait(sem);
  printf("Message received from shared memory: %s\n", shm);

  sem_post(sem);
}
