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
  int shmfd;
  char *shm;
  shmfd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
  if (shmfd == -1) {
    perror("shm_open");
    exit(1);
  }
  ftruncate(shmfd, 1024);
  shm = mmap(0, 1024, PROT_WRITE, MAP_SHARED, shmfd, 0);
  if ((char *)shm == (char *)-1) {
    perror("mmap");
    exit(1);
  }
  key_t key = ftok("semfile", 65);
  if (key == -1) {
    perror("ftok");
    exit(1);
  }

  int semid = semget(key, 1, IPC_CREAT | 0666);
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
}
