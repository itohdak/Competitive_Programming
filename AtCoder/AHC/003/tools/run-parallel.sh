#!/bin/bash

QUIET=0
SUMMARIZE=0

args=`getopt :qs "$@"`
set -- $args
for OPT in "$@"
do
    case $OPT in
        -q) QUIET=1
            shift 1
            ;;
        -s) SUMMARIZE=1
            shift 1
            ;;
    esac
done

BEGIN=$2
END=$3

for fileno in `seq $BEGIN $END`; do
    filename=`printf %04d $fileno`.txt
    if [ $SUMMARIZE = 1 ]; then
        cargo run -q --release --bin tester in/$filename ./a.out > out/$filename 2>> score.txt
    elif [ $QUIET = 1 ]; then
        cargo run -q --release --bin tester in/$filename ./a.out > out/$filename
    else
        cargo run --release --bin tester in/$filename ./a.out > out/$filename
    fi
done
