#!/bin/bash

PURPLE=$'\e[1;35m'
NC=$'\e[1;0m'

for i in ./lab_*
do
    echo
    echo "$PURPLE$i$NC"
    echo
    cd $i
    ./build_release.sh
    cd "./func_tests/scripts"
    ./func_tests.sh -v
    cd ../../..
done
