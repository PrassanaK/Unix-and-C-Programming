#!/bin/bash

read variable1 variable2

if [variable1 -nt variable2]; then
    echo file1 is newer than file2
fi

if [variable2 -nt variable1]; then
    echo file2 is newer than file1
fi
