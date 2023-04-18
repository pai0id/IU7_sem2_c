#!/bin/bash

gcc -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -g3 -Wvla -O0 main.c
gcc -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -g3 -Wvla -O0 calc.c
gcc -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -g3 -Wvla -O0 IO.c

gcc -o app.exe -g3 IO.o calc.o main.o -lm
