#!/bin/bash

prog=$1

if [ $# -ge 2 ]; then testf=$3; else testf="test$prog"; fi

g++ $prog.cc -std=c++14 -o $prog

cat $testf | ./$prog

