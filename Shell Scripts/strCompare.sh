#!/bin/sh

echo "Enter str1>> "
read str1
echo "Enter str2>> "
read str2

if [ $str1 == $str2 ]
then
	echo "Str1 and Str2 are equal"

else
if [ $str1 \> $str2 ]
then
	echo "Str1 is greater than Str2"

else
	echo "Str2 is greater than Str1"
fi
fi

echo "Str1 >> $str1"
echo "Str2 >> $str2"
