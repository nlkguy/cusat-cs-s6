#!/bin/bash

echo "enter array , space separated:"
read -a arr1

arr2=($(for i in "${arr1[@]}"; do echo "$i"; done | sort -n))
# can aalso use sorting algo

echo "Sorted array:"
echo "${arr2[@]}"

