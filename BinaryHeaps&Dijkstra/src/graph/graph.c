#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>

struct temp_vertex{
  unsigned int id = 0;
  std::vector<unsigned int> neighbor_ids;
  std::vector<unsigned int> neighbor_weights;

  bool operator > (const temp_vertex& str) const
  {
    return (id > str.id);
  }

}


//http://www.inf.ufrgs.br/~MRPRITT/doku.php?id=inf05016:2017-1-trabalhos
Graph::Graph(std::string input_file)
{
  std::ifstream inputF(input_file);
  if(!inputF.is_open()) {
    //error
    throw "error opening file";
  }
  std::string line="", dummy;
  while (line.substr(0,4) != "p sp")
    getline(in,line);
  
  std::stringstream linestr;
  linestr.str(line);
  linestr >> dummy >> dummy >> n >> m;

  //allocates memory
  vertexes = new Vertex[n];
  edges = new Edge[m];
  temp_vertex temp_ = new temp_vetex[n];

  unsigned i=0;
  while (i<m) {
    getline(in,line);
    if (line.substr(0,2) == "a ") {
      std::stringstream arc(line);
      unsigned u,v,w
      char ac;
      arc >> ac >> u >> v >> w;
      // processar arco (u,v) com peso w
      temp_[u].neighbor_ids.push_back(v);
      temp_[u].neighbor_weights.push_back(w);
      i++;
    }
  }

  //sorting temporary vector
  std::sort(temp_.begin(), temp_.end(),greater<temp_vertex>());
  unsigned_int edge_pointer = 0;

  for(int ind = 0; ind < temp_.size(); temp_++){
    vertexes[ind].num_neigh = temp_[ind].neighbor_ids.size();
    vertexes[ind].first_neigh = edges + edge_pointer;
    for(int edg_in; edg_in < temp_[ind].neighbor_ids.size(); edg_in++) {
      edges[edge_pointer].source = vertexes + temp_.id - 1;
      edges[edge_pointer].destination = vertexes + temp[ind].neighbor_ids[edge_in]-1;
      edges[edge_pointer].weight = temp[ind].neighbor_weights[edge_in];
      edge_pointer++;
    }

  }

}


}


void read_dimacs(std::istream& in, unsigned& n, unsigned& m, MyGraph& a) {
  std::string line="", dummy;
  
  a.resize(n);
}

