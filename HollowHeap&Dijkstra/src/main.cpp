#include "graph/graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "dijkstra/dijkstra.h"
#include <limits>
#include <string.h>

int main(int argc, char **argv) {
std::vector<unsigned> distances;
 if(argc < 3) {
   std::cout << "error: Expecting origin destination pair\n";
   return -1;
 }

 //processing input
 //optional parameters: -v print heap operations and time
 bool print_info= false;
 if(argc >= 4) {
   if(strncmp(argv[1], "-v",2)==0)
     print_info = true;
 }
 unsigned int o,d;
 if(print_info) {
   o = std::atoi(argv[2]);
   d = std::atoi(argv[3]);
 } else {
   o = std::atoi(argv[1]);
   d = std::atoi(argv[2]);
 }
 
 Graph g = Graph(std::cin);
 distances = dijkstra(o,g,2, print_info);
 if(distances[d-1]==std::numeric_limits<unsigned>::max()){
   std::cout << "inf\n";
 } else {
   std::cout << distances[d-1]<<"\n";
 }
}
