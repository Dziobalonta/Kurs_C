#!/bin/bash
gcc -c liczby_wymierne.c -fpic
gcc -shared -o liblicz_wym.so -fpic liczby_wymierne.o
gcc -c interpreter_if.c -o interpreter_if.o
gcc -o interpreter_if interpreter_if.o -lm liblicz_wym.so -L.
LD_LIBRARY_PATH=. ./interpreter_if