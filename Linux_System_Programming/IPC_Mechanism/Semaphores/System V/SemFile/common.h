#ifndef COMMON_H
#define COMMON_H
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#define KEY_FILE "file"
#define KEY_ID   65
void wait_semaphore(int semid);
void signal_semaphore(int semid);
#endif

