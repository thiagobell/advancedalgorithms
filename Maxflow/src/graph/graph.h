#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <sstream>
struct Vertex;
class Edge {
		public:
			unsigned source_vertex_id;
		  unsigned destination_vertex_id;
		  unsigned capacity, flow;
			unsigned get_forward(){return capacity-flow;};
			unsigned get_backward(){return flow;};
			void increment_flow(unsigned delta){flow = flow + delta;};
   };

struct Vertex {
		std::vector<Edge*> edges;
   };


class Graph {
  private:
  unsigned int n, m;
   Edge *edges;
   Vertex *vertexes;

  public:
   unsigned s,t;
   Graph(std::istream& input);
   unsigned numVertexes();
   unsigned numEdges();
   void increment_flow_on_edge(unsigned source, unsigned destination, unsigned delta);
   std::vector<Edge*> get_edges_from_vertex(unsigned id);
};
#endif
