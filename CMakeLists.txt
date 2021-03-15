# CMakeList.txt: projekt CMake dla elementu hash_table, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (hash_table "hash_table.cpp" "hash_table.h" "pair.h")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
