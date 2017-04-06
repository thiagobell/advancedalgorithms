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
  while(node_count < data.size()) {
    
    if(nodes_printed_at_level < num_nodes_at_level) {
      nodes_printed_at_level++;     
      std::cout << data[node_count].priority << " ";
    } else {
      nodes_printed_at_level = 1;
      num_nodes_at_level *= n;
      std::cout << "\n" << data[node_count].priority << " ";
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
  heapify_down(0);
  return temp;
}
/*
int main()
{
  
  std::cout << "initializing heap\n";
  Nheap<std::string> myheap(2, 200);
  std::cout << "done./n";
  hnode<std::string> pair1(30,"hello"), pair2(100,"its"),pair3(1,"me"),min;
  std::cout << "inserting pair1...\n";
  myheap.insert(pair1);
  std::cout << "inserting pair2...\n";
  myheap.insert(pair2);
  std::cout << "inserting pair3...\n";
  myheap.insert(pair3);
  std::cout << "done.\n";
  myheap.print_heap();
  min = myheap.get_min();
  std::cout << "minimum key is " << min.key;

  std::cout << "updating key 1 to 2\n";
  myheap.update_key("me",2);
  min = myheap.get_min();
  std::cout << "minimum key and value are " << min.key <<" "<<min.value << "\n";
  
  std::cout << "updating key 30 to 0\n";
  myheap.update_key("hello",0);
  min = myheap.get_min();
  std::cout << "minimum key and value are " << min.key <<" "<<min.value << "\n";
  myheap.print_heap();

  std::cout << "delete key 0\n";
  myheap.delete_elem("hello");
  myheap.print_heap();
  
}
*/
template class Nheap<unsigned>;
