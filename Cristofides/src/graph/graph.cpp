#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>

double Graph::distance_between(unsigned n1, unsigned n2) {
  double deltax = abs(vertex_coordinates[n1*2] - vertex_coordinates[n2*2]);
  double deltay = abs(vertex_coordinates[n1*2]+1 - vertex_coordinates[n2*2]);
  return sqrt( pow(deltax,2) + pow(deltay,2) );
}

//creates a Minimum Spanning Tree
std::vector<unsigned> Graph::gen_mst()
{
  std::sort(edges.begin(), edges.end());
  bool *visited = new bool[n];
  std::memset(visited, false, sizeof(bool)*n);
  std::vector<unsigned> node_degrees;
  node_degrees.reserve(n);
  for(unsigned i = 0; i < n; i++) {
    node_degrees.push_back(0);
  }
  unsigned num_visited = 0;
  unsigned curr_edge = 0;
  while(num_visited < n){
    unsigned n1, n2;
    n1 = edges[curr_edge].n1;
    n2 = edges[curr_edge].n1;
    if(visited[n1] == false || visited[n2]==false){
      edges[curr_edge].selected = true;
      node_degrees[n1] = node_degrees[n1] +1;
      node_degrees[n2] = node_degrees[n2] +1;
      if(visited[n1]== false && visited[n2]==false)
        num_visited= num_visited +2;
      else
        num_visited = num_visited +1;
      visited[n1] = true;
      visited[n2] = true;
    }
    curr_edge++;
  }
  return node_degrees;
}

//file parsing based on:
//http://www.inf.ufrgs.br/~MRPRITT/doku.php?id=inf05016:2017-1-trabalhos
Graph::Graph(std::istream& inputF)
{

  std::string line="", dummy;

  while (line.substr(0,10) != "DIMENSION:")
    getline(inputF,line);

    std::stringstream linestr;
    linestr.str(line);
    linestr >> dummy >> n;
    m = n*(n-1);

  while (line.substr(0,18) != "NODE_COORD_SECTION")
    getline(inputF,line);

  vertex_coordinates.reserve(n*2);
  unsigned i=0;
  while (i<n) {
    getline(inputF,line);

    std::stringstream arc(line);
    unsigned node;
    double x, y;
    arc >> node >> x >> y;
    vertex_coordinates.push_back(x);
    vertex_coordinates.push_back(y);

    i++;
  }
  edges.reserve(m);
  //calculate distances
  for(unsigned j=0; j<n; j++){
    for(unsigned k=j+1; k<n; k++){
      Edge e;
      e.n1 = j;
      e.n2 = k;
      e.distance = distance_between(j,k);
      edges.push_back(e);
    }
  }
}
