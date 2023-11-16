#!/bin/bash
gcc -c liczby_wymierne.c -fpic
gcc -shared -o liblicz_wym.so -fpic liczby_wymierne.o
gcc -c interpreter_switch.c -o interpreter_switch.o
gcc -o interpreter_switch interpreter_switch.o -lm liblicz_wym.so -L.
LD_LIBRARY_PATH=. ./interpreter_switch