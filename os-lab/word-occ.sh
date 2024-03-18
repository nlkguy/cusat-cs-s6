#!/bin/bash

filename="file.txt"

if [ ! -f "$filename" ]; then
    echo "not file!"
    exit 1
fi

echo "search word:"
read search

count=$(cat "$filename" | grep -c "$search")

echo "0ccurrrences of '$search' in $filename: $count"

