#include "../hheap/hheap.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <cmath>

int main()
{
  unsigned n = 2;
  unsigned num_levels = 27;
  unsigned num_keys = std::pow(2,num_levels)-1;

  unsigned next_key = num_keys; 
  HHeap heap;

  for(unsigned i = 0; i < num_levels; i++) {
    unsigned num_keys_level = std::pow(n,i);
    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();

    for(unsigned j = next_key; j > next_key - num_keys_level; j-- ) {
			heap.insert(new Item(0), j);      
	//heap.insert(hnode<unsigned>(j, 0));	
    }
    
    std::cout << "i= "<<i<<" time= " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count()<<" nodes_created= " << heap.get_num_nodes_created() << " nodes_destroyed= " << heap.get_num_nodes_destroyed() << " num_melds= " << heap.get_num_melds() << " num_links= "<< heap.get_num_links()<<  std::endl;	

		heap.num_melds = 0;
		heap.num_nodes_created = 0;
		heap.num_nodes_destroyed = 0;
		heap.num_links = 0;
    next_key -= num_keys_level;
  }
}

  
