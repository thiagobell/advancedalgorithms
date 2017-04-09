#include "../graph/graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "../dijkstra/dijkstra.h"
#include <chrono>

int main(int argc, char **argv) {
std::vector<unsigned> distances;

if(argc < 3) {
std::cout << "error: Expecting origin destination pair\n";
}

 std::chrono::system_clock::time_point t = std::chrono::system_clock::now();

 cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count() << endl;

 unsigned int o,d;

 o = std::atoi(argv[1]);
 d = std::atoi(argv[2]);

 Graph g = Graph(std::cin);
 distances = dijkstra(o,g);

  
  try {

 }catch (const char* msg) {
std::cout  << msg << std::endl; 
 }

std::cout << distances[d-1]<<"\n";

}
