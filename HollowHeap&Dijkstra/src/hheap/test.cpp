#include <iostream>
#include "hheap.h"

int main(){
  
  Node *h = NULL;
  Item meuitem(111),i2(999), i3(9);

  h = insert(&meuitem, 20, h);
  decrease_key(&meuitem, 10, h);

  h = insert(&i2, 8,h);
  
  Item *itpt;
  itpt = find_min(h);
  std::cout << "key of min is="<< itpt->node->key << " value is= "<< itpt->value; 
  h = delete_min(h);

  itpt = find_min(h);
  std::cout << "key of min is="<< itpt->node->key << " value is= "<< itpt->value;

  h = insert(&i3, 8,h);

}
