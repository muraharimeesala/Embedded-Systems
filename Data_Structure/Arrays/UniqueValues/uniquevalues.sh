#!/bin/bash

gcc Hashing.c -o Hashing 
gcc NestedLoop.c -o NestedLoop

echo "Running Hashing Approach"
./Hashing
echo " "
echo " "
echo "Running Nested Loop Approach"
./NestedLoop
echo " "
