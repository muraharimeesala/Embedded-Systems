savedcmd_charDriver.mod := printf '%s\n'   charDriver.o | awk '!x[$$0]++ { print("./"$$0) }' > charDriver.mod
