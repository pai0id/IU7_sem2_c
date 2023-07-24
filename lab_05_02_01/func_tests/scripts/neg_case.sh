#!/bin/bash

in_file=$1
prog="./app.exe"

read -r input < "$in_file"

rm tmp -f
touch tmp

if ! $prog "$input" > tmp ; then
    exit 0
else
    exit 1
fi
