// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
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
    hash_function(const KEY &position, const my::pair<KEY, VAL> **storage_, const size_t h_table_size) = 0;

    virtual void
    delete_function(const KEY &position, my::pair<KEY, VAL> **storage_, const size_t h_table_size) = 0;
};

template<class KEY, class VAL>
class open_addressing : public hash_function_properties<KEY, VAL> {

public:
    size_t hash_function(const KEY &position, const my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = position % h_table_size;

        while (storage_[index]->first != position || storage_[index] != nullptr) {
            ++index;
        }
        return index;
    }

    void delete_function(const KEY &position, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

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
        storage_ = (my::pair<KEY, VAL> **) malloc (size*sizeof(my::pair<KEY, VAL> *));
        this->size_ = size;
    }


    void push(const my::pair<KEY, VAL> value) {
        storage_[operations_->hash_function(value.first, storage_, size_)] = &value;
    };

    void push(KEY key, VAL value) {
        storage_[operations_->hash_function(key, storage_, size_)] = new my::pair<KEY,VAL>(key,value);
    };


    void pop(const my::pair<KEY, VAL> &value) {
        operations_->delete_function[(value.first, storage_, size_)];
    };

    void pop(const KEY &value) {
        operations_->delete_function[(value.first, storage_, size_)];
    };

    VAL& operator[](const KEY& position){

        return *storage_[operations_->hash_function(position, storage_, size_)];
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
    h_table<int, std::string> tab(10);
    tab.push({3,"lol"});
    tab.push(4,"lel");

    return 0;
}
