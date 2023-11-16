#!/bin/bash
gcc -c liczby_wymierne.c -fpic
gcc -shared -o liblicz_wym.so -fpic liczby_wymierne.o
gcc -c main.c -o main.o
gcc -o main main.o -lm liblicz_wym.so -L.
LD_LIBRARY_PATH=. ./main
