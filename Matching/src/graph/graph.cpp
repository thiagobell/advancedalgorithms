#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

//file parsing based on:
//http://www.inf.ufrgs.br/~MRPRITT/doku.php?id=inf05016:2017-1-trabalhos
Graph::Graph(std::istream& inputF)
{

  std::string line="", dummy;
  while (line.substr(0,6) != "p edge")
    getline(inputF,line);

  std::stringstream linestr;
  linestr.str(line);
  int n,m;
  linestr >> dummy >> dummy >> n >> m;
  unsigned sizeofset = n/2;
  //allocates memory
  U.reserve(sizeofset);
  V.reserve(sizeofset);
  unsigned i=0;
  while(i <= sizeofset) { //pre allocates vertexes including nill node
    Vertex vU, vV;


    U.push_back(vU);
    V.push_back(vV);
    i++;
  }


  i=0;
  while (i<m) {
    getline(inputF,line);
    if (line.substr(0,2) == "e ") {
      std::stringstream arc(line);
      unsigned s,d;
      char ac;

      arc >> ac >> s >> d;
      if(s <= sizeofset){ //source is at set U
        U[s].neigh.push_back(d-sizeofset);
        V[d-sizeofset].neigh.push_back(s);
      } else { // source is at set V
        V[s-sizeofset].neigh.push_back(d);
        U[d].neigh.push_back(s-sizeofset);
      }
      i++;
    }
  }
}
