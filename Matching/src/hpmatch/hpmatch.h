//implementation of the    for bipartite graph matching
//based on pseudocode from https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm

#ifndef H_HPMATCH
#define H_HPMATCH
#include <vector>
#include "../graph/graph.h"


class HPmatch {
 public:
  static int match(std::vector<Vertex> U, std::vector<Vertex> V);
};



#endif
