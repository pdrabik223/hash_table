# CMakeList.txt: projekt CMake dla elementu hash_table, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required(VERSION 3.17)
project(hash_table)
set(CMAKE_CXX_STANDARD 14)


# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (hash_table
        main.cpp
        h_table.h
        pair.h
        hash_function.h)

