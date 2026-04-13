#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHM_NAME "/writer_reader"
#define SIZE 1024

int main() {

  key_t key;
  int shmfd, semid;
  char *shm;

  shmfd = shm_open(SHM_NAME, O_RDONLY, 0666);
  if (shmfd == -1) {
    perror("shm_open");
    exit(1);
  }
  // ftruncate(shmid, SIZE);
  shm = mmap(0, SIZE, PROT_READ, MAP_SHARED, shmfd, 0);
  if ((char *)shm == (char *)-1) {
    perror("mmap");
    exit(1);
  }

  key = ftok("semfile", 65);
  if (key == -1) {
    perror("ftok");
    exit(1);
  }

  semid = semget(key, 1, 0666);
  if (semid == -1) {
    perror("semget");
    exit(1);
  }

  semctl(semid, 0, SETVAL, 1);

  struct sembuf lock = {0, -1, 0};
  struct sembuf unlock = {0, 1, 0};

  semop(semid, &lock, 1);
  printf("Message from shared memory: %s\n", shm);
  semop(semid, &unlock, 1);
}
