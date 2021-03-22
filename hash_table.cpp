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
    tab.push(my::pair<int, char>(10, 's'));
    tab.push(my::pair<int, char>(20, 'l'));


    std::cout << "val : " << tab[0] << std::endl;
    std::cout << "val2 : " << tab[20] << std::endl;
    for (auto i:tab) {
        std::cout << i.first<<"\t"<<i.second<<std::endl;
    }


    system("pause");
    return 0;
}
