/**
  Header definition of n-ary min-heap
 **/

#ifndef NHEAP_H
#define NHEAP_H

#include <vector>


class Nheap {
 private:
  std::vector<std::pair<unsigned int, unsigned int> > data;
  int n, maxsize;
  unsigned get_index_parent(unsigned elem_index);
  //child num is the index of the child starting from 1
  unsigned get_index_child(unsigned parent_index, unsigned child_num);
  void heapify_up(unsigned int position_elem);
  void heapify_down(unsigned int position_elem);
  unsigned int  find_key_index(unsigned int key);
 public:
  //maxsize is the largest number of nodes in heap.
  //n is heap n-arity
  Nheap(int n, int maxsize);

  //each element is a pair with <key, id>
  void insert(std::pair<unsigned int, unsigned int> elem);

  std::pair<unsigned int, unsigned int> get_min();

  //  std::pair<unsigned int, unsigned int> delete_min();

  //  void delete_elem(std::pair<unsigned int, unsigned int> pair)
 
  void update(unsigned int old_key, unsigned int new_key);
  
  void print_heap();

};

#endif
