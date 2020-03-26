#!/bin/bash
contest=$(basename `pwd`)
basename `pwd`
cd $1
g++ -std=c++14 "-I${COMPRO_LIB}" -Wall -Wextra -fuse-ld=gold -fsanitize=undefined "${contest}_${1}.cpp" && oj test
