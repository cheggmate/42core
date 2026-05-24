#include "searchable_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "searchable_array_bag.hpp"
#include "set.hpp"

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
  if (argc == 1)
    return 1;
  searchable_bag *t = new searchable_tree_bag;
  searchable_bag *a = new searchable_array_bag;

  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  t->print();
  a->print();

  for (int i = 1; i < argc; i++) {
    std::cout << t->has(atoi(argv[i])) << std::endl;
    std::cout << a->has(atoi(argv[i])) << std::endl;
    std::cout << t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << a->has(atoi(argv[i]) - 1) << std::endl;
  }
  t->clear();
  a->clear();

  const searchable_array_bag tmp = searchable_array_bag(static_cast<searchable_array_bag &>(*a));
  tmp.print();
  tmp.has(1);

  set set_a(*a);
  set set_t(*t);
  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));

    a->has(atoi(argv[i]));
    a->print();
    set_a.get_bag().print();
    t->print();
    a->clear();
	int temp_array[] = {1, 2, 3, 4};
	a->insert(temp_array, 4);
    std::cout << std::endl;
  }

  return 0;
}