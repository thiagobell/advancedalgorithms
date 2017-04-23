#include <iostream>
#include "hheap.h"
#include <cmath>
#include <cstring>

Node* min_root=NULL;
unsigned num_full_nodes = 0;
unsigned num_all_nodes = 0;
unsigned num_inserts = 0;
unsigned num_decrease_key = 0;
unsigned num_delete_min = 0;
double const phi = (1 + std::sqrt(5))/2;

unsigned get_num_insert() {return num_inserts;}
unsigned get_num_decrease_key() {return num_decrease_key;}
unsigned get_num_delete_min() {return num_delete_min;}

bool heap_is_empty(Node *h){
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


Node* link(Node *n1, Node *n2){
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
Node* make_heap(Item *item, unsigned int key)
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

Node* meld(Node *h1, Node *h2) {
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

Node* insert(Item *item, unsigned key, Node* h){
  num_inserts++;
  return meld(make_heap(item,key), h);
}


Node* decrease_key(Item *item, unsigned key, Node* h){
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

  return meld(v,h);

}

void link_heap(Node *h, Node **r_vec) {
  
  if(h->item == NULL) {
    Node* r = h->fc;
    while(r != NULL){
      Node *rn = r->ns;
      link_heap(r, r_vec);
      r = rn;
    }
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


Node* delete_min(Node *h){
  num_delete_min++;
  if(h == NULL)
    return NULL;
  h->item = NULL;  
  num_full_nodes--;
  unsigned M = ceil(log(num_full_nodes)/log(phi));
  Node** r_vec =  new Node *[M+1];
  memset(r_vec, 0, (M+1)*sizeof(Node*));
  
  Node* r = h;
  Node* rn;
  do {
    if(r == NULL)
      std::cout<< "PROBLEM\n";
    rn = r->ns;
    link_heap(r,r_vec);
    r = rn;
  } while(r != h);

  h = NULL;
  for(unsigned i = 0; i <= M; i++) {
    if(r_vec[i] != NULL) {
      r_vec[i]->ns = r_vec[i];
      h = meld(h, r_vec[i]);
    }
  }
  return h;
  
  /*
  unsigned i = 0;
  while(i <= M && r_vec[i]==NULL){
    i++;
  }
  if(i>M)
    return NULL;
  h = r_vec[i];
  h->ns = h;
  while(i < M){
    r_vec[i]->ns = r_vec[i];
    h = meld(h, r_vec[i]);
    i++;
  }
  return h;
  */
}


Node* delete_item(Item *item, Node *h){
  item->node->item = NULL;
  if(item->node == h) {
    //is min
    return delete_min(h);
  } else {
    num_full_nodes--;
    return h;
  }
}

Node* get_min(Node *h){
  return h;
}

Item* find_min(Node *h){
  if(h==NULL)
    return NULL;
  else {
    return h->item;
  }
}



