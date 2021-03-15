// hash_table.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "hash_table.h"
#include "pair.h"
// adresowanie otwarte z przyrostem liniowym = 1

unsigned read_file(const char* file_path);
unsigned read_console();

template<class KEY, class VAL>
class hash_function_properties {
public:
	virtual size_t hash_function(const KEY& position, const my::pair<KEY, VAL>* storage_, const  size_t h_table_size) = delete;
};

template<class KEY, class VAL>
class open_addresing:public hash_function_properties {

public:
	 size_t hash_function(const KEY& position, const my::pair<KEY, VAL>* storage_, const size_t h_table_size) {
	
		 size_t index = position % h_table_size;
		
		 while ( storage_[index].first != position || storage_[index].first != {}) {
			 ++index;
		 };
		 return index;
	 }

};



template <class KEY,class VAL>
class h_table {


	h_table(size_t size) {
		hash_function_ = new open_addresing<KEY>();
		storage_ = new my::pair<KEY, VAL>[size];
		this->size_ = size;
	}

	
	void push(const my::pair<KEY, VAL>& value) {
		storage_[*hash_function_(value.first, storage_, size_)] = value;
	};
	void pop(const my::pair<KEY, VAL>& value) {
		storage_[*hash_function_(value.first, storage_, size_)] = value;

	};
	


private:
	
	hash_function_properties<KEY>* hash_function_;
	my::pair<KEY,VAL>* storage_;
	size_t size_;


};


int main()
{
	std::cout << "Hello CMake." << std::endl;
	return 0;
}
