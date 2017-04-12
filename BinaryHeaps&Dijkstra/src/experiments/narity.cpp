#include "../graph/graph.h"
#include "../graph/generate_graph.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include "../dijkstra/dijkstra.h"
#include <chrono>
#include <cmath>

void gen_net(unsigned num_nodes,unsigned num_edges, const char* path) {
  //  unsigned m = std::pow(2,2*n_exp)-std::pow(2,n_exp);
  double p = ((double)num_edges) / (num_nodes*(num_nodes-1));
  std::cout << "p at gen"<< p;
  generate_graph(num_nodes,p,path);
}

int main(int argc, char **argv) {
  std::vector<unsigned> distances;

  std::srand(std::time(0));

  unsigned int min_num_node = 15;
  unsigned int max_num_node = 17;
  for(int node_num=min_num_node;node_num<=max_num_node;node_num++) {
    unsigned num_node = std::pow(2,node_num);
    unsigned num_edge = num_node * node_num/2;
    gen_net(num_node,num_edge , "/tmp/narity_test.graph");
    unsigned int o;
    std::ifstream inputfile;
    inputfile.open("/tmp/narity_test.graph");
    Graph g = Graph(inputfile);
    //choose random source vertex
    o = std::rand() % g.numVertexes()+1;
    unsigned int min_n, max_n;
    min_n = 1;
    max_n = 6;
    std::cout << "------------------\n";
    std::cout << "num nodes "<< g.numVertexes() <<" num edges "<< g.numEdges()<<"\n"; 
    for(unsigned p=min_n; p <=max_n; p++) {
      unsigned i = std::pow(2,p);
   
      std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
      distances = dijkstra(o,g, i);
      /*
	distances = dijkstra(o,g, i);   
	distances = dijkstra(o,g, i);   
	distances = dijkstra(o,g, i);   
   distances = dijkstra(o,g, i);   
   distances = dijkstra(o,g, i);   
   distances = dijkstra(o,g, i);   
   distances = dijkstra(o,g, i);   
   distances = dijkstra(o,g, i);   
   distances = dijkstra(o,g, i);   
   distances = dijkstra(o,g, i);   
   distances = dijkstra(o,g, i);   
   */

   std::cout << " n="<<i<<" time=" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() << std::endl;

 }
 


    
  }



}
