#!/bin/sh

echo "Enter number upto which fibonacci has to be calculated>> "
read num

a=0
b=1

echo "$a,  "
if [ $num -gt 1 ]
then
    echo "$b,  "
fi

for(( i=2;i<$num;i++ ))
do
    c=$(($a+$b))
    echo "$c,  "
    a=$b
    b=$c
done