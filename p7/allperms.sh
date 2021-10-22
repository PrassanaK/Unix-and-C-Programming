#!/bin/bash

for file in $(find /home/19097457/Documents/UCP/p7/*); do
    if [-w $file];then
        echo file is writable
    else if [-r $file]
        echo file is readable
    else if [-x $file]
        echo file is executable
    fi
done
