#!/bin/sh

echo "Enter string >> "
read str

revstr=$(rev <<< "$str")

if [[ $str == $revstr ]]
then
    echo "Palindrome"
else    
    echo "Not palindrome"
fi