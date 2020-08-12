#!/bin/bash

alias oj-submit='oj s -y --open'
alias g++='g++-8 -std=c++17 -I /workspaces/compro/lib -Wall -Wextra -fuse-ld=gold -fsanitize=undefined'
alias oj-bundle='oj-bundle -I /workspaces/compro/lib'
alias oj-prepare='oj-prepare --config-file "/workspaces/compro/oj/oj-prepare.config.toml"'
oj -c /workspaces/compro/oj/oj-cookie.jar
