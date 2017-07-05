#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <sstream>
#include <cassert>
struct Vertex;
class Edge {
		public:
			unsigned source_vertex_id;
		  unsigned destination_vertex_id;
		  unsigned capacity, flow;
			unsigned get_forward(){return capacity-flow;};
			unsigned get_backward(){return flow;};
			void increment_flow(unsigned delta){
				assert(delta >= 0);
				flow = flow + delta;};
   };

struct Vertex {
		std::vector<Edge*> edges;
   };


class Graph {
  private:

   Edge *edges;
   Vertex *vertexes;

  public:
   unsigned s,t;
	 unsigned int n, m;
   Graph(std::istream& input);
   unsigned numVertexes();
   unsigned numEdges();
   void increment_flow_on_edge(unsigned source, unsigned destination, unsigned delta);
   std::vector<Edge*> get_edges_from_vertex(unsigned id);
};
#endif
