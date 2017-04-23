/*
 * Header Definition of Hheap class. It implements the HollowHeap data structure
 *  based on https://arxiv.org/abs/1510.06535
 */

#include <iostream>

struct Item;
struct Node {
  Item *item;
  unsigned int key;
  Node *fc, *ns;
  unsigned int rank;
};

struct Item {
  Node *node;
  unsigned int value;
  Item(unsigned v){
    value = v;
  }
};

//points to the root with the lowest minimum key
//Node *minimum_node;

Node* make_heap();
Node* get_min(Node *h);
Item* find_min(Node *h);  
Node* insert(Item *item, unsigned key, Node *h);
Node* decrease_key(Item *item, unsigned key, Node *h);

Node* delete_item(Item *item, Node *h);
Node* delete_min(Node *h);


unsigned get_num_insert();
unsigned get_num_decrease_key();
unsigned get_num_delete_min();

bool heap_is_empty(Node *h);
