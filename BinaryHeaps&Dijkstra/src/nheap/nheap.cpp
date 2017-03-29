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



int main()
{
  std::cout << "initializing heap\n";
  Nheap myheap(2, 200);
  std::cout << "done./n";
  std::pair<unsigned, unsigned> pair1(30,2), pair2(100,3),pair3(1,4);
  std::cout << "inserting pair1...\n";
  myheap.insert(pair1);
  std::cout << "inserting pair2...\n";
  myheap.insert(pair2);
  std::cout << "inserting pair3...\n";
  myheap.insert(pair3);
  std::cout << "done./n";

  

}
