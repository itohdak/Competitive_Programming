#!/bin/bash

sum=0
cat score.txt | while read line
do
  score=`echo $line | tr -d " " | cut -d "=" -f 2`
  sum=$((sum+score));
  echo $sum
done
