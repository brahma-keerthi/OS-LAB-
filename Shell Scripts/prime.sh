#!/bin/sh

echo "Enter range >> "
read a b

echo "Prime number in range $a to $b >>"

for ((  i=a; i<=b; ++i  ))
do
    flag=1
    for (( j=2; j<=$i/2; ++j  ))
    do  
        ((  temp=$i%$j  ))
        if [ $temp -eq 0 ]
        then
            flag=0
            break;
        fi
    done

    if [ $flag -eq 1 ]
    then
        echo -ne "$i"
    fi
done  