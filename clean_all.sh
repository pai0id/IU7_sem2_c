#!/bin/bash

for i in ./lab_*
do
    cd $i
    ./clean.sh
    cd ..
done
