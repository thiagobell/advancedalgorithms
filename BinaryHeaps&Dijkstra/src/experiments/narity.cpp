#include "../graph/graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "../dijkstra/dijkstra.h"
#include <chrono>
#include <cmath>

int main(int argc, char **argv) {
std::vector<unsigned> distances;


 unsigned int o,d;

 o = std::atoi(argv[1]);
 d = std::atoi(argv[2]);

 Graph g = Graph(std::cin);

 unsigned int min_n, max_n;
 min_n = 1;
 max_n = 6;
 
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

   std::cout << "n="<<i<<" time=" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() << std::endl;

 }

std::cout << distances[d-1]<<"\n";

}
