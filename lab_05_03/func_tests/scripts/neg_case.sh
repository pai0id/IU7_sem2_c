#!/bin/bash

in_file=$1
args_file=$2

prog="./app.exe"

rm -f bin_in_tmp
touch bin_in_tmp
./convert.exe t2b "$in_file" bin_in_tmp

read -r args < "$args_file"

IFS=' ' read -r -a args <<< "$args"

if ! $prog "${args[@]}" > tmp ; then
    exit 0
else
    exit 1
fi
