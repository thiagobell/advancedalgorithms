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
//#include <chrono>
#include <cmath>
#include <cstdlib>

using namespace std;

// information stored in edges
struct EdgeInformation {
  unsigned o,d;
  unsigned weight;
  EdgeInformation(unsigned o_, unsigned d_, unsigned w_ ) {
    o = o_;
    d = d_;
    weight = w_;
  }
};

const unsigned maxweight = 1000;


int generate_graph(int n, double p,const char *filepath_output) {
  vector<EdgeInformation> edges;
  srand48(time(0));
  ofstream outfile;
  outfile.open(filepath_output);

  for(unsigned i=1; i<=n; i++)
    for(unsigned j=1; j<=n; j++)
      if (i != j && drand48() < p)
	edges.push_back(EdgeInformation(i,j, lrand48()%maxweight));
 
  // (3) print out in DIMACS challenge format
  outfile << "p sp " << n << " " << edges.size() << endl;
 
  for (unsigned int ind =0; ind < edges.size(); ind++)
    outfile << "a " << edges[ind].o << " " <<edges[ind].d << " " << edges[ind].weight;

  outfile.close();
}
