#include <iostream>
#include "graph/graph.h"
#include "hpmatch/hpmatch.h"
#include <string.h>
#include <chrono>
int main(int argc, char **argv)
{
  bool verbose = false;
  if(argc > 1 && strncmp(argv[1],"-v",2)==0) {
    verbose = true;
  }
  Graph g(std::cin);

  std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
  int num_match = HPmatch::match(g.U, g.V);
  if(verbose) {
      std::cout << "time(ms)= " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count();
      std::cout << ",match=" << num_match;
      std::cout << ",n=" << g.n;
      std::cout << ",m=" << g.m;
      std::cout << std::endl;
  } else {
      std::cout << num_match;
  }

}
