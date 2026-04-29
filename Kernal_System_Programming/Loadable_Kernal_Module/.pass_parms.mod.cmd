savedcmd_pass_parms.mod := printf '%s\n'   pass_parms.o | awk '!x[$$0]++ { print("./"$$0) }' > pass_parms.mod
