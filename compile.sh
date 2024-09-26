#!/bin/bash

# Compile the C++ files
g++ main.cpp matrix.cpp matrixui.cpp RowTransform.cpp -o my_program

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Run ./my_program to execute."
else
    echo "Compilation failed."
fi
