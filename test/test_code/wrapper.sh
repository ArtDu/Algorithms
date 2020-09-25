#!/usr/bin/env bash

if ! g++ main.cpp -o correct -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG; then
    echo "ERROR: Failed to compile file."
    exit 1
fi

if ! g++ ../main.cpp -o main -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG; then
    echo "ERROR: Failed to compile file."
    exit 1
fi


mkdir -p tests
#if ! python3 test_gen.py ; then
#    echo "ERROR: Failed to python generate tests."
#    exit 1
#fi

for test_file in `ls tests/*.t`; do
    answer_file="${test_file%.*}"
    echo "Execute ${test_file}"
    if !  ./correct < ${test_file} > "${answer_file}.ans" ; then
        echo "ERROR"
        continue
    fi
     if ! ./main < ${test_file} > "${answer_file}.my" ; then
         echo "ERROR"
         continue
     fi

    if ! diff "${answer_file}.ans"  "${answer_file}.my"  ; then
        echo "Failed"
    else
        echo "OK"
    fi 
done  
