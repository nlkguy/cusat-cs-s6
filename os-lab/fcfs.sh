#!/bin/bash

declare -a processes=("P1 0 5" "P3 1 10" "P2 2 15" "P4 3 20" "P5 4 25")

# Sort the processes array based on arrival time (index 1)
IFS=$'\n' processes=($(sort -n -k2 <<<"${processes[*]}"))
unset IFS

echo "FCFS Scheduling:"
for process in "${processes[@]}"; do
    details=($process)
    pid=${details[0]}
    arrival=${details[1]}
    burst=${details[2]}

    completion=$((arrival + burst))
    turnaround=$((completion - arrival))
    waiting=$((turnaround - burst))

    echo "PID: $pid , Arr: $arrival s , Burst: $burst s , Comp: $completion s , Turn: $turnaround s , Wait: $waiting s"
    echo "-------------------------------------------------"
done

