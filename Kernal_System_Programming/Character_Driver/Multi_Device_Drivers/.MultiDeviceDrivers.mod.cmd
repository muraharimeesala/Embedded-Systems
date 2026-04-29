savedcmd_MultiDeviceDrivers.mod := printf '%s\n'   MultiDeviceDrivers.o | awk '!x[$$0]++ { print("./"$$0) }' > MultiDeviceDrivers.mod
