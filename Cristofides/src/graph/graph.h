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
  /* whether this edge is part of MST or path*/
  bool selected = false;
  bool operator<(const Edge& rhs){
    return distance < rhs.distance;
  }
  static bool less_than_pointer(const Edge* lhs, const Edge* rhs)
  {
    return lhs->distance < rhs->distance;
  }
};

class Graph {
  public:
   unsigned n, m;
   Graph(std::istream& input);
   std::vector<double> vertex_coordinates;

   //stores pointers to edges structs so that they can be
    // accessed based on the specific nodes
   //accessed as [smallerID][largerID-smallerID-1]
   std::vector<std::vector<Edge*> > edges_vertex;

   //resets selected variable of each edge to false
   void reset_selected();

   //distance inforation stored this way so that the vector can be sorted
   //for generating the MST
   std::vector<Edge> edges;
   std::vector<Edge*> edges_pt;
  
   //sum of the weights of the selected edges on MST.
   double selected_edges_weight;

   double distance_between(unsigned n1, unsigned n2);
   //returns vector with edges (endpoint1, endpoint2, enpoint1, endpoint2..)
   std::vector<unsigned> gen_mst();
};
#endif
