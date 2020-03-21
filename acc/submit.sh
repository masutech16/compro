#!/bin/bash
contest=$(basename `pwd`)
cd $1
oj-bundle "${contest}_$1.cpp" > submit.cpp
oj s "https://atcoder.jp/contests/${contest}/tasks/${contest}_$1" submit.cpp --no-open -y
