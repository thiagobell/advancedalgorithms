#include <iostream>
#include "hheap.h"

Node* Hheap::make_heap()
{
  return NULL;
}
Node* Hheap::make_heap(Item *item, unsigned int key)
{
  Node *n= new Node;
  n->item = item;
  n->key = key;
  n->fc = NULL;
  n->ns = n;
  n->rank = 0;
}

Node* Hheap::make_child(Node *winner, Node *loser);
Node* Hheap::link(Node *n1, Node *n2);
Node* Hheap::meld(Node *h1, Node *h1);


