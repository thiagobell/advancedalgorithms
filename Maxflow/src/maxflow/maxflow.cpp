#include "maxflow.h"
#include "../graph/graph.h"
#include "../dijkstra/dijkstra.h"
#include <iostream>

unsigned maxflow(Graph g)
{
  unsigned s,t;
  s = g.s;
  t = g.t;
  unsigned iterations = 0;
	bool path_exists = true;
	while(path_exists) {
		//calculate fattest path with modified dijkstra's algorithm
		Dijkstra dj(s, t,g,2);
		if(dj.found_path) {
      iterations++;
			unsigned fat_bottleneck = dj.get_distances()[t-1]; //fattest bottleneck
      if(fat_bottleneck == 0)
        path_exists = false;
			//scans path and update edges
			std::vector<unsigned> paths = dj.get_paths();
			unsigned u = paths[t-1]; // origin
			unsigned v = t; // destination

      while(u != 0) {
        g.increment_flow_on_edge(u,v, fat_bottleneck);

        v = u;
        u = paths[v-1];
      }
		}
		else
			path_exists=false;
	}

	//summing individual paths...
	std::vector<Edge*> edges = g.get_edges_from_vertex(s);
	unsigned sum=0;
	for(unsigned i=0; i < edges.size(); i++){
			sum = sum + edges[i]->flow;
	}
  //std::cout << "num iterations: " << iterations << " ";
	return sum;
}
