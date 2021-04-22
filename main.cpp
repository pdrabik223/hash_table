// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
//
#include <string>
#include <cstdlib>
#include "h_table.h"

unsigned read_console();
// todo 6) repair []
// todo 2) repair get element to not return pointer but instead something else
// todo 3) mahe the thing goble up the input's from console
// todo 4) general debbuging


int main() {


    h_table<int, std::string> tab(10);
    tab.push(3,"a");
    tab.push(13,"b");
    tab.push(23,"c");
    tab.push(33,"d");
    tab.push(4,"e");

    tab.push(1,"f");
    tab.push(9,"g");
    tab.push(19,"h");


    for(int i=0;i<tab.get_size();i++) {
     std::cout<<i<<"\t";
        if (tab.get_element(i) != nullptr)
            std::cout << tab.get_element(i)->first << "\t" << tab.get_element(i)->second << std::endl;
        else   std::cout<<std::endl;
    }

    std::cout<<std::endl;
    tab.pop(23);
    tab.pop(1);
    tab.pop(9);



    for(int i=0;i<tab.get_size();i++) {
        std::cout<<i<<"\t";
        if (tab.get_element(i) != nullptr)
            std::cout << tab.get_element(i)->first << "\t" << tab.get_element(i)->second << std::endl;
        else   std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

