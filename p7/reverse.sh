#!/bin/bash

o=
for num in "@$"; do 
    o="$num $o"
done
echo "$o"
