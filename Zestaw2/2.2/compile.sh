#!/bin/bash
gcc -c Dua_Silnia.c
gcc -c Fib.c
gcc -c Silnia.c
gcc Main_file.c -o Main_file Silnia.o Dua_Silnia.o Fib.o
