#include <iostream>
#include "graph/graph.h"
#include <string.h>
#include <cassert>
//#include <chrono>
#include "blossom5/GEOM/GeomPerfectMatching.h"
#include "blossom5/PerfectMatching.h"


//returns the sum of the weights of the matches
double matching(Graph g, std::vector<unsigned> odd_vertices )
{
  std::cout << odd_vertices.size() << " odd vertices\n";
  //based on example code from blossom5 project
  struct PerfectMatching::Options options;
	struct GeomPerfectMatching::GPMOptions gpm_options;
  unsigned node_num = odd_vertices.size();
  GeomPerfectMatching *gpm = new GeomPerfectMatching(node_num, 2);
  for(unsigned i = 0; i < odd_vertices.size();i++) {
    GeomPerfectMatching::REAL coord[2];
    coord[0] = g.vertex_coordinates[odd_vertices[i]*2];
    coord[1] = g.vertex_coordinates[odd_vertices[i]*2+1];
    gpm->AddPoint(coord);
  }
  gpm->options = options;
  gpm->gpm_options = gpm_options;
  gpm->Solve();
  double sum_distance_matches = 0.0;
  unsigned j;
  for(unsigned i = 0; i < node_num;i++){
		j = gpm->GetMatch(i);
		if (i < j)
		{
			sum_distance_matches = sum_distance_matches + gpm->Dist(i, j);
    }
  }
  return sum_distance_matches;

}

int main(int argc, char **argv)
{
  bool verbose = false;
  if(argc > 1 && strncmp(argv[1],"-v",2)==0) {
    verbose = true;
  }
  Graph g(std::cin);
  std::cout << "done reading\n";
  //returns degrees of all vertices
  std::vector<unsigned> degrees = g.gen_mst();
  std::cout << "done mst\n";
  std::vector<unsigned> odd_vertices;
  //find odd vertices ids
  for(unsigned i = 0; i<degrees.size();i++) {
    if(degrees[i]%2 == 1)
      odd_vertices.push_back(i);
  }
  for(auto a: degrees) {
    std::cout << a<<"\t";
  }
  //there must be an even number of nodes with odd degree
  assert(odd_vertices.size()%2==0);
  double weight_matches = 0;
  if(odd_vertices.size()>1) {
    //calculates geometric matching using blossom5 package
    weight_matches = matching(g, odd_vertices);
  }
  std::cout << "matches wgth"<< weight_matches<<"\n";
  std::cout << "selected edge wgth"<< g.selected_edges_weight<<"\n";
  std::cout << weight_matches + g.selected_edges_weight;


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
