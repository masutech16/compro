#!/bin/sh

LIB_DIR="/workspaces/compro/lib"
INTERVAL=1 #監視間隔, 秒で指定
last=`ls -l --full-time $1 | awk '{print $7}'`
while true; do
        sleep $INTERVAL
        current=`ls -l --full-time $1 | awk '{print $7}'`
        if test $last != $current ; then
                echo ""
                echo "updated: $current"
                last=$current
                eval "g++-8 -O2 -std=c++17 -I $LIB_DIR -I $LIB_DIR/ac-library -Wall -Wextra -DLOCAL -fuse-ld=gold -fsanitize=undefined $1 && oj-bundle -I '$LIB_DIR' -I '$LIB_DIR/ac-library' $1 > submit.cpp && oj t"
        fi
done
