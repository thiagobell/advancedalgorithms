#include <iostream>
#include "graph/graph.h"
#include <string.h>
#include <cassert>
//#include <chrono>


void matching(Graph g, std::vector<unsigned> odd_vertices )
{
  //based on example code from blossom5 project
  struct PerfectMatching::Options options;
	struct GeomPerfectMatching::GPMOptions gpm_options;
  GeomPerfectMatching::REAL* x_array = new GeomPerfectMatching::REAL[g.n]
  GeomPerfectMatching::REAL* y_array = new GeomPerfectMatching::REAL[g.n]
  GeomPerfectMatching *gpm = new GeomPerfectMatching(g.n, 2);
  for(unsigned i = 0; i < odd_vertices.size();i++) {
    GeomPerfectMatching::REAL coord[2];
    coord[0] = g.vertex_coordinates[odd_vertices[i]*2];
    coord[1] = g.vertex_coordinates[odd_vertices[i]*2+1];
    gpm->AddPoint(coord);
  }
  gpm->options = options;
  gpm->gpm_options = gpm_options;
  gpm->Solve();


}

int main(int argc, char **argv)
{
  bool verbose = false;
  if(argc > 1 && strncmp(argv[1],"-v",2)==0) {
    verbose = true;
  }
  Graph g(std::cin);
  //returns degrees of all vertices
  std::vector<unsigned> degrees = g.gen_mst();

  std::vector<unsigned> odd_vertices;
  //find odd vertices ids
  for(unsigned i = 0; i<degrees.size();i++) {
    if(degrees[i]%2 == 1)
      odd_vertices.push_back(i);
  }
  //there must be an even number of nodes with odd degree
  assert(odd_vertices.size()%2==0);



  /*
  std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
  int num_match;
  num_match = HPmatch::match(g.U, g.V,verbose);
  if(verbose) {
      std::cout << "time(ms)= " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count();
      std::cout << ",match=" << num_match;
      std::cout << ",n=" << g.n;
      std::cout << ",m=" << g.m;
      std::cout << std::endl;
  } else {
      std::cout << num_match;
  }
  */
}
