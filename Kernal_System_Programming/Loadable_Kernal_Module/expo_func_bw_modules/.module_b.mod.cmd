savedcmd_module_b.mod := printf '%s\n'   module_b.o | awk '!x[$$0]++ { print("./"$$0) }' > module_b.mod
