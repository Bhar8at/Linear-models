#!/bin/bash

# Compile the main program along with matrix functions
g++ main.cpp external/linear-algebra-framework/matrix.cpp \
    external/linear-algebra-framework/matrixui.cpp \
    external/linear-algebra-framework/RowTransform.cpp \
    -Iexternal/linear-algebra-framework \
    -o my_program

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Run ./my_program to execute."
else
    echo "Compilation failed."
fi
