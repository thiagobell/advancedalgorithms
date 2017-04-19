#include <iostream>
#include "hheap.h"

int main(){
  
  Node *h = NULL;
  Item meuitem;
  meuitem.value = 111;
  h = insert(&meuitem, 2, h);
  h = delete_min(h);

}
