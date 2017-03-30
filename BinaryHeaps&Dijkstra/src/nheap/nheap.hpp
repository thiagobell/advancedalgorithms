/**
  Header definition of n-ary min-heap
 **/

#ifndef NHEAP_H
#define NHEAP_H

#include <vector>
template <class T> 
struct hnode {
  unsigned int key;
  T value;
  hnode(unsigned int key_, T value_){
    key = key_;
    value = value_;
  }
  hnode(){};
};
template <class T>
class Nheap {
 private:
  std::vector<hnode<T> > data;
  int n, maxsize;
  unsigned get_index_parent(unsigned elem_index);
  //child num is the index of the child starting from 1
  unsigned get_index_child(unsigned parent_index, unsigned child_num);
  void heapify_up(unsigned int position_elem);
  void heapify_down(unsigned int position_elem);
  unsigned int find_elem_index(T value);
 public:
  //maxsize is the largest number of nodes in heap.
  //n is heap n-arity
  Nheap(int n, int maxsize);

  //each element is a pair with <key, id>
  void insert(hnode<T> elem);

  hnode<T> get_min();

  hnode<T> delete_min();

  void delete_elem(T value);
 
  void update_key(T value, unsigned int new_key);
  
  void print_heap();

};

#endif
