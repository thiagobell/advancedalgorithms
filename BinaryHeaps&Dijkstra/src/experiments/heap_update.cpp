#include "../nheap/nheap.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <cmath>

int main()
{
  unsigned n = 2;
  unsigned int count = 0;

  for(unsigned i = 1; i <21; i++) {
    
    Nheap<unsigned int> heap(n, 2);
    unsigned int next_value = 1;
    unsigned int two_i = std::pow(2, i);
    unsigned int priority = two_i +1;
    for(unsigned int j = 0; j < two_i -1; j++){
      heap.insert(hnode<unsigned int>(priority, next_value));
      next_value++;
      //      std::cout << " inserting priority " << priority << "value "<< next_value-1<<"\n";
    }
    priority +=1;
    for(unsigned int j = 0; j < two_i ; j++){
      heap.insert(hnode<unsigned int>(priority, next_value));
      next_value++;
      
      //      std::cout << " inserting priority " << priority << "value "<< next_value-1<<"\n";
    }
    //heap.print_heap();
    unsigned int new_priority = two_i;


    heap.num_swaps = 0;
    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();

    for(unsigned int j = next_value-two_i; j < next_value ; j++){
      //std::cout <<"updating value = "<<j<< " priority <<" << new_priority <<"\n";
      heap.update_key(j, new_priority);
      new_priority--;
    }
    //heap.print_heap();
    std::cout << "i="<<i<<" time=" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() << " swap count= "<< heap.num_swaps <<  std::endl;

   

  }

  
}
