// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
//
#include <string>
#include <stdlib.h>
#include "h_table.h"

unsigned read_console();
// todo 6)repair []
// todo 2) repair get element to not return pointer but instead something else
// todo 3) mahe the thing goble up the input's from console
// todo 4) general debbuging


int main() {


    h_table<int, std::string> tab(10);
    tab.push(3,"fuck");
    tab.push(13,"you");
    tab.push(23,"cunt");
    tab.push(33,"know");
    tab.push(4,"your allays ");
    tab.push(1,"(.).)======D");
    tab.push(9,":)");
    tab.push(19,":)))");


    for(int i=0;i<tab.get_size();i++) {
     std::cout<<i<<"\t";
        if (tab.get_element(i) != nullptr)
            std::cout << tab.get_element(i)->first << "\t" << tab.get_element(i)->second << std::endl;
        else   std::cout<<std::endl;
    }

    std::cout<<std::endl;
    tab.pop(23);



    for(int i=0;i<tab.get_size();i++) {
        std::cout<<i<<"\t";
        if (tab.get_element(i) != nullptr)
            std::cout << tab.get_element(i)->first << "\t" << tab.get_element(i)->second << std::endl;
        else   std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

