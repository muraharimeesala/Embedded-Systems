#!/bin/bash

gcc Dyanamic.c -o Dyanamic
gcc Function.c -o Function
gcc Loop.c -o Loop
gcc Pointer.c -o Pointer
gcc Recursive.c -o Recursive

echo "Recursive Dyanamic Approach"
./Dyanamic
echo " "
echo " "
echo "Function Function Approach"
./Function
echo " "
echo " "
echo "Loop Function Approach"
./Loop
echo " "
echo " "
echo "Pointer Function Approach"
./Pointer
echo " "
echo " "
echo "Recursive Function Approach"
./Recursive
echo " "
