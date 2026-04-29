// Create a program that monitors and displays the usage statistics of shared memory segments, such as the amount of memory used and the number of attached processes. 

// Usage: ./usageStatisticsOfShm

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
    // Open the shared memory segment
    key_t key;
    printf("Enter key: ");
    scanf("%d", &key);
    int shmid = shmget(key, 0, 0);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Get the shared memory segment statistics
    struct shmid_ds shmid_ds;
    if (shmctl(shmid, IPC_STAT, &shmid_ds) == -1) {
        perror("shmctl");
        return 1;
    }

    // Display the usage statistics
    printf("Memory used: %ld bytes\n", shmid_ds.shm_segsz);
    printf("Number of attached processes: %ld\n", shmid_ds.shm_nattch);

    return 0;
}
