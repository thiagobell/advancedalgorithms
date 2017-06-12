#include <iostream>
#include "graph/graph.h"
#include "hpmatch/hpmatch.h"
int main(int argc, char **argv)
{

  Graph g(std::cin);
  int num_match = HPmatch::match(g.U, g.V);
  std::cout << num_match;
}
