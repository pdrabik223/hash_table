// hash_table.h: plik dołączany dla standardowych systemowych plików dołączanych,
// lub pliki dołączane specyficzne dla projektu.

#pragma once

#include <iostream>
#include <cstring>

#include "pair.h"
#include "hash_function.h"

template<typename h_table>
class iterator {

public:
    using ValueType = typename h_table::ValueType;

    ValueType *current_ptr;


    iterator(ValueType *x) : current_ptr(x) {}

    iterator(const iterator &mit) : current_ptr(mit.current_ptr) {}

    iterator &operator++() {
        ++current_ptr;
        return *this;
    }

    iterator operator++(int) {
        iterator tmp(*this);
        operator++();
        return tmp;
    }

    bool operator==(const iterator &rhs) const { return current_ptr == rhs.current_ptr; }

    bool operator!=(const iterator &rhs) const { return current_ptr != rhs.current_ptr; }

    ValueType &operator*() { return *current_ptr; }
};

template<class KEY, class VAL>
class h_table {
public:


    using ValueType = my::pair<KEY, VAL>;

    iterator<h_table<KEY, VAL>*> begin() {
        return iterator<h_table<KEY, VAL>*>(storage_[0]);
    };

    iterator<h_table<KEY, VAL>*> end() {
        return iterator<h_table<KEY, VAL>*>(storage_[size_]);
    };

    my::pair<KEY, VAL>* get_element(unsigned position){
        my::pair<KEY, VAL> * temp = storage_[position];
        if(temp != nullptr) return temp;
        else return nullptr;

    }

    h_table(size_t size);


    void push(my::pair<KEY, VAL> value);

    void push(KEY key, VAL value);

    void pop(my::pair<KEY, VAL> value);

    void pop(KEY &key);

    VAL &operator[](KEY position);

    ~h_table();

    size_t get_size() const { return size_; }

private:

    hash_function_properties<KEY, VAL> *operations_;
    my::pair<KEY, VAL> **storage_;
    size_t size_;

};

template<class KEY, class VAL>
h_table<KEY, VAL>::~h_table() {
    delete[]storage_;
    delete operations_;
}

template<class KEY, class VAL>
VAL &h_table<KEY, VAL>::operator[](KEY position) {
    return *operations_->find(position, storage_, size_)->second;
}

template<class KEY, class VAL>
void h_table<KEY, VAL>::pop(KEY &key) {
    operations_->delete_function(key, storage_, size_);
}

template<class KEY, class VAL>
void h_table<KEY, VAL>::pop(my::pair<KEY, VAL> value) {
    operations_->delete_function(value.first, storage_, size_);
}

template<class KEY, class VAL>
void h_table<KEY, VAL>::push(KEY key, VAL value) {
    storage_[operations_->hash_function(key, storage_, size_)] = new my::pair<KEY, VAL>(key, value);
}

template<class KEY, class VAL>
void h_table<KEY, VAL>::push(my::pair<KEY, VAL> value) {
    storage_[operations_->hash_function(value.first, storage_, size_)] = new my::pair<KEY, VAL>(value);
}

template<class KEY, class VAL>
h_table<KEY, VAL>::h_table(size_t size) {
    operations_ = new open_addressing<KEY, VAL>();
    storage_ = new my::pair<KEY, VAL> *[size];
    memset(storage_, 0, sizeof(my::pair<KEY, VAL> *) * size);

    size_ = size;
}

