#include <iostream>
#include "hheap.h"

void print_size(HHeap &h) {
  std::cout << "full nodes: "<< h.num_full_nodes << " all nodes: "<< h.num_all_nodes << "\n";

}

int main(){
  
  HHeap heap;
  Item meuitem(111),i2(999), i3(9);

  heap.insert(&meuitem, 20);
  heap.insert(&i2, 90);
  heap.insert(&i3, 22);
  heap.genDot("1.dot");
  heap.decrease_key(&meuitem, 10);
  heap.genDot("2.dot");
  heap.delete_min();
  heap.genDot("3.dot");   
  heap.decrease_key(heap.find_min(), 1);
  print_size(heap);

  std::cout<< "is empty?: " << heap.empty()<<"\n";
  heap.delete_min();
  std::cout<< "is empty?: " << heap.empty()<<"\n";
  heap.genDot("4.dot");
}
