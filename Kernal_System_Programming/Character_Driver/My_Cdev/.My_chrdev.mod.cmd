savedcmd_My_chrdev.mod := printf '%s\n'   My_chrdev.o | awk '!x[$$0]++ { print("./"$$0) }' > My_chrdev.mod
