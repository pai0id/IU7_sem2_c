#!/bin/bash

clang -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g3 -Wvla -O0 main.c
clang -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g3 -Wvla -O0 calc.c
clang -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g3 -Wvla -O0 IO.c
clang -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g3 -Wvla -O0 codes.c

clang -o app.exe -g3 IO.o calc.o codes.o main.o -lm -fsanitize=undefined
