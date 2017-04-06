#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <sstream>
struct Vertex;
struct Edge {
    unsigned destination_vertex_id;
    unsigned weight;
   };

struct Vertex {
    unsigned num_neigh = 0;
    Edge *first_neigh;
   };


class Graph {
  private:
  unsigned int n, m;
   Edge *edges;
   Vertex *vertexes;

  public:
   
   Graph(std::istream& input);
   unsigned numVertexes();
   unsigned numEdges();
   std::vector<unsigned> get_edges_from_vertex(unsigned id);
};
#endif
