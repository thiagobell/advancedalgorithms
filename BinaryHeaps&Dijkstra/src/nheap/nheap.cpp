#include "nheap.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
template <class T>
Nheap<T>::Nheap(int n, int maxsize)
{
this->n = n;
this->maxsize = maxsize;
 num_swaps = 0;
 num_insert = 0;
 num_update = 0;
 num_deletemin = 0;
 data.reserve(maxsize);
}


template <class T>
bool Nheap<T>::empty()
{
  if(data.size() == 0)
    return true;
  return false;
}

template <class T>
unsigned Nheap<T>::get_index_child(unsigned parent_index, unsigned child_num)
{
return parent_index*n + child_num;
}

template <class T>
unsigned Nheap<T>::get_index_parent(unsigned elem_index)
{
return std::floor((elem_index-1)/n);
}

template <class T>
void Nheap<T>::insert(hnode<T> elem) 
{
  unsigned int position = data.size(); //index at which the elem will be inserted
  data.push_back(elem);
  num_insert++;
  heapify_up(position);
}

template <class T>
void Nheap<T>::heapify_up(unsigned int position_elem)
{
  if(position_elem == 0) //is root
    return;
  unsigned int position_parent =  get_index_parent(position_elem);
  unsigned int key_parent = data[position_parent].priority;
  unsigned int key_elem = data[position_elem].priority;

  if(key_parent > key_elem) {
    hnode<T> temp;
    temp = data[position_parent];
    data[position_parent] = data[position_elem];
    data[position_elem] = temp;
    num_swaps++;
    heapify_up(position_parent);
  }
}

template <class T>
void Nheap<T>::heapify_down(unsigned int position_elem) {

  unsigned int position_first_child = get_index_child(position_elem, 1);

  if(position_first_child >= data.size()) {
    //element has no children
    return;
  }
  
  unsigned int number_children = data.size()-position_first_child;
  if(number_children > n)
    number_children = n;

  if(number_children == 1) {
    //element has only one child
    if(data[position_elem].priority > data[position_first_child].priority){
      hnode<T> temp = data[position_elem];
      data[position_elem] = data[position_first_child];
      data[position_first_child] = temp;
      num_swaps++;
      heapify_down(position_first_child);
    }
  } else {
    //there is more than one child
    unsigned lowest_key, lowest_key_position;
    lowest_key = data[position_first_child].priority;
    lowest_key_position = position_first_child;
    for(unsigned i=position_first_child+1; i < position_first_child+number_children;i++){
      unsigned key = data[i].priority;
      if(key < lowest_key){
	lowest_key = key;
	lowest_key_position = i;
      }
    }

    if(data[position_elem].priority > lowest_key) {
      //swap elements if parent has a key larger then one of the smallest children
      hnode<T> temp = data[position_elem];
      data[position_elem] = data[lowest_key_position];
      data[lowest_key_position] = temp;
      num_swaps++;
      heapify_down(lowest_key_position);
    }
  }
  

}


//finds internal vector index for a given id
template <class T>
unsigned int Nheap<T>::find_elem_index(T id)
{
  int i=0;
  while(i < data.size()) {
    if(data[i].id == id)
      return i;
    i++;
  }
  throw "id not found";
}


template <class T>
void Nheap<T>::update_key(T id, unsigned int new_priority)
{
  unsigned int pos = find_elem_index(id);
  unsigned int old_key = data[pos].priority;
  num_update++;
  if(new_priority < old_key) {
    data[pos].priority = new_priority;
    heapify_up(pos);
  } else {
    data[pos].priority = new_priority;
    heapify_down(pos);
  }
}

//error if size of tree is zero
template <class T>
hnode<T> Nheap<T>::get_min()
{
  if(data.size() >= 1) {
    return data[0];
  }
  throw "heap is empty";
  //throws exception
}

template <class T>
void Nheap<T>::print_heap()
{
  int node_count = 0;
  int num_nodes_at_level = 1;
  int nodes_printed_at_level=0;
  std::cout << "size of heap:" << data.size()<< "\n"; 
  while(node_count < data.size()) {
    
    if(nodes_printed_at_level < num_nodes_at_level) {
      nodes_printed_at_level++;     
      std::cout << data[node_count].priority << " ";
    } else {
      nodes_printed_at_level = 1;
      num_nodes_at_level *= n;
      std::cout << "\n"<< "level: " << data[node_count].priority << " ";
    }
    node_count++;
  }
  std::cout << "\n";
}

template <class T>
void Nheap<T>::delete_elem(T value)
{
  unsigned int array_index = find_elem_index(value);
  data[array_index] = data[data.size()-1];
  data.pop_back();
  heapify_down(array_index);
}

template <class T>
hnode<T> Nheap<T>::delete_min()
{
  hnode<T> temp = get_min();
  data[0] = data[data.size()-1];
  data.pop_back();
  num_deletemin++;
  heapify_down(0);
  return temp;
}

template class Nheap<unsigned>;
