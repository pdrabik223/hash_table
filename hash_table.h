// hash_table.h: plik dołączany dla standardowych systemowych plików dołączanych,
// lub pliki dołączane specyficzne dla projektu.

#pragma once

#include <iostream>
#include "pair.h"
#include "hash_function.h"
template<class KEY, class VAL>
class h_table {
public:

    h_table(size_t size) {
        operations_ = new open_addressing<KEY, VAL>();
        storage_ = new my::pair<KEY, VAL> *[size];
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
        return operations_->find(position, storage_, size_)->second;
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
// TODO: W tym miejscu przywołaj dodatkowe nagłówki wymagane przez program.
