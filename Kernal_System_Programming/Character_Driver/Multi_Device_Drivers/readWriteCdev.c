#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd0, fd1, fd2;
    char buf[100];
    char input[100];

    /* Open all devices */
    fd0 = open("/dev/mydev0", O_RDWR);
    fd1 = open("/dev/mydev1", O_RDWR);
    fd2 = open("/dev/mydev2", O_RDWR);

    if (fd0 < 0 || fd1 < 0 || fd2 < 0) {
        perror("open");
        return -1;
    }

    /* -------- DEVICE 0 -------- */
    printf("Enter message for Device 0: ");
    fgets(input, sizeof(input), stdin);
    write(fd0, input, strlen(input));

    /* -------- DEVICE 1 -------- */
    printf("Enter message for Device 1: ");
    fgets(input, sizeof(input), stdin);
    write(fd1, input, strlen(input));

    /* -------- DEVICE 2 -------- */
    printf("Enter message for Device 2: ");
    fgets(input, sizeof(input), stdin);
    write(fd2, input, strlen(input));

    /* Read from each device */
    memset(buf, 0, sizeof(buf));
    read(fd0, buf, sizeof(buf)-1);
    printf("Read from dev0: %s\n", buf);

    memset(buf, 0, sizeof(buf));
    read(fd1, buf, sizeof(buf)-1);
    printf("Read from dev1: %s\n", buf);

    memset(buf, 0, sizeof(buf));
    read(fd2, buf, sizeof(buf)-1);
    printf("Read from dev2: %s\n", buf);

    close(fd0);
    close(fd1);
    close(fd2);

    return 0;
}
