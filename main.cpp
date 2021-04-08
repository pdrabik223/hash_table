// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
//
#include <string>
#include <stdlib.h>
#include "h_table.h"
#include "pair.h"

unsigned read_file(const char *file_path);

unsigned read_console();


int main() {
    int *ptr_to_int ;

    h_table<int, char> tab(10);
    tab.push(my::pair<int, char>(0, 'k'));
    std::cout << "val0 : " << tab[0] << std::endl;
    tab.push(my::pair<int, char>(1, 'p'));
    tab.push(my::pair<int, char>(10, 's'));
    tab.push(my::pair<int, char>(20, 'l'));


    std::cout << "val1 : " << tab[10] << std::endl;
    std::cout << "val2 : " << tab[20] << std::endl;
    // tab.pop(10);
    std::cout << "val2 : " << tab[1] << std::endl;

    system("pause");
    for (int i=0;i<tab.get_size();i++) {
        std::cout <<i<<": "<<tab[i]<<std::endl;
    }


    system("pause");
    return 0;
}

