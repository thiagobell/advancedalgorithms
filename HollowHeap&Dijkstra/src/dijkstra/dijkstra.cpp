#include "../hheap/hheap.h"
#include "../graph/graph.h"
#include <vector>
#include <limits>
#include <iostream>
#include <chrono>
//returns the minimum cost departing from node with id s to every other node
std::vector<unsigned> dijkstra(unsigned s, Graph g, unsigned heap_arity, bool print_heap_op_count)
{
  std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
  unsigned int num_visits=0;
  unsigned n_vertex = g.numVertexes();
  unsigned inf = std::numeric_limits<unsigned>::max();
  std::vector<unsigned> distance(n_vertex,  inf);
  std::vector<bool > visited(n_vertex,  false);
  std::vector<Item*> items(n_vertex, NULL);
//  Node* heap = make_heap();
	HHeap heap;
  distance[s-1] = 0;
  
  //  heap.insert(hnode<unsigned>(0,s));
  items[s-1] = new Item(s);
  heap.insert(items[s-1], 0);
  while(!heap.empty()) {
    //    hnode<unsigned> v_node = heap.delete_min();
    Item *v_node = heap.find_min();
    heap.delete_min();
    visited[v_node->value -1] = true;
    num_visits++;    
    std::vector<unsigned> u_set = g.get_edges_from_vertex(v_node->value);
    for(unsigned i = 0; i < u_set.size()/2;i++) {
      unsigned u_id = u_set[i*2];
      unsigned weight = u_set[i*2+1];
      if(!visited[u_id-1]) {
	unsigned distance_through_v = distance[v_node->value-1] + weight;
	if(distance[u_id-1] == inf) {
	  distance[u_id-1] = distance_through_v;
	  items[u_id-1] = new Item(u_id);
	  heap.insert(items[u_id-1], distance_through_v);
	  //heap.insert(hnode<unsigned>(distance_through_v, u_id));
	} else if (distance_through_v < distance[u_id-1]) {
	  distance[u_id-1] = distance_through_v;
	  heap.decrease_key(items[u_id-1], distance_through_v);
	   
	  //heap.update_key(u_id, distance_through_v);
	}	
      }
    }
    
  }

  if(print_heap_op_count){
    std::cout << "time(ms)= " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count();
    std::cout << " num_insert " << heap.get_num_insert() << " num_deletemin "<< heap.get_num_delete_min() << " num_decreasekey "<< heap.get_num_decrease_key() << " num_nodes_visited " << num_visits<< "\n";
  } 
 	heap.~HHeap();
  return distance;
}


