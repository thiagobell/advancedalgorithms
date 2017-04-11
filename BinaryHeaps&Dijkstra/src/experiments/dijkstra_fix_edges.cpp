#include<iostream>
#include "../graph/graph.h"
#include "../graph/generate_graph.h"
#include "../dijkstra/dijkstra.h"
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <fstream>

int main() {

  unsigned int max_i = 15 ; //n = 2^i
  unsigned int min_i = 7;
  unsigned int expo = 20; // m = 2^expo

  std::cout << "Dijkstra Performance Test -- fixed vertex number\n";
  std::cout << "m = 2^"<<expo<<"\n";
  
  for(int i =min_i; i<=max_i;i++) {
  double p = std::pow(2,expo) /(std::pow(2,i*2)-std::pow(2,i));
  std::cout <<"----------------------\n";
  std::cout << "i = "<< i<<"\n";
  std::cout << "p = "<<p<<"\n";
  //generating graph
  generate_graph(n,p,"/tmp/graph.file");
  std::cout << "graph generated\n";
  std::ifstream inputfile;
  inputfile.open("/tmp/graph.file");
  Graph g(inputfile);

  std::srand(std::time(0));
  //runs dijkstra's 30 times
  for(unsigned j =0; j < 30; j++) {
    //choose random source vertex
    unsigned int s = std::rand() % g.numVertexes()+1;
    std::cout << "i value "<<i<<" run# "<< j+1 << " origin vertexes "<< s;
    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
    dijkstra(s,g,2);
    std::cout << " time=" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count();
    std::cout << "\n";
  }
  }
}
