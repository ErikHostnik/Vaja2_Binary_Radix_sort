#!/bin/bash

g++ src/radix_sort.cpp -o radix_sort -std=c++11

echo "5 3 8 1 2" > test_input.txt
./radix_sort 0 test_input.txt
if [ "$(cat out.txt)" != "1 2 3 5 8 " ]; then
    echo "Test 1 failed"
    exit 1
fi

echo "" > test_input.txt
./radix_sort 0 test_input.txt
if [ -s out.txt ]; then
    echo "Test 2 failed"
    exit 1
fi

echo "1000000 999999 1" > test_input.txt
./radix_sort 0 test_input.txt
if [ "$(cat out.txt)" != "1 999999 1000000 " ]; then
    echo "Test 3 failed"
    exit 1
fi

echo "All tests passed"
exit 0