#!/bin/bash

gcc Hashing.c -o Hashing
gcc NestedLoop.c -o NestedLoop
gcc SortedMethod.c -o SortedMethod

echo "Running Hashing Approach"
./Hashing
echo " "
echo " "
echo "Running Nested Loop Approach"
./NestedLoop
echo " "
echo " "
echo "Running Sorted Method Approach"
./SortedMethod
echo " "
echo " "
