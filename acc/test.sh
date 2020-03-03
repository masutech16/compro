#!/bin/bash

basename `pwd`
cd $1
g++ template.cpp && oj test
