#!/bin/bash

if [-w $1];then
    echo file is writable
else if [-r $1]
    echo file is readable
else if [-x $1]
    echo file is executable
fi
