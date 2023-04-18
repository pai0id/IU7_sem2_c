#!/bin/bash

in_file=$1
out_file=$2
prog="./app.exe"

rm tmp -f
touch tmp

code=$($prog < "$in_file" > tmp)

if [ "$code" == "100" ]; then
    if ./func_tests/scripts/comparator.sh tmp "$out_file"; then
        exit 0
    else
        exit 1
    fi
else
    if $code; then
        exit 0
    else
        exit 1
    fi
fi
