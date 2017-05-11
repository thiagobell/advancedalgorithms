#include <iostream>
#include "nheap.h" 
int main()
{

Nheap<unsigned> h(2,1000);
h.insert(hnode<unsigned>(10,1));
h.insert(hnode<unsigned>(20,2));
h.insert(hnode<unsigned>(30,3));
h.insert(hnode<unsigned>(40,4));
h.insert(hnode<unsigned>(50,5));
h.print_heap();
h.update_key(2, 5);
h.print_heap();

while(!h.empty())
{
std::cout << "heap before\n";
h.print_heap();
hnode<unsigned> temp = h.delete_min();
std::cout << "removed element with id"<< temp.id<<"\n";
std::cout << "heap after\n";
h.print_heap();
std::cout <<"-------------------------\n";


}

}
