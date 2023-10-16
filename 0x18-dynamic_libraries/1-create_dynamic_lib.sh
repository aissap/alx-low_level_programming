#!/bin/basih
gcc -fPIC *.c
gcc -shared -o liballa.so *.o
