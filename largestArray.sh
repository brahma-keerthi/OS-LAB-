#!/bin/sh

declare -a arr
echo "Enter array size>> "
read num

echo "Enter array elements>> "
for (( i=0; i<num; i++ ))
do
    read arr[i]
done

max=${arr[0]}

for (( i=1; i<num; i++ ))
do
    if [ $max -lt ${arr[$i]} ]
    then 
        max=${arr[$i]}
    fi
done

echo "Maximum element is $max"