#include <iostream>
#include "hheap.h"
#include <cmath>
#include <cstring>

Node* min_root=NULL;
unsigned num_full_nodes = 0;
unsigned num_all_nodes = 0;
double const phi = (1 + std::sqrt(5))/2;

Node* link(Node *n1, Node *n2){
  if(n1->key <= n2->key){
    return make_child(n1,n2);
  } else {
    return make_child(n2,n1);
  }
}

Node* make_child(Node *winner, Node *loser) {
  loser->ns = winner->fc;
  winner->fc = loser;
  ( winner->rank)++;
  return winner;
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
  std::swap(h1->ns, h2->ns);
  if(h1->key <= h2->key)
    return h1;
  else
    return h2;
}

Node* insert(Item *item, unsigned key, Node* h){
  return meld(make_heap(item,key), h);
}

void decrease_key(Item *item, unsigned key, Node* h){
  Node *u = item->node;
  Node *v = make_heap(item, key);
  v->rank = std::max(0, int(u->rank) -2);
  if(u->rank >= 2) {
    v->fc = u->ns->ns;
    u->ns->ns = NULL;
  }
}

void link_heap(Node *h, Node **r_vec) {
  if(h->item == NULL) {
    Node* r = h->fc;
    do{
      Node *rn = r->ns;
      link_heap(r, r_vec);
      r = rn;
    }while(r != NULL);
    delete h;
  } else {
    unsigned i = h->rank;
    while(r_vec[i] != NULL){
      h = link(h, r_vec[i]);
      r_vec[i] = NULL;
      i++;
    }
    r_vec[i] = h;
  }

}


Node* delete_min(Node *h){
  if(h == NULL)
    return NULL;
  h->item = NULL;  
  num_full_nodes--;
  unsigned M = ceil(log(num_full_nodes)/log(phi));
  Node** r_vec =  new Node *[M];
  memset(r_vec, 0, M*sizeof(Node*));

  Node* r = h;
  Node* rn;
  do {
    rn = r->ns;
    link_heap(r,r_vec);
    r = rn;
  } while(r != h);
    
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
  else
    return h->item;
}



