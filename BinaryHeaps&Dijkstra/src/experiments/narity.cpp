#include "../graph/graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "../dijkstra/dijkstra.h"


int main(int argc, char **argv) {
std::vector<unsigned> distances;


try {

  unsigned int o,g;
  o = 1;
  d = 12;
  Graph g = Graph(std::cin);
  distances = dijkstra(o,g,2);



 }catch (const char* msg) {
std::cout  << msg << std::endl; 
 }

std::cout << distances[d-1]<<"\n";

}
