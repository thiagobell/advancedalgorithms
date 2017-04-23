#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


struct temp_vertex{
  unsigned int id = 0;
  std::vector<unsigned int> neighbor_ids;
  std::vector<unsigned int> neighbor_weights;
  
  bool operator < (const temp_vertex& str) const
  {
    return (id < str.id);
  }

};

//file parsing based on:
//http://www.inf.ufrgs.br/~MRPRITT/doku.php?id=inf05016:2017-1-trabalhos
Graph::Graph(std::istream& inputF)
{

  std::string line="", dummy;
  while (line.substr(0,4) != "p sp")
    getline(inputF,line);
  
  std::stringstream linestr;
  linestr.str(line);
  linestr >> dummy >> dummy >> n >> m;

  //allocates memory
  vertexes = new Vertex[n];
  edges = new Edge[m];
  std::vector<temp_vertex> temp_(n);
  unsigned i=0;
  unsigned edges_index=0;
  while (i<m) {
    getline(inputF,line);
    if (line.substr(0,2) == "a ") {
      std::stringstream arc(line);
      unsigned u,v,w;
      char ac;
      arc >> ac >> u >> v >> w;
      // processar arco (u,v) com peso w
      temp_[u-1].id = u;
      temp_[u-1].neighbor_ids.push_back(v);
      temp_[u-1].neighbor_weights.push_back(w);
      i++;
    }
  }

  //sorting temporary vector
  std::sort(temp_.begin(), temp_.end());
  unsigned int edge_pointer = 0;
   
  for(int ind = 0; ind < n; ind++){
    vertexes[ind].num_neigh = temp_[ind].neighbor_ids.size();
    vertexes[ind].first_neigh = &edges[edge_pointer];
    for(int edg_in=0; edg_in < temp_[ind].neighbor_ids.size(); edg_in++) {
      edges[edge_pointer].destination_vertex_id = temp_[ind].neighbor_ids[edg_in];
      edges[edge_pointer].weight = temp_[ind].neighbor_weights[edg_in];
      edge_pointer++;
    }
  }

}

unsigned Graph::numVertexes()
{
  return n;
}

unsigned Graph::numEdges()
{
  return m;
}

std::vector<unsigned> Graph::get_edges_from_vertex(unsigned id)
{

  unsigned num_neigh = vertexes[id-1].num_neigh;
  Edge *edg = vertexes[id-1].first_neigh;
  std::vector<unsigned> results(num_neigh*2);
  for(unsigned i=0;i < num_neigh; i++) {
    results[i*2] = (edg + i)->destination_vertex_id;
    results[i*2+1] = (edg + i)->weight;
  }
  
  return results;
}
