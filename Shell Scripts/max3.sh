#!/bin/sh

echo "Enter 3 numbers>> "
read num1
read num2
read num3

if [ $num1 -eq $num2 ]
then
	if [ $num2 -eq $num3 ]
	then
	echo "All numbers are equal to $num1"
	fi
	
else
if [ $num1 -gt $num2 ]
then
	if [ $num1 -gt $num3 ]
	then
	echo "Num1 is greater"
	
	else
	echo "Num3 is greater"
	fi

else
	if [ $num2 -gt $num3 ]
	then
	echo "Num2 is greater"

	else
	echo "Num3 is greater"
	fi
fi
fi

echo "Num1 >> $num1"
echo "Num2 >> $num2"
echo "Num3 >> $num3"
