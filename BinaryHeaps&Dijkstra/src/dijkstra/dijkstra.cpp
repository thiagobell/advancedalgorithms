#include "../nheap/nheap.h"
#include "../graph/graph.h"
#include <vector>
#include <limits>
#include <iostream>

//returns the minimum cost departing from node with id s to every other node
std::vector<unsigned> dijkstra(unsigned s, Graph g)
{
  unsigned n_vertex = g.numVertexes();
  unsigned inf = std::numeric_limits<int>::max();
  std::vector<unsigned> distance(n_vertex,  inf);
  std::vector<bool > visited(n_vertex,  false);

  Nheap<unsigned int> heap(2, n_vertex);
  heap.insert(hnode<unsigned>(0,s));
  if(heap.data.size() == 0) {
    std::cout <<"PROBLEM!!!!!\n";
  } else {
    std::cout << "not empty\n";
  }

  
  while(!heap.empty()) {
    hnode<unsigned> v_node = heap.delete_min();
    std::cout << "read node " << v_node.id << std::endl;
    visited[v_node.id -1] = true;

    //vector is destination weight destination weight ...
    std::vector<unsigned> u_set = g.get_edges_from_vertex(v_node.id);
    for(unsigned i = 0; i < u_set.size()/2;i++) {
      unsigned key = u_set[i*2];
      unsigned weight = u_set[i*2+1];

      if(!visited[key-1]) {
	unsigned distance_through_v = distance[v_node.id-1] + weight;
	if(distance[key-1] == inf) {
	  distance[key-1] = distance_through_v;
	  heap.insert(hnode<unsigned>(distance_through_v, key));
	} else if (distance_through_v < distance[key-1]) {
	  distance[key-1] = distance_through_v;
	  heap.update_key(key-1, distance_through_v);
	 
	}
	
      }
    }
    
  }
  return distance;
  
  
}


