// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
//
#include <string>
#include <cstdlib>
#include "h_table.h"

bool read_console(std::string &command, h_table<long int, std::string> &tab);
// todo 6) repair []
// todo 2) repair get element to not return pointer but instead something else
// todo 3) mahe the thing goble up the input's from console
// todo 4) general debbuging


int main() {
    h_table<long int, std::string> tab(10);
    int N;
    std::cin >> N;
    std::string command;
    for (int i = 0; i < N; i++) {
        while (true) {
            std::cin >> command;
            if (read_console(command, tab)) break;
        }
    }

    return 0;
}

bool read_console(std::string &command, h_table<long int, std::string> &tab) {
    if (command == "size") {
        int size;
        tab.clear();
        std::cin >> size;
        tab.set_size(size);
        return false;
    }

    if (command == "add") {
        long int key;
        std::string val;
        std::cin >> key;
        std::cin >> val;
        tab.push(key, val);
        return false;
    }
    if (command == "delete") {
        long int key;
        std::cin >> key;
        tab.pop(key);
        return false;
    }
    if (command == "print") {
        for (int i = 0; i < tab.get_size(); i++) {

            if (tab.get_element(i) != nullptr)
                std::cout << i << " " << tab.get_element(i)->first << " " \
                << tab.get_element(i)->second << std::endl;

        }
        std::cout << std::endl;
        return false;
    }
    if (command == "stop") {
        return true;

    }


}