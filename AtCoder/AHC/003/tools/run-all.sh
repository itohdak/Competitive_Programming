#!/bin/bash

function kill_survived_process () {
    for pid in $(echo `ps aux | grep ./a.out | grep -v grep` | cut -d " " -f 2); do
        kill $pid;
    done
    for pid in $(echo `ps aux | grep ./run-parallel.sh | grep -v grep` | cut -d " " -f 2); do
        kill $pid;
    done
}

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

g++ ../A.cpp

function min () {
    echo $(($1>$2 ? $2 : $1))
}

if [ $SUMMARIZE = 1 ]; then
    echo "store = 0" > score.txt
fi

N_PROC=5
N_FILE_TO_PROCESS=$(((100+N_PROC-1)/N_PROC))
echo $NPROC $N_FILE_TO_PROCESS
if [ $SUMMARIZE = 1 ]; then
    kill_survived_process
    for procno in `seq 0 $((N_PROC-1))`; do
        ./run-parallel.sh -s $((procno*N_FILE_TO_PROCESS)) `min $(((procno+1)*N_FILE_TO_PROCESS-1)) 99` &
    done
elif [ $QUIET = 1 ]; then
    kill_survived_process
    for procno in `seq 0 $((N_PROC-1))`; do
        ./run-parallel.sh -q $((procno*N_FILE_TO_PROCESS)) `min $(((procno+1)*N_FILE_TO_PROCESS-1)) 99` &
    done
else
    for fileno in `seq 0 99`; do
        filename=`printf %04d $fileno`.txt
        cargo run --release --bin tester in/$filename ./a.out > out/$filename
    done
fi

# while [ `cat ./score.txt | wc -l` -lt 101 ]; do
#     sleep 5
# done

# if [ $SUMMARIZE = 1 ]; then
#     ./summarize.sh
# fi
