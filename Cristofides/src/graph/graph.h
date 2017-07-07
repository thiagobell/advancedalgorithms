#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>

struct Edge {
  /* n1 and n2 are node indexes. n1<n2*/
  unsigned n1, n2;
  double distance;
  /* whether this edge is part of MST*/
  bool selected = false;
  /*sum of selected edges*/
  double weight_selected_edges;
  bool operator<(const Edge& rhs){
    return distance < rhs.distance;
  }
};

class Graph {
  public:
   unsigned n, m;
   Graph(std::istream& input);
   std::vector<double> vertex_coordinates;

   //distance inforation stored this way so that the vector can be sorted
   //for generating the MST
   std::vector<Edge> edges;

   //sum of the weights of the selected edges.
   double selected_edges_weight;

   double distance_between(unsigned n1, unsigned n2);
   //returns vector with edges (endpoint1, endpoint2, enpoint1, endpoint2..)
   std::vector<unsigned> gen_mst();
};
#endif
