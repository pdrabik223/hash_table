// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
//
#include <string>
#include <stdlib.h>
#include "h_table.h"
#include "pair.h"

unsigned read_console();


int main() {


    h_table<int, char> tab(10);
    tab.push(3,'f');
    tab.push(13,'u');
    tab.push(23,'c');
    tab.push(33,'k');
    tab.push(4,'u');


    for(int i=0;i<tab.get_size();i++)
    if(tab.get_element(i)!= nullptr)
        std::cout<<tab.get_element(i)->first<<"\t"<<tab.get_element(i)->second<<std::endl;

    tab.pop(23);


    for(int i=0;i<tab.get_size();i++)
        if(tab.get_element(i)!= nullptr)
            std::cout<<tab.get_element(i)->first<<"\t"<<tab.get_element(i)->second<<std::endl;


    system("pause");
    return 0;
}

