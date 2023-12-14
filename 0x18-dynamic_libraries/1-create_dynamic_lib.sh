#!/bin/bash
gcc -FPIC -c *.c
gcc -shared *.c -o liball.so
