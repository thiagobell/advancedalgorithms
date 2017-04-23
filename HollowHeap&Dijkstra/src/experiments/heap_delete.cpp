#include "../hheap/hheap.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <vector>
int main()
{
  //current time is seed
  std::srand(std::time(0));
  
  unsigned n = 2;
  unsigned int count = 0;

  for(unsigned i = 1; i <=30; i++) {
    HHeap heap;
    unsigned int two_i = std::pow(2, i);
    unsigned int next_value = 0;
		std::vector<Item> items;
		items.resize(two_i -1);
    for(unsigned int j = 0; j < two_i -1; j++){
			items.push_back(Item(next_value));
			heap.insert(&items[items.size()-1],(unsigned)std::rand());
	    next_value++;
    }

		heap.num_melds = 0;
		heap.num_nodes_created = 0;
		heap.num_nodes_destroyed = 0;
		heap.num_links = 0;
    unsigned int num_deletes = std::pow(2,i-1);
    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();

    for(unsigned int j = 0; j < num_deletes ; j++){
      heap.delete_min();
    }
    std::cout << "i="<<i<<" time=" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() <<" nodes_created= " << heap.get_num_nodes_created() << " nodes_destroyed= " << heap.get_num_nodes_destroyed() << " num_melds= " << heap.get_num_melds() << " num_links= "<< heap.get_num_links()<<  std::endl;

   

  }

  
}
