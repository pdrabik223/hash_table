//
// Created by studio25 on 21.03.2021.
//

#ifndef HASH_TABLE_HASH_FUNCTION_H
#define HASH_TABLE_HASH_FUNCTION_H


template<class KEY, class VAL>
class hash_function_properties {
public:
    virtual size_t

    hash_function(KEY &key, my::pair<KEY, VAL> **storage_, size_t h_table_size) = 0;


    virtual my::pair<KEY, VAL> *
    find(KEY &key, my::pair<KEY, VAL> **storage_, size_t h_table_size) = 0;

    virtual void
    delete_function(KEY &key, my::pair<KEY, VAL> **storage_, size_t h_table_size) = 0;
};

template<class KEY, class VAL>
class open_addressing : public hash_function_properties<KEY, VAL> {

public:
    size_t hash_function(KEY &key, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = key % h_table_size;

        for (; index < h_table_size; ++index) {

            if (storage_[index] != nullptr) return index;
            else if (storage_[index]->first == key) return index;

        }
        throw "out of table_range";
    }

    my::pair<KEY, VAL> *find(KEY &position, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = position % h_table_size;

        for (index; index < h_table_size; ++index) {

            if (!storage_[index]) return storage_[index];
            else if (storage_[index]->first == position) return storage_[index];

        }
        throw "out of table_range";
    }

    void delete_function(KEY &key, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = key % h_table_size; // solve for proper position of element in tab
        size_t index_copy = index;


        for (; index <= h_table_size; ++index) {   // check if the element under position
            if (storage_[index]->first == key) break;   // is the right one,
            // if not go thru elements after this one till you find corect one
        }
        if (index == h_table_size) return; // if tab does not contain element

        while (storage_[index]->first % h_table_size == index_copy) {  // correct position of subsequent element's
            if (index >= h_table_size) return;
            storage_[index] = storage_[index + 1];
            storage_[index + 1] = nullptr; // this can be better
            ++index;
        }


    }
};

#endif //HASH_TABLE_HASH_FUNCTION_H
