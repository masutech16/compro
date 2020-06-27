#!/bin/bash

# this depends on online-judge-tools
# Usage: ./gen.sh {URL} {FOLDER_NAME}
# URL: Problem url you want to solve
# FOLDER_NAME: Name that will be created

oj login $1
mkdir $2
cd $2 && oj download $1 && touch tmp.cpp
../watch.sh
