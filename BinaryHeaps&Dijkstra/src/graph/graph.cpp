#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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

  unsigned last_key = 0;
  unsigned i=0;
  unsigned edges_index=0;
  while (i<m) {
    getline(inputF,line);
    if (line.substr(0,2) == "a ") {
      std::stringstream arc(line);
      unsigned u,v,w;
      char ac;
      arc >> ac >> u >> v >> w;
      if(last_key > u) {
	throw "edges in input file are not ordered according to origin vertex";
      }
      // processar arco (u,v) com peso w
      //origin vertex id is in u.
      unsigned int shift = vertexes[u-1].num_neigh;
      unsigned pos = edges_index + shift;
      edges[pos].destination_vertex_id = v -1;
      edges[pos].weight = w;
      vertexes[u-1].num_neigh++;
      if(shift == 0) {
	//is first neighbour added. must set pointer
	vertexes[u-1].first_neigh = edges + edges_index;
      }
     edges_index++;
      
      i++;
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
