obj-m += pass_parms.o   # search for pass_parms.c
CC := x86_64-linux-gnu-gcc-13

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
