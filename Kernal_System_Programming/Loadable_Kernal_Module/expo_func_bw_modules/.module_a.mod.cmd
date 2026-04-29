savedcmd_module_a.mod := printf '%s\n'   module_a.o | awk '!x[$$0]++ { print("./"$$0) }' > module_a.mod
