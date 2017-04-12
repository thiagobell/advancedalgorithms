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
};


class Hheap {
 private:
  //points to the root with the lowest minimum key
  Node *minimum_node;


  Node* make_child(Node *winner, Node *loser);
  Node* link(Node *n1, Node *n2);
  Node* meld(Node *h1, Node *h1);

  


 public: 
  Hheap();
  Item* get_min(){
    return minimum_node->item;
  }
  Item* find_min(){
    if(minimum_node==NULL)
      return NULL;
    else
      return minimum_node.item;
  }
  
  /*insert();
  decrease_key();
  delete();
  delete_min();*/
};
