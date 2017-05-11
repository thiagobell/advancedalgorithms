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
  EdgeInformation(unsigned o_, unsigned d_) {
    o = o_;
    d = d_;
  }
};

const unsigned maxweight = 1000;


int generate_graph(int n, double p,const char *filepath_output) {
  vector<EdgeInformation> edges;
  unsigned int approx_m = n*n*p;
  edges.reserve(approx_m);
  srand48(time(0));
  ofstream outfile;
  outfile.open(filepath_output);
  // choosing s and t  
  
  

  for(unsigned i=1; i<=n; i++){
    for(unsigned j=1; j<=n; j++)
      if (i != j && drand48() < p)
	      edges.push_back(EdgeInformation(i,j));
  }

  unsigned s,t;
  do{  
    s = std::rand() % n + 1;
    t = std::rand() % n + 1;
  }while(s==t);

  // (3) print out in DIMACS challenge format
  outfile << "p max " << n << " " << edges.size() << endl;
  outfile << "n " << s << " s"<< endl;
  outfile << "n " << t << " t"<< endl;

  for (unsigned int ind =0; ind < edges.size(); ind++)
    outfile << "a " << edges[ind].o << " " <<edges[ind].d << " " << lrand48()%maxweight<<"\n";

  outfile.close();
}
