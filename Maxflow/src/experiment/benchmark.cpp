/*
  Experimentally tests the scalability of the algorithm
*/

#include "../graph/generate_graph.h"
#include "../maxflow/maxflow.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <chrono>
int main() {
	unsigned maxf;
  unsigned min_m_exp = 13, max_m_exp = 18;
  //m ~= 2^Nfactor * Nfactor
  unsigned n_exp = 10;
  for(unsigned m_exp = min_m_exp; m_exp <= max_m_exp; m_exp++) {
    unsigned n = std::pow(2, n_exp);
    double p = std::pow(2, m_exp) /(std::pow(2,n_exp*2)-std::pow(2,n_exp));
    //repeats 10 times.
    for(unsigned run = 0; run < 10; run++){
      generate_graph(std::pow(2, n_exp), p,"/tmp/net.gr");
      std::ifstream inputfile;
      inputfile.open("/tmp/net.gr");
      Graph g(inputfile);
      std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
      maxf = maxflow(g);
      std::cout << "n= "<< n << " run= "<< run  << " m= " << g.numEdges() << " maxflow= "<< maxf <<" time= "<< std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count()<<"\n";
    std::cout << std::flush;
  }
  

}
}
