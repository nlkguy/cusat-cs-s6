#!/bin/bash

declare -a pid at bt wt tat ct

calctimes() {
    ct=0
    for ((i = 0; i < $n; i++)); do
        wt[$i]=$ct
        tat[$i]=$((ct + bt[i] - at[i]))
        ct=$((tat[i] + at[i]))
    done
}

disptimes() {
    echo "PID |arrival|burst|wait|turnaround|complet"
    for ((i = 0; i < $n; i++)); do
        echo "${pid[i]} | ${at[i]} | ${bt[i]} | ${wt[i]} | ${tat[i]} | ${at[i]} + ${tat[i]} = $((at[i] + tat[i]))"
    done
}

echo -n "noof processes: "
read n

for ((i = 0; i < $n; i++)); do
    echo -n "PID for P$(($i + 1)): "
    read pid[i]
    echo -n "arrival for P$(($i + 1)): "
    read at[i]
    echo -n "burst for P$(($i + 1)): "
    read bt[i]
done

calctimes
disptimes

