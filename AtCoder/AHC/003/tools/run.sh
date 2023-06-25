#!/bin/bash

EPOCH=1
QUIET=0

args=`getopt :n:q "$@"`
set -- $args
for OPT in "$@"
do
    case $OPT in
        -n) EPOCH=$2
            shift 2
            ;;
        -q) QUIET=1
            shift 1
            ;;
    esac
done

g++ ../A.cpp
for i in `seq 0 $((EPOCH-1))`; do
    if [ $QUIET = 0 ]; then
        cargo run --release --bin tester $2 ./a.out > out.txt
    else
        cargo run -q --release --bin tester $2 ./a.out > out.txt
    fi
done
