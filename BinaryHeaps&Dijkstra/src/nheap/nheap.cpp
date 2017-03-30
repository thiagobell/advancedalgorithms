#include "nheap.hpp"
#include <iostream>
#include <cmath>
#include <vector>

Nheap::Nheap(int n, int maxsize)
{
this->n = n;
this->maxsize = maxsize;
}

unsigned Nheap::get_index_child(unsigned parent_index, unsigned child_num)
{
return parent_index*n + child_num;
}

unsigned Nheap::get_index_parent(unsigned elem_index)
{
return std::floor((elem_index-1)/n);
}


void Nheap::insert(std::pair<unsigned int, unsigned int> elem) 
{
  unsigned int position = data.size(); //index at which the elem will be inserted
  data.push_back(elem);
  heapify_up(position);
}

void Nheap::heapify_up(unsigned int position_elem)
{
  if(position_elem == 0) //is root
    return;
  unsigned int position_parent =  get_index_parent(position_elem);
  unsigned int key_parent = data[position_parent].first;
  unsigned int key_elem = data[position_elem].first;

  if(key_parent > key_elem) {
    std::pair<unsigned int, unsigned int> temp;
    temp = data[position_parent];
    data[position_parent] = data[position_elem];
    data[position_elem] = temp;
    heapify_up(position_parent);
  }
}

void Nheap::heapify_down(unsigned int position_elem) {

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
  } else {
    //there is more than one child
    unsigned lowest_key, lowest_key_position;
    lowest_key = data[position_first_child].first;
    lowest_key_position = position_first_child;
    for(unsigned i=position_first_child+1; i < position_first_child+number_children;i++){
      unsigned key = data[i].first;
      if(key < lowest_key){
	lowest_key = key;
	lowest_key_position = i;
      }
    }

    if(data[position_elem].first > lowest_key) {
    
    //swap elements if parent has a key larger then one of the smallest children
    std::pair<unsigned int, unsigned int> temp = data[position_elem];
    data[position_elem] = data[lowest_key_position];
    data[lowest_key_position] = temp;
    heapify_down(lowest_key_position);
    }
  }
  

}
//finds internal vector index for a given key
unsigned int Nheap::find_key_index(unsigned int key)
{
  int i=0;
  while(i < data.size()) {
    if(data[i].first == key)
      return i;
    i++;
  }
  throw "key not found";
}
  
void Nheap::update(unsigned int old_key, unsigned int new_key)
{
  unsigned int pos = find_key_index(old_key);
  if(new_key < old_key) {
    data[pos].first = new_key;
    heapify_up(pos);
  } else {
    data[pos].first = new_key;
    heapify_down(pos);
  }
}

//error if size of tree is zero
std::pair<unsigned int, unsigned int> Nheap::get_min()
{
  if(data.size() > 1) {
    return data[0];
  }
  throw "heap is empty";
  //throws exception
}


void Nheap::print_heap()
{
  int node_count = 0;
  int num_nodes_at_level = 1;
  int nodes_printed_at_level=0;
  while(node_count < data.size()) {
    
    if(nodes_printed_at_level < num_nodes_at_level) {
      nodes_printed_at_level++;     
      std::cout << data[node_count].first << " ";
    } else {
      nodes_printed_at_level = 1;
      num_nodes_at_level *= n;
      std::cout << "\n" << data[node_count].first << " ";
    }
    node_count++;
  }
  std::cout << "\n";
}


int main()
{
  std::cout << "initializing heap\n";
  Nheap myheap(2, 200);
  std::cout << "done./n";
  std::pair<unsigned, unsigned> pair1(30,2), pair2(100,3),pair3(1,4),min;
  std::cout << "inserting pair1...\n";
  myheap.insert(pair1);
  std::cout << "inserting pair2...\n";
  myheap.insert(pair2);
  std::cout << "inserting pair3...\n";
  myheap.insert(pair3);
  std::cout << "done.\n";
  myheap.print_heap();
  min = myheap.get_min();
  std::cout << "minimum key is " << min.first;

  std::cout << "updating key 1 to 2\n";
  myheap.update(1,2);
  min = myheap.get_min();
  std::cout << "minimum key is " << min.first << "\n";
  
  std::cout << "updating key 30 to 0\n";
  myheap.update(30,0);
  min = myheap.get_min();
  std::cout << "minimum key is " << min.first << "\n";
  myheap.print_heap();
}
