#include<iostream>
#include "../graph/graph.h"
#include "../graph/generate_graph.h"
#include "../dijkstra/dijkstra.h"
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <fstream>

int main() {

  unsigned int max_i =29;
  unsigned int expo = 15;//15;
  unsigned int n = std::pow(2, expo);
  std::cout << "#n = 2^"<<expo<<"="<< n <<"\n";
  
  for(int i =15; i<=max_i;i++) {
    double p = std::pow(2,i) /(std::pow(2,expo*2)-std::pow(2,expo));
    std::cout <<"----------------------\n";
    
    //generating graph
    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
    generate_graph(n,p,"/tmp/graph.file");
    std::cout << "time to generate graph(ms)= " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count()<<"\n";
    
    std::ifstream inputfile;
    inputfile.open("/tmp/graph.file");
    Graph g(inputfile);
    std::cout << "i = "<< i<<" m =  "<< g.numEdges() <<"\n";
    std::srand(std::time(0));
    //runs dijkstra's 30 times
    for(unsigned j =0; j < 30; j++) {
      //choose random source vertex
      unsigned int s = std::rand() % g.numVertexes()+1;
      std::cout <<"run# "<< j+1 << " origin vertex "<< s;
      std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
      dijkstra(s,g,true);
      std::cout << " time(ms)= " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count();
      std::cout << "\n";
      
    }
  }
}
