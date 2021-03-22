// hash_table.h: plik dołączany dla standardowych systemowych plików dołączanych,
// lub pliki dołączane specyficzne dla projektu.

#pragma once

#include <iostream>

#include "pair.h"
#include "hash_function.h"
template<typename h_table>
class iterator
{

public:
    using ValueType = typename h_table::ValueType;

    ValueType* current_ptr;

public:
    iterator(ValueType*  x) :current_ptr(x) {}
    iterator(const iterator& mit) : current_ptr(mit.current_ptr) {}
    iterator& operator++() {++current_ptr;return *this;}
    iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
    bool operator==(const iterator& rhs) const {return current_ptr==rhs.current_ptr;}
    bool operator!=(const iterator& rhs) const {return current_ptr!=rhs.current_ptr;}
    ValueType& operator*() {return *current_ptr;}
};

template<class KEY, class VAL>
class h_table {
public:



    using ValueType =  my::pair<KEY, VAL>;

    iterator<h_table<KEY,VAL>> begin() {
        return iterator<h_table<KEY,VAL>>(storage_);
    };

    iterator<h_table<KEY,VAL>> end() {
        return iterator<h_table<KEY,VAL>>(&storage_[size_]);
    };



    h_table(size_t size) {
        operations_ = new open_addressing<KEY, VAL>();
        storage_ = new my::pair<KEY, VAL> [size];
        this->size_ = size;
    }


    void push(my::pair<KEY, VAL> value) {
        storage_[operations_->hash_function(value.first, storage_, size_)] = value;
    };

    void push(KEY key, VAL value) {

        storage_[operations_->hash_function(key, storage_, size_)] = my::pair<KEY, VAL>(key, value);
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
    my::pair<KEY, VAL> *storage_;
    size_t size_;


};
// TODO: W tym miejscu przywołaj dodatkowe nagłówki wymagane przez program.
