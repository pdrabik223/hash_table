﻿// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
//
#include <string>
#include <stdlib.h>
#include "hash_table.h"
#include "pair.h"

unsigned read_file(const char *file_path);

unsigned read_console();


template<class KEY, class VAL>
class hash_function_properties {
public:
    virtual size_t

    hash_function(KEY &key, my::pair<KEY, VAL> **storage_, const size_t h_table_size) = 0;

    virtual my::pair<KEY, VAL> *
    find(KEY &key, my::pair<KEY, VAL> **storage_, const size_t h_table_size) = 0;

    virtual void
    delete_function(KEY &position, my::pair<KEY, VAL> **storage_, const size_t h_table_size) = 0;
};

template<class KEY, class VAL>
class open_addressing : public hash_function_properties<KEY, VAL> {

public:
    size_t hash_function(KEY &key, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = key % h_table_size;

        while (!(storage_[index] == nullptr || storage_[index]->first == key)) ++index;

        return index;
    }

    my::pair<KEY, VAL> *find(KEY &position, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = position % h_table_size;

        while (storage_[index]->first != position) {

            if (index >= h_table_size || storage_[index]) return nullptr;
            ++index;
        }
        return storage_[index];
    }

    void delete_function(KEY &position, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = position % h_table_size;

        while (storage_[index]->first != position || storage_[index] != nullptr) {
            ++index;
        }

        while (storage_[index]->first != index || storage_[index] != nullptr) {
            storage_[index] = storage_[index + 1];
        }


    }
};


template<class KEY, class VAL>
class h_table {
public:

    h_table(size_t size) {
        operations_ = new open_addressing<KEY, VAL>();
        storage_ = (my::pair<KEY, VAL> **) malloc(size * sizeof(my::pair<KEY, VAL> *));
        this->size_ = size;
    }


    void push(my::pair<KEY, VAL> value) {
        storage_[operations_->hash_function(value.first, storage_, size_)] = &value;
    };

    void push(KEY key, VAL value) {

        storage_[operations_->hash_function(key, storage_, size_)] = new my::pair<KEY, VAL>(key, value);
    };


    void pop(const my::pair<KEY, VAL> &value) {
        operations_->delete_function[(value.first, storage_, size_)];
    };

    void pop(const KEY &value) {
        operations_->delete_function[(value.first, storage_, size_)];
    };

    VAL &operator[](KEY position) {
        return operations_->find(position, storage_, size_)->second;
    }

    VAL &operator[](KEY &position) {
        return operations_->hash_function(position, storage_, size_)->second;
    }

    ~h_table() {
        delete[]storage_;
        delete operations_;
    }

private:

    hash_function_properties<KEY, VAL> *operations_;
    my::pair<KEY, VAL> **storage_;
    size_t size_;


};


int main() {
    std::cout << "Hello CMake." << std::endl;
    h_table<int, char> tab(10);
    tab.push(my::pair<int, char>(3, 'k'));
    std::cout << "val : " << tab[3] << std::endl;

    tab.push(13, 's');

    std::cout << "val : " << tab[4] << std::endl;


    return 0;
}
