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
    std::cout << "1\n";
    //vector is destination weight destination weight ...
    std::vector<unsigned> u_set = g.get_edges_from_vertex(v_node.id);
    std::cout << "2\n";
    std::cout << "uset size " << u_set.size()/2 << "\n";
    for(unsigned i = 0; i < u_set.size()/2;i++) {
      std::cout << "3.1\n";
      unsigned u_id = u_set[i*2];
      unsigned weight = u_set[i*2+1];
      std::cout << "id is "<< u_id << "weight is" << weight <<"\n";

      std::cout << "3.2\n";
      if(!visited[u_id-1]) {
	std::cout << "3.2.1\n";
	unsigned distance_through_v = distance[v_node.id-1] + weight;
	std::cout << "3.3\n";
	if(distance[u_id-1] == inf) {
	  std::cout << "3.3a\n";
	  distance[u_id-1] = distance_through_v;
	  heap.insert(hnode<unsigned>(distance_through_v, u_id));
	} else if (distance_through_v < distance[u_id-1]) {
	  std::cout << "3.3b\n";
	  distance[u_id-1] = distance_through_v;
	  heap.update_key(u_id-1, distance_through_v);
	 
	}
	
      }
      std::cout << "3.4\n";
    }
    
  }
  return distance;
  
  
}


