#!/bin/bash
contest=$(basename `pwd`)
basename `pwd`
cd $1
g++-8 -std=c++17 -I ../../../lib -Wall -Wextra -fuse-ld=gold -fsanitize=undefined "${contest}_${1}.cpp" && oj test
