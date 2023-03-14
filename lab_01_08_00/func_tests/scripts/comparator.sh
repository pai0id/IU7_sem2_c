#!/bin/bash

file1=$1
file2=$2
verb=$3

if [ -z "$file1" ] || [ -z "$file2" ] || [ ! -f "$file1" ] || [ ! -f "$file2"  ]; then
	if [[ $verb == "-v" ]]; then
		echo "Please enter correct file names"
	fi
	exit 2
elif [ ! -r "$file1" ] || [ ! -r "$file2"  ]; then
	if [[ $verb == "-v" ]]; then
		echo "Permission error"
	fi
	exit 3
fi

arr1=""
arr2=""
delimiter="Result: "
weregood=0

while read -r line1; do
        if [ $weregood -eq 1 ]; then
                arr1="$arr1
$line1"
        elif [[ $line1 == *"Result: "* ]]; then
                arr1=${line1#*"$delimiter"}
                while read -r line2; do
                        if [ $weregood -eq 1 ]; then
				arr2="$arr2
$line2"
                        elif [[ $line2 == *"Result: "* ]]; then
                                #arr2=$(grep -Eo "Result: [[:graph:]]*" <<< "$line2")
				arr2=${line2#*"$delimiter"}
				if [[ "$arr1" != "$arr2" ]]; then
                                        if [ "$verb" == "-v" ]; then
                                                echo "files do not match"
                                        fi
                                        exit 1
                                else
                                        arr1=""
                                        arr2=""
                                        weregood=1
                                fi
                        fi
                done < "$file2"
        fi
done < "$file1"

if [[ "$arr1" == "$arr2" ]]; then
        if [ "$verb" == "-v" ]; then
                echo "files match"
        fi
        exit 0
else
        if [ "$verb" == "-v" ]; then
                echo "files do not match"
        fi
        exit 1
fi

