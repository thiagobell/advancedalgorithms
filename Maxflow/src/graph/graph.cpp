#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


//file parsing based on:
//http://www.inf.ufrgs.br/~MRPRITT/doku.php?id=inf05016:2017-1-trabalhos
Graph::Graph(std::istream& inputF)
{

  std::string line="", dummy;
  while (line.substr(0,5) != "p max")
    getline(inputF,line);
  std::stringstream linestr;
  linestr.str(line);
  linestr >> dummy >> dummy >> n >> m;

  //allocates memory
  vertexes = new Vertex[n];
  edges = new Edge[m];


  unsigned i=0;
  while (i<m) {
    getline(inputF,line);
    if (line.substr(0,2) == "a ") {
      std::stringstream arc(line);
      unsigned u,v,w;
      char ac;
      arc >> ac >> u >> v >> w;
      // processar arco (u,v) com peso w
			edges[i].source_vertex_id = u;
			edges[i].destination_vertex_id = v;
		  edges[i].capacity = w;
			edges[i].flow = 0;
			vertexes[u-1].edges.push_back(&edges[i]);
			vertexes[v-1].edges.push_back(&edges[i]);
      i++;
    }
    else if(line.substr(0,2) == "n ") {
      std::stringstream arc(line);
      unsigned node;
      char dummy, name;
      arc >> dummy >> node >> name;
      //m++;
      //i++;
      if(name == 's') //source
        s = node;
      else if(name = 't')
        t = node;
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

std::vector<Edge*> Graph::get_edges_from_vertex(unsigned id)
{
	std::vector<Edge*> edges_into_vertex;
	for(unsigned i=0; i < vertexes[id-1].edges.size();i++){
		if(vertexes[id-1].edges[i]->source_vertex_id == id)
			edges_into_vertex.push_back(vertexes[id-1].edges[i]);
	}
  return edges_into_vertex;
}

void Graph::increment_flow_on_edge(unsigned source, unsigned destination, unsigned delta){
	for(unsigned i=0; i < vertexes[source-1].edges.size();i++){
		if(vertexes[source-1].edges[i]->source_vertex_id == source && vertexes[source-1].edges[i]->destination_vertex_id == destination)
			vertexes[source-1].edges[i]->increment_flow(delta);
	}


}
