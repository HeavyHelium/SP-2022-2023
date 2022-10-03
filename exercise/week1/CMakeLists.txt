cmake_minimum_required(VERSION 3.23)
project(week1 C)

set(CMAKE_C_STANDARD 17)

add_executable(cp cp.c)
add_executable(cat cat.c)
add_executable(catfile catfile.c)
add_executable(tee tee.c)
add_executable(wc wc.c)
add_executable(head head.c)
add_executable(cut cut.c)
