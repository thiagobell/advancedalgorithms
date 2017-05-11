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

  unsigned min_n_exp = 5, max_n_exp = 13;
  //m ~= 2^Nfactor * Nfactor

  for(unsigned n_exp = min_n_exp; n_exp <= max_n_exp; n_exp++) {
    unsigned n = std::pow(2, n_exp);
    double p = n*n_exp /(std::pow(2,n_exp*2)-std::pow(2,n_exp));
    generate_graph(std::pow(2, n_exp), p,"/tmp/net.gr");
    std::cout << "graph generated\n";
    std::ifstream inputfile;
    inputfile.open("/tmp/net.gr");
    Graph g(inputfile);
    std::cout << "graph read\n";
    std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
    maxflow(g);
    std::cout << "n= "<< n << " m= " << g.numEdges() <<" time= "<< std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count()<<"\n";
  }
  

}
