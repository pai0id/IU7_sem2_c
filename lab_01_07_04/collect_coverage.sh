#!/bin/bash

./func_tests/scripts/func_tests_silent.sh

echo
echo "Result:"
echo
gcov main.c
