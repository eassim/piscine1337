#!/bin/bash

BASE1="'\"?!"
BASE2="mrdoc"
BASE3="gtaio luSnemf"

to_decimal() {
  nbr=$1
  base=$2
  base_len=${#base}
  dec=0
  i=0
  while [ $i -lt ${#nbr} ]; do
    c="${nbr:$i:1}"
    # find index of c in base (0-based)
    pos=$(expr index "$base" "$c")
    if [ $pos -eq 0 ]; then
      echo "0"
      return
    fi
    val=$((pos - 1))
    dec=$((dec * base_len + val))
    i=$((i + 1))
  done
  echo $dec
}

from_decimal() {
  dec=$1
  base=$2
  base_len=${#base}
  if [ "$dec" -eq 0 ]; then
    echo "${base:0:1}"
    return
  fi
  res=""
  while [ $dec -gt 0 ]; do
    rem=$((dec % base_len))
    dec=$((dec / base_len))
    digit="${base:$rem:1}"
    res="$digit$res"
  done
  echo "$res"
}

# Convert inputs to decimal
num1=$(to_decimal "$FT_NBR1" "$BASE1")
num2=$(to_decimal "$FT_NBR2" "$BASE2")

# Add numbers
sum=$((num1 + num2))

# Convert sum to target base
result=$(from_decimal $sum "$BASE3")

echo "$result"