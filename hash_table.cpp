// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
//
#include <string>
#include <stdlib.h>
#include "hash_table.h"
#include "pair.h"

unsigned read_file(const char *file_path);

unsigned read_console();





int main() {
    std::cout << "Hello CMake." << std::endl;
    h_table<int, char> tab(10);
    tab.push(my::pair<int, char>(0, 'k'));
    std::cout << "val : " << tab[0] << std::endl;

    tab.push(10, 's');

    std::cout << "val2 : " << tab[10] << std::endl;


    return 0;
}
