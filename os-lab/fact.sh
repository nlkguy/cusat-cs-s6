#!/bin/bash


echo "number:"
read number

if [[ $num =~ ^[0-9]+$ && $num -gt 0 ]]; then
    fact=1
    for (( i=1; i<=$num; i++ )); do
        fact=$((fact * i))
    done
    echo "fact o $num is $fact"
else
    echo "errrror"
fi

