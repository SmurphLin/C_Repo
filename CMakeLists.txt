cmake_minimum_required(VERSION 3.9)
project(ETL_C C)

set(CMAKE_C_STANDARD 11)

add_executable(ETL_C main.c ETL_C.h JSON_ETL.h ETL_TEST_C.h)