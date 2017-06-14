//this file is based on the example provided on:
//http://inf.ufrgs.br/~MRPRITT/doku.php?id=inf05016:2017-1-trabalhos
/**
 * \file gen.cpp
 *   \author Marcus Ritt <mrpritt@inf.ufrgs.br> 
 *   \version $Id: emacs 2872 2009-01-31 01:46:50Z ritt $
 *   \date Time-stamp: <2011-08-24 15:17:49 ritt>
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

// information stored in edges
struct EdgeInformation {
  unsigned o,d;
  EdgeInformation(unsigned o_, unsigned d_) {
    o = o_;
    d = d_;
  }
};

int generate_graph(int n, double p) {
  vector<EdgeInformation> edges;
  unsigned int approx_m = n*n*p;
  edges.reserve(approx_m);
  srand48(time(0));
  for(unsigned i=1; i<=n; i++){
    for(unsigned j=1; j<=n; j++)
      if (i != j && drand48() < p)
	edges.push_back(EdgeInformation(i,j+n));
  }
  // (3) print out in DIMACS challenge format
  cout << "c Bi-partite graph\n";
  cout << "p edge " << n*2 << " " << edges.size() << endl;

  for (unsigned int ind =0; ind < edges.size(); ind++)
    cout << "e " << edges[ind].o << " " <<edges[ind].d <<"\n";
}

int main(int argc, char **argv) {
  if(argc < 3) {
    cout << "./fastgen n p\n";
    return 0;
  }
  unsigned n = atoi(argv[1]);
  double p = atof(argv[2]);
  
  generate_graph(n,p);

}
