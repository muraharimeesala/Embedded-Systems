#!/bin/bash

gcc pointers.c -o pointers
gcc reverse_traversal.c -o reverse_traversal
gcc two_pointers.c -o two_pointers
gcc WithoutExtraVar.c  -o WithoutExtraVar
gcc XOR.c -o XOR

echo "Running Pointers Approach"
./pointers
echo " "
echo " "
echo "Running Reverse Traversal Approach"
./reverse_traversal
echo " "
echo " "
echo "Running Two Pointers Approach"
./two_pointers
echo " "
echo " "
echo "Running Without Extra Variable Approach"
./WithoutExtraVar
echo " "
echo " "
echo "Running XOR Approach"
./XOR
echo " "
