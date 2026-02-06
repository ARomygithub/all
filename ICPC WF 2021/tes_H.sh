#!/bin/bash
pref="./icpc2021data/H-prehistoricprograms/secret-more"
for((i=12;i<=50;i++)); do
    DIFF=$(diff "$pref$i.ans" "impossible.txt")
    if [ "$DIFF" == "" ]
    then
        continue
    fi
    echo $i
    ./H.exe < "$pref$i.in" > ans.txt
    DIFF=$(diff "ans.txt" "impossible.txt")
    if [ "$DIFF" == "" ]
    then
        break
    fi
done