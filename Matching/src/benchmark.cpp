#include <iostream>
#include "graph/graph.h"
#include "hpmatch/hpmatch.h"
#include <string.h>
#include <chrono>
#include <cmath>
int run(int setsize, double p)
{
  std::cout << "generating graph\n";
  Graph g(setsize ,p);
  std::cout << "done\n";
  std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
  int num_match;
  for(unsigned r = 0; r < 300; r++) {
    if(r == 0)
      num_match = HPmatch::match(g.U, g.V,true);
    else
      num_match = HPmatch::match(g.U, g.V,false);
  }
  std::cout << "time(ms)= " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count();
  std::cout << ",repetitions=" << 300;
  std::cout << ",match=" << num_match;
  std::cout << ",n=" << g.n;
  std::cout << ",m=" << g.m;
  std::cout << std::endl;

}
int main() {
  std::vector<unsigned> ns;
  ns.push_back(12);
  ns.push_back(13);
  ns.push_back(14);
  ns.push_back(15);

  double pinit = 0.1;
  for(unsigned ninx = 0; ninx< ns.size();ninx++) {
    run(std::pow(2,ns[ninx]), pinit);
    pinit = pinit * 0.25;
  }


}
