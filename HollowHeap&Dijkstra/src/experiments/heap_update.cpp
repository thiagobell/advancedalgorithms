#include "../hheap/hheap.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
int main()
{
  unsigned n = 2;
  unsigned int count = 0;

  for(unsigned i = 1; i <21; i++) {   
    //Nheap<unsigned int> heap(n, 2);
		//Node *heap = make_heap();
		HHeap heap;
    unsigned int next_value = 1;
    unsigned int two_i = std::pow(2, i);
    unsigned int priority = two_i +1;
		std::vector<Item*> items1;	
    for(unsigned int j = 0; j < two_i -1; j++){
			Item *itm = new Item(next_value);
      heap.insert(itm, priority);
			items1.push_back(itm);
      next_value++;
      //      std::cout << " inserting priority " << priority << "value "<< next_value-1<<"\n";
    }
    priority +=1;
		std::vector<Item*> items2;
    for(unsigned int j = 0; j < two_i ; j++){
			Item *itm = new Item(next_value);
      heap.insert(itm, priority);
			items2.push_back(itm);
      next_value++;
      
      //      std::cout << " inserting priority " << priority << "value "<< next_value-1<<"\n";
    }

    unsigned int new_priority = two_i;


		heap.num_melds = 0;
		heap.num_nodes_created = 0;
		heap.num_nodes_destroyed = 0;
		heap.num_links = 0;
    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();

    for(unsigned int j = 0; j < items2.size() ; j++){
      //std::cout <<"updating value = "<<j<< " priority <<" << new_priority <<"\n";
//      heap.update_key(j, new_priority);
			heap.decrease_key(items2[j], new_priority);
			new_priority--;
    }
    //heap.print_heap();
    std::cout << "i="<<i<<" time=" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() <<" nodes_created= " << heap.get_num_nodes_created() << " nodes_destroyed= " << heap.get_num_nodes_destroyed() << " num_melds= " << heap.get_num_melds() << " num_links= "<< heap.get_num_links()<<  std::endl;
	//deallocating items from dynamic memory
	for(unsigned int j = 0; j < items1.size() ; j++){
		delete items1[j];		
	}
  for(unsigned int j = 0; j < items2.size() ; j++){
		delete items2[j];		
	}

  }

  
}
