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

        while (true){

          if(&storage_[index] == nullptr) return index;
            else if(storage_[index].first == key) return index;
            ++index;
        }

    }

    my::pair<KEY, VAL> *find(KEY &position, my::pair<KEY, VAL> *storage_, const size_t h_table_size) {

        size_t index = position % h_table_size;

        while (storage_[index].first != position) {

            if (index >= h_table_size || &storage_[index]) return nullptr;
            ++index;
        }
        return &storage_[index];
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
