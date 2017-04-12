#include "../nheap/nheap.h"
#include "../graph/graph.h"
#include <vector>
#include <limits>
#include <iostream>

//returns the minimum cost departing from node with id s to every other node
std::vector<unsigned> dijkstra(unsigned s, Graph g, unsigned heap_arity)
{
  unsigned int num_visits=0;
  unsigned n_vertex = g.numVertexes();
  unsigned inf = std::numeric_limits<int>::max();
  std::vector<unsigned> distance(n_vertex,  inf);
  std::vector<bool > visited(n_vertex,  false);
  distance[s-1] = 0;
  Nheap<unsigned int> heap(heap_arity, n_vertex);
  heap.insert(hnode<unsigned>(0,s));

  while(!heap.empty()) {
    hnode<unsigned> v_node = heap.delete_min();
    visited[v_node.id -1] = true;
    num_visits++;
    std::vector<unsigned> u_set = g.get_edges_from_vertex(v_node.id);
    for(unsigned i = 0; i < u_set.size()/2;i++) {
      unsigned u_id = u_set[i*2];
      unsigned weight = u_set[i*2+1];
      if(!visited[u_id-1]) {
	unsigned distance_through_v = distance[v_node.id-1] + weight;
	if(distance[u_id-1] == inf) {
	  distance[u_id-1] = distance_through_v;
	  heap.insert(hnode<unsigned>(distance_through_v, u_id));
	} else if (distance_through_v < distance[u_id-1]) {
	  distance[u_id-1] = distance_through_v;
	  heap.update_key(u_id, distance_through_v);
	}	
      }
    }
    
  }
  std::cout << "#insert "<< heap.num_insert << " #deletemin "<< heap.num_deletemin << " #update " << heap.num_update << " #swap "<< heap.num_swaps<< " #nodes_visited" << num_visits;
  return distance;
}


