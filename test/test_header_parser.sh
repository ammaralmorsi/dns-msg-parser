#!/bin/bash
echo
echo
echo Compiling source code for testing...
make;
echo Compiling completed.
echo 
echo
echo **********************Query*****************************
./test_header_parser < query_example;
echo
echo
echo *******************Response****************************
./test_header_parser < response_example;
echo
