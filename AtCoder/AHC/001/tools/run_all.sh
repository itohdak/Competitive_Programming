#!/bin/bash

echo compiling...
g++atcoder ~/Competitive_Programming/AtCoder/AHC/001/A.cpp
for filename in `ls in`; do
    echo processing $filename;
    time cat ./in/$filename | ./a.out > /tmp/out.txt 2> /tmp/error.txt;
    cargo run --release --bin vis ./in/$filename /tmp/out.txt;
    gnome-open vis.html;
    echo finished $filename;
done
