#!/bin/sh
INTERVAL=1 #監視間隔, 秒で指定
last=`ls -l --full-time tmp.cpp | awk '{print $7}'`
while true; do
        sleep $INTERVAL
        current=`ls -l --full-time tmp.cpp | awk '{print $7}'`
        if test $last != $current ; then
                echo ""
                echo "updated: $current"
                last=$current
                eval "g++-9 -std=c++17 -I ../../lib/ -Wall -Wextra -fuse-ld=gold -fsanitize=undefined tmp.cpp && oj-bundle -I '../../lib/' tmp.cpp > submit.cpp"
        fi
done
