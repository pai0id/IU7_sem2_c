#!/bin/bash

in_file=$1
out_file=$2
args_file=$3

prog="./app.exe"

read -r args < "$args_file"

IFS=' ' read -r -a args <<< "$args"

if [[ "${args[0]}" == "ft" ]] ; then
    if $prog "${args[@]}" || ./func_tests/scripts/comparator.sh tmp "$out_file" ; then
        exit 0
    else
        exit 1
    fi
elif [[ "${args[0]}" == "sb" ]] ; then
    rm -f bin_in_tmp
    touch bin_in_tmp
    ./convert.exe t2b "$in_file" bin_in_tmp
    if $prog "${args[@]}" > ttmp; then
        rm -f tmp
        touch tmp
        ./convert.exe b2t bin_in_tmp tmp
        if ./func_tests/scripts/comparator.sh tmp "$out_file" || ./func_tests/scripts/comparator.sh ttmp "$out_file" ; then
            exit 0
        else
            exit 1
        fi
    else
        exit 1
    fi
fi
exit 1
