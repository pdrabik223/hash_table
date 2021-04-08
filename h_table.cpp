// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "h_table.h"

template<class KEY, class VAL>
h_table<KEY, VAL>::~h_table() {
    delete[]storage_;
    delete operations_;
}

template<class KEY, class VAL>
VAL &h_table<KEY, VAL>::operator[](KEY position) {
    return operations_->find(position, storage_, size_)->second;
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

    this->size_ = size;
}
