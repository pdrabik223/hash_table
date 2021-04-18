//
// Created by studio25 on 21.03.2021.
//

#ifndef HASH_TABLE_HASH_FUNCTION_H
#define HASH_TABLE_HASH_FUNCTION_H


template<class KEY, class VAL>
class hash_function_properties {
public:
    virtual size_t
    hash(KEY &key, size_t h_table_size) = 0;

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
    size_t hash(KEY &key, size_t h_table_size) {
        return key % h_table_size;
    }


    size_t hash_function(KEY &key, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = hash(key, h_table_size);

        for (int i = 0; i < h_table_size; ++i) {

            if (storage_[index] == nullptr) return index;
            else if (storage_[index]->first == key) return index;
            index++;
            if (index == h_table_size) index = 0; // wrap around
        }
        throw "out of table_range";
    }

    my::pair<KEY, VAL> *find(KEY &position, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = hash(position, h_table_size);

        for (int i = 0; i < h_table_size; ++i) {

            if (!storage_[index]) return storage_[index];
            else if (storage_[index]->first == position) return storage_[index];
            index++;
            if (index == h_table_size) index = 0; // wrap around
        }
        throw "out of table_range";
    }

    void delete_function(KEY &key, my::pair<KEY, VAL> **storage_, const size_t h_table_size) {

        size_t index = hash(key,h_table_size); // solve for proper position of element in tab
        size_t proper_element_index = index; // the place where element should be
        // when element collisions happen element gets  misplaced
        int i;
        for ( i=0 ; i < h_table_size; ++i) {

            if(storage_[index]->first == key)break;
            index++;
            if (index == h_table_size) index = 0; // wrap around
        }
        if(i == h_table_size)   throw "out of table_range";


        storage_[index] = nullptr; // deleting the wanted item;

        for ( i = 0; i < h_table_size; ++i) {// correct the position of subsequent element's

            if (storage_[index + 1] == nullptr) break;

            if (hash(storage_[index + 1]->first, h_table_size) != index + 1) {

                storage_[index] = new my::pair<KEY, VAL>(storage_[index + 1]->first, storage_[index + 1]->second);

                storage_[index + 1] = nullptr; // deleting subsequent element
            } else break;

            ++index;
            if (index == h_table_size) index = 0; // wrap around
        }

    }
};

#endif //HASH_TABLE_HASH_FUNCTION_H
