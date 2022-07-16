#!/bin/sh
echo "Enter a number>> "
read num

temp=$num
reverse=0

while [ $temp -ne 0 ]
do
    dig=$(($temp%10))
    reverse=$(($reverse*10 + $dig))
    temp=$(($temp/10))
done

if [ $num -eq $reverse ]
then
    echo "$num is Palindrome"
else
    echo "$num is not Palindrome"
fi