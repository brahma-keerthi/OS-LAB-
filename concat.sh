#!/bin/sh

echo "Enter string1>> "
read str1
echo "Enter string2>> "
read str2

echo "Str1 >> $str1"
echo "Str2 >> $str2"

str1+=$str2  
# str1 = str1 + str2

echo "After concatenation>> $str1"
