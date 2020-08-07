#!/bin/bash 

read -p "enter a: " a 
if [ $a -eq 2 ]; then 
	echo "equal"
elif [ $a -gt 2 ]; then 
	echo "greater than"
else 
	echo "less than"
fi
