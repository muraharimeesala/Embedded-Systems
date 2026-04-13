// Create a program to remove an existing message queue using the msgctl system call. Ensure that the program prompts the user for confirmation before deleting the message queue.

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int msgid, choice;
    key_t key;
    struct msqid_ds buf;
    char message[100];

    printf("Enter the message queue key: ");
    scanf("%d", &key);

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("msgget");
        exit(1);
    }

    printf("Message queue ID: %d\n", msgid);

    printf("Do you want to delete the message queue? (1 for yes, 0 for no): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        if (msgctl(msgid, IPC_RMID, NULL) == -1)
        {
            perror("msgctl");
            exit(1);
        }
        printf("Message queue deleted successfully.\n");
    }
    else
    {
        printf("Message queue not deleted.\n");
    }

    return 0;
}
