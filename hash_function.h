//
// Created by studio25 on 21.03.2021.
//

#ifndef HASH_TABLE_HASH_FUNCTION_H
#define HASH_TABLE_HASH_FUNCTION_H


template<class KEY, class VAL>
class hash_function_properties {
public:
    virtual size_t

    hash_function(KEY &key, my::pair<KEY, VAL> *storage_, const size_t h_table_size) = 0;

    virtual my::pair<KEY, VAL> *
    find(KEY &key, my::pair<KEY, VAL> *storage_, const size_t h_table_size) = 0;

    virtual void
    delete_function(KEY &position, my::pair<KEY, VAL> *storage_, const size_t h_table_size) = 0;
};

template<class KEY, class VAL>
class open_addressing : public hash_function_properties<KEY, VAL> {

public:
    size_t hash_function(KEY &key, my::pair<KEY, VAL> *storage_, const size_t h_table_size) {

        size_t index = key % h_table_size;

        auto ptr = &(storage_[index]);

        for (index; index < h_table_size; ++index) {

            if (!ptr->first)            return index;
            else if (ptr->first == key) return index;
            ++ptr;
        }
        throw "out of table_range";
    }

    my::pair<KEY, VAL> *find(KEY &position, my::pair<KEY, VAL> *storage_, const size_t h_table_size) {

        size_t index = position % h_table_size;
        auto ptr = &(storage_[index]);
        for (index; index < h_table_size; ++index) {

            if (!ptr->first)                 return ptr;
            else if(ptr->first == position)  return ptr;
            ++ptr;
        }
        throw "out of table_range";
    }

    void delete_function(KEY &position, my::pair<KEY, VAL> *storage_, const size_t h_table_size) {

        size_t index = position % h_table_size;

        while (storage_[index].first != position || &storage_[index] != nullptr) {
            ++index;
        }

        while (storage_[index].first != index || &storage_[index] != nullptr) {
            storage_[index] = storage_[index + 1];
        }


    }
};

#endif //HASH_TABLE_HASH_FUNCTION_H
