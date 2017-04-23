#include <iostream>
#include "hheap.h"
#include <cmath>
#include <cstring>

double const phi = (1 + std::sqrt(5))/2;

unsigned HHeap::get_num_insert() {return num_inserts;}
unsigned HHeap::get_num_decrease_key() {return num_decrease_key;}
unsigned HHeap::get_num_delete_min() {return num_delete_min;}
unsigned HHeap::get_num_melds() {return num_melds;}
unsigned HHeap::get_num_nodes_created() {return num_nodes_created;}
unsigned HHeap::get_num_nodes_destroyed() {return num_nodes_destroyed;}
unsigned HHeap::get_num_links() {return num_links;}

bool HHeap::empty(){
  if(num_full_nodes > 0)
    return false;
  return true;
}

Node* make_child(Node *winner, Node *loser) {
  loser->ns = winner->fc;
  winner->fc = loser;
  ( winner->rank)++;
  return winner;
}


Node* HHeap::link(Node *n1, Node *n2){
	num_links++;
  if(n1->key <= n2->key){
    return make_child(n1,n2);
  } else {
    return make_child(n2,n1);
  }
}


Node* make_heap()
{
  return NULL;
}
Node* HHeap::make_heap(Item *item, unsigned int key)
{
  Node *n= new Node;
  n->item = item;
  item->node = n;
  n->key = key;
  n->fc = NULL;
  n->ns = n;
  n->rank = 0;
  num_all_nodes++;
  num_full_nodes++;
  return n;
}

Node* HHeap::meld(Node *h1, Node *h2) {
	num_melds++;
  if(h1 == NULL)
    return h2;
  if(h2 == NULL)
    return h1;
  if(h2->ns == NULL) {
    std::cout << "meld: h2 has null ns\n";
  }
  if(h1->ns == NULL) {
    std::cout << "meld: h1 has null ns\n";
  }
  std::swap(h1->ns, h2->ns);
  if(h1->key <= h2->key)
    return h1;    
  else 
    return h2;
}

void HHeap::insert(Item *item, unsigned key){
  num_inserts++;
  min_root = meld(make_heap(item,key), min_root);
}


void HHeap::decrease_key(Item *item, unsigned key){
  num_decrease_key++;
  Node *u = item->node;
  u->item = NULL;
  num_full_nodes--;
  Node *v = make_heap(item, key);
  v->rank = std::max(0, int(u->rank) -2);
  if(u->rank >= 2) {
    v->fc = u->fc->ns->ns;
    u->fc->ns->ns = NULL;
    u->rank = 2;
  }

  min_root = meld(v,min_root);

}

void HHeap::link_heap(Node *h, Node **r_vec) {
  
  if(h->item == NULL) {
    Node* r = h->fc;
    while(r != NULL){
      Node *rn = r->ns;
      link_heap(r, r_vec);
      r = rn;
    }
		num_nodes_destroyed++;
    delete h;
  } else {
    unsigned i = h->rank;
    unsigned M = ceil(log(num_full_nodes)/log(phi));
    while(r_vec[i] != NULL && i <= M ){
      h = link(h, r_vec[i]);
      r_vec[i] = NULL;
      i++;
    }
    r_vec[i] = h;
  }

}


void HHeap::delete_min(){
  num_delete_min++;
  if(min_root == NULL)
    return;
  min_root->item = NULL;  
  num_full_nodes--;
  unsigned M = ceil(log(num_full_nodes)/log(phi));
  Node** r_vec =  new Node *[M+1];
  memset(r_vec, 0, (M+1)*sizeof(Node*));
  
  Node* r = min_root;
  Node* rn;
  do {
    if(r == NULL)
      std::cout<< "PROBLEM\n";
    rn = r->ns;
    link_heap(r,r_vec);
    r = rn;
  } while(r != min_root);

  min_root = NULL;
  for(unsigned i = 0; i <= M; i++) {
    if(r_vec[i] != NULL) {
      r_vec[i]->ns = r_vec[i];
      min_root = meld(min_root, r_vec[i]);
    }
  }
}


void HHeap::delete_item(Item *item){
  item->node->item = NULL;
  if(item->node == min_root) {
    //is min
    delete_min();
  } else {
    num_full_nodes--;
  }
}

Node* HHeap::get_min(){
  return min_root;
}

Item* HHeap::find_min(){
  if(min_root==NULL)
    return NULL;
  else {
    return min_root->item;
  }
}



