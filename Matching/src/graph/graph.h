#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>


class Vertex {
 public:
  std::vector<unsigned> neigh;
  int  matched_to;
  unsigned distance;
  Vertex(std::vector<unsigned> neighbours) {
    neigh = neighbours;
    matched_to = 0;
  }
  Vertex(){
    matched_to = 0;
  }
};

class Graph {
  public:
   unsigned n, m;
   std::vector<Vertex> U,V;
   Graph(int n, double p);
   Graph(std::istream& input);

};
#endif
