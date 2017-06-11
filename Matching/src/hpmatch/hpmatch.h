//implementation of the Hopcroft-Karp algorithm for bipartite graph matching

#ifndef H_HPMATCH
#define H_HPMATCH
#include <vector>
class Vertex {
 public:
  std::vector<unsigned> neigh;
  enum vertex_group {U,V};
  vertex_group group;
  int  matched_to;
  unsigned distance;
  Vertex(std::vector<unsigned> neighbours, vertex_group gr) {
    neigh = neighbours;
    group = gr;
    distance = 0;
    matched_to = -1;
  }
};

class HPmatch {
 public:
  int match();

};



#endif
