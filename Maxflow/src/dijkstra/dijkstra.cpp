#include "../nheap/nheap.h"
#include "../graph/graph.h"
#include "dijkstra.h"
#include <vector>
#include <limits>
#include <iostream>
#include <algorithm> 

Dijkstra::Dijkstra(unsigned s, unsigned t,Graph g, unsigned heap_arity)
{
  unsigned int num_visits=0;
  unsigned n_vertex = g.numVertexes();
  unsigned inf = std::numeric_limits<unsigned>::max();
  distance = std::vector<unsigned>(n_vertex,  inf);
  std::vector<bool > visited(n_vertex,  false);
  previous_vertex = std::vector<unsigned>(n_vertex,0); //previous vertex on fattest path to the respective vertex.
  distance[s-1] = inf;
  Nheap<unsigned int> heap(heap_arity, n_vertex);
  heap.insert(hnode<unsigned>(0,s));

  while(!heap.empty()) {
    hnode<unsigned> v_node = heap.delete_max();
    visited[v_node.id -1] = true;
    num_visits++;
    std::vector<Edge*> u_set = g.get_edges_from_vertex(v_node.id);
    for(unsigned i = 0; i < u_set.size();i++) {
			if(u_set[i]->get_forward()!= 0){
		    unsigned u_id = u_set[i]->destination_vertex_id;
		    unsigned weight = u_set[i]->get_forward();
		    if(!visited[u_id-1]) {
					unsigned distance_through_v = std::min(distance[v_node.id-1], weight);
					previous_vertex[u_id-1] = v_node.id;
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
	}

	found_path = visited[t-1];
	return;
}



