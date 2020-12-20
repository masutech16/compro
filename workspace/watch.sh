#!/bin/sh

SCRIPT_DIR=$(cd $(dirname $0); pwd)
INTERVAL=1 #監視間隔, 秒で指定
last=`ls -l --full-time $1 | awk '{print $7}'`
while true; do
        sleep $INTERVAL
        current=`ls -l --full-time $1 | awk '{print $7}'`
        if test $last != $current ; then
                echo ""
                echo "updated: $current"
                last=$current
                eval "g++-8 -std=c++17 -I $SCRIPT_DIR/../lib/ -Wall -Wextra -fuse-ld=gold -fsanitize=undefined $1 && oj-bundle -I '$SCRIPT_DIR/../lib/' $1 > submit.cpp && oj t"
        fi
done
