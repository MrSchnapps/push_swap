#!/bin/bash

i=0
ARG=()
max=$1
while ((i<$max))
do
	tester=1
	RAND=$((1 + RANDOM % 3000))
	for j in "${ARG[@]}"; do
		if [[ $j == $RAND ]]
		then
			tester=0
		fi
	done
	if [[ $tester == 1 ]]
	then
		ARG[i]=$RAND
		((i+=1))
	fi
done
echo ${ARG[*]} > values
ARG=$(cat values);
./push_swap.exe $ARG | ./checker.exe $ARG | wc -l
