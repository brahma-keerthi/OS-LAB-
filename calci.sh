#!/bin/sh

echo "Enter 2 numbers>> "
read a 
read b
choice=0

while [ $choice -lt 6 ]
do
    echo "1->Addition\n2->Subtraction\n3->Multiplication\n4->Division\n5->Exit"

    read choice

    case $choice in
    1) 
        sum=$(($a + $b))
        echo "Sum = $sum"
        ;;

    2)
        diff=$(($a- $b))
        echo "Diff = $diff"
        ;;

    3)
        pro=$(( $a*$b ))
        echo "Pro = $pro"
        ;;

    4)
        quo=$(($a/$b))
        echo "Quo = $quo"
        ;;
    esac
done