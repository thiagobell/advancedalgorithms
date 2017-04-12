#include "graph/graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "dijkstra/dijkstra.h"
#include <limits>

int main(int argc, char **argv) {
std::vector<unsigned> distances;
 if(argc < 3) {
   std::cout << "error: Expecting origin destination pair\n";
 }

 unsigned int o,d;
 o = std::atoi(argv[1]);
 d = std::atoi(argv[2]);
 
 Graph g = Graph(std::cin);
 distances = dijkstra(o,g,2);
 
 if(distances[d-1]==std::numeric_limits<int>::max()){
   std::cout << "inf\n";
 } else {
   std::cout << distances[d-1]<<"\n";
 }


}
