#!/bin/bash

./build_debug_gcov.sh

cd ./func_tests/scripts/ || exit 1
./func_tests.sh
cd ../../

echo
echo "Result:"
echo
gcov main.c
