#include "graph/graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "dijkstra/dijkstra.h"


int main() {
 try {
  Graph g = Graph(std::cin);
  std::vector<unsigned> distances = dijkstra(1,g);
 }catch (const char* msg) {
std::cout  << msg << std::endl; 
 }
  
}
