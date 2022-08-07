#!/bin/sh

echo "Enter 2 numbers >> "
read a b

while [[ true ]]
do
    echo "1.Add\n2.Sub\n3.Mul\n4.Div5.Exit\n"
    read choice

    case $choice in
    1) ((  temp=$a+$b  ))
        echo "Sum >> $temp"
        ;;
    
    2) ((  temp=$a-$b  ))
        echo "Diff >> $temp"
        ;;

    3) (( temp=$a*$b  ))
        echo "Product >> $temp "
        ;;

    4) (( temp=$a/$b  ))
        echo "Quotient >> $temp"
        ;;

    5) exit 2
    esac
done