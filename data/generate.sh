#!/bin/bash

# Define the starting and ending set numbers
start=46
end=50

# Loop through the set numbers
for ((i=$start; i<=$end; i++))
do
    ./scramble && ./rm_trailing.sh output.txt && mv output.txt "set_${i}.txt" && notify-send "set_${i} done"
    # Check if the last command was successful
    if [ $? -ne 0 ]; then
        echo "An error occurred during the execution of set_${i}."
        exit 1
    fi
done

echo "All sets completed successfully."
notify-send "all done"
