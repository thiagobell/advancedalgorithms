#include "../nheap/nheap.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <cmath>

int main()
{
  unsigned n = 2;
  Nheap<unsigned int> heap(n, 2);
  unsigned int count = 0;

  for(unsigned i = 1; i <21; i++) {

    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();

    unsigned int two_i = std::pow(2, i);
    unsigned int value = two_i +1;
    for(unsigned int j = 0; j < two_i -1; j++){
      heap.insert(hnode<unsigned int>(value, value));
    }
    value +=1;
    for(unsigned int j = 0; j < two_i ; j++){
      heap.insert(hnode<unsigned int>(value, value));
    }
    unsigned int new_value = two_i;
    for(unsigned int j = 0; j < two_i ; j++){
      heap.update_key(value, new_value);
      std::cout << new_value << "\n";
      new_value--;
    }
    
    std::cout << "i="<<i<<" time=" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() << " swap count= "<< heap.num_swaps <<  std::endl;

    heap.num_swaps = 0;
   

  }

  
}
