#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {

}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& source) : array_bag(source) {

}

// Fixed typo 'bsearchable' to 'searchable' and added missing & to source comparison
searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& source) {
	if (this != &source) {
		array_bag::operator=(source);
	}
	return (*this);
}

// Fixed typo 'searcheable' and added missing empty parentheses ()
searchable_array_bag::~searchable_array_bag() {

}

bool searchable_array_bag::has(int value) const {
	for (int i = 0 ; i < this->size ; i++) {
		if (this->data[i] == value) {
			return (true);
		}
	}
	return (false);
}