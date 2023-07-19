#!/bin/sh

echo "Enter a number>>"
read num

numrev=$(rev <<< "$num")

if [ $numrev == $num ]
then
    echo "Palindrome"
else
    echo "Not palindrome"
fi