#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {

}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& source) : tree_bag(source) {
	
}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& source) {
	if (this != &source) { // Also added missing & address-of operator check
		tree_bag::operator=(source);
	}
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag() {

}

// Fixed: changed class scope to searchable_tree_bag and specified tree_bag::node
bool searchable_tree_bag::search(tree_bag::node* node, const int value) const {
	if (node == NULL) // NULL is preferred over NULL in modern C++
		return (false);
	if (node->value == value)
		return (true);
	else if (value < node->value)
		return (search(node->l, value));
	else
		return (search(node->r, value));
}

bool searchable_tree_bag::has(int value) const {
	return (search(this->tree, value));
}