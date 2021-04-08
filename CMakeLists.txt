# CMakeList.txt: projekt CMake dla elementu hash_table, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required(VERSION 3.17)
project(gol)
set(CMAKE_CXX_STANDARD 14)


# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (hash_table "main.cpp" "h_table.cpp" "h_table.h" "pair.h" "hash_function.h")

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive  -Wl,--no-whole-archive")
