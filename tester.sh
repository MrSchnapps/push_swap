#!/bin/bash

num=$1
bash generate_random.sh $num;
ARG=$(cat values);
./push_swap.exe $ARG | ./checker.exe $ARG | wc -l