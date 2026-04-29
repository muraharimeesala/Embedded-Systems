savedcmd_pass_args.mod := printf '%s\n'   pass_args.o | awk '!x[$$0]++ { print("./"$$0) }' > pass_args.mod
