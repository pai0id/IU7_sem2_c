#!/bin/bash

gcc -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -g3 -Wvla -O0 main.c
gcc -o app.exe -g3 main.o -lm
