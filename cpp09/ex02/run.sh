#!/bin/bash

# Create an array of numbers from 1 to 21
numbers=( $(seq 1 21) )

# Shuffle and output the numbers
./PmergeMe $(echo "${numbers[@]}" | tr ' ' '\n' | shuf | tr '\n' ' ')
