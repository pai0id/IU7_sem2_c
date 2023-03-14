#!/bin/bash

gcc -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion --coverage -g3 -Wvla -O0 main.c
gcc -o app.exe -g3 --coverage main.o -lm
