#include "../nheap/nheap.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <cmath>
#include <cstdlib>

int main()
{
  //current time is seed
  std::srand(std::time(0));
  
  unsigned n = 2;
  unsigned int count = 0;

  for(unsigned i = 1; i <=30; i++) {
    
    Nheap<unsigned int> heap(n, 2);
    unsigned int two_i = std::pow(2, i);
    unsigned int next_value = 0;
    for(unsigned int j = 0; j < two_i -1; j++){
      heap.insert(hnode<unsigned int>(std::rand(), next_value));
      next_value++;
    }
 
    heap.num_swaps = 0;
    unsigned int num_deletes = std::pow(2,i-1);
    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();

    for(unsigned int j = 0; j < num_deletes ; j++){
      heap.delete_min();
    }
    std::cout << "i="<<i<<" time=" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() << " swap count= "<< heap.num_swaps <<  std::endl;

   

  }

  
}
