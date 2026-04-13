#!/bin/bash

gcc Loop.c -o Loop 
gcc Memcpy.c -o Memcpy
gcc Pointers.c -o Pointers

echo "Running Loop Approach"
./Loop
echo " "
echo " "
echo "Running Memcpy Approach"
./Memcpy
echo " "
echo " "
echo "Running Pointers Approach"
./Pointers
echo " "

