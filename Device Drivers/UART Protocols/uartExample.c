#include <stdio.h>
#include <fcntl.h>      // for open(), O_RDWR, etc.
#include <termios.h>    // for termios structure and serial config
#include <unistd.h>     // for write(), close()

int main() {
    int fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY);
    struct termios tty;

    tcgetattr(fd, &tty);
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    tty.c_cflag = CS8 | CLOCAL | CREAD;

    tcsetattr(fd, TCSANOW, &tty);

    write(fd, "Hello UART", 10);

    close(fd);
    return 0;
}

