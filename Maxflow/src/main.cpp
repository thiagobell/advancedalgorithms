#include "graph/graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "maxflow/maxflow.h"
#include <limits>


int main(int argc, char **argv) {
 std::vector<unsigned> distances;
 Graph g = Graph(std::cin);
 unsigned flow = maxflow(g);
 std::cout << flow;
 return 0;

}
