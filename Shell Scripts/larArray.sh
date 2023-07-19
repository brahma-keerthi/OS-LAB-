#!/bin/sh

declare -a arr

echo "Enter num of elements >> "
read n

echo "Enter elements >> "
for (( i=0; i<n; ++i ))
do
    read arr[i]
done

max=${arr[0]}

for (( i=1; i<n; ++i ))
do
    if [ $max -lt ${arr[$i]} ]
    then
        max=${arr[$i]}
    fi
done

echo "max >> $max"