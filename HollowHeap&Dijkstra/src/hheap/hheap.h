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
	Item() {}
};

//points to the root with the lowest minimum key
//Node *minimum_node;
class HHeap {
public:
unsigned num_full_nodes = 0;
unsigned num_all_nodes = 0;
unsigned num_inserts = 0;
unsigned num_decrease_key = 0;
unsigned num_delete_min = 0;

unsigned num_melds = 0;
unsigned num_nodes_created = 0;
unsigned num_nodes_destroyed = 0;
unsigned num_links = 0;


//Node* make_heap();
 void genDot(std::string path);
Node* get_min();
Item* find_min();
~HHeap();
void insert(Item *item, unsigned key);
void decrease_key(Item *item, unsigned key);

void delete_item(Item *item);
void delete_min();

unsigned get_num_insert();
unsigned get_num_decrease_key();
unsigned get_num_delete_min();
unsigned get_num_melds();
unsigned get_num_nodes_created();
unsigned get_num_nodes_destroyed();
unsigned get_num_links();
bool empty();
private:
void link_heap(Node *h, Node **r_vec, unsigned M);
Node* min_root=NULL; 
Node* link(Node *n1, Node *n2);
Node* make_heap(Item *item, unsigned int key);
Node* meld(Node *h1, Node *h2);
void dealloc_subtree(Node *h);
};

