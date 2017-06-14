#include "hpmatch.h"
#include "../graph/graph.h"
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <iterator>
unsigned inf = std::numeric_limits<unsigned>::max();


// 0 - 1
// 2 \- 3
//
//
//
//


//starts from free vertexes from U
//occupied vertexes from V
//occupied vertexes from U
//free vertex from V
bool breadth_search(std::vector<Vertex>& U, std::vector<Vertex>& V)
{
  std::queue<unsigned> q;
  U[0].distance = inf;
  V[0].distance = inf;
  for(int u = 1; u < U.size(); u++){
    if(U[u].matched_to == 0){ //matched to nill
      U[u].distance = 0;
      q.push(u);
    } else {
      //std::cout << "u="<< u<< " not matched to nill\n";
      U[u].distance = inf;
    }

  }
  while(!q.empty()){
    unsigned u = q.front();
    q.pop();
    if(U[u].distance < U[0].distance) {
      //if(U[u].neigh.size() > 0){
        for(std::vector<unsigned>::iterator v = U[u].neigh.begin(); v !=  U[u].neigh.end(); v++){
            if(U[V[*v].matched_to].distance == inf) {
              U[V[*v].matched_to].distance = U[u].distance+1;
              q.push(V[*v].matched_to);
              //std::cout << "pushed u="<<V[*v].matched_to<<"with distance"<< U[u].distance<<"\n";
            }
        }
      //}
    }
  }

  //return U[0].distance != inf;
  if(U[0].distance == inf) {
    return false;

  }
  else
    return true;
}

//id: of node. when none = -1
bool DFS(int u, std::vector<Vertex>& U, std::vector<Vertex>& V)
{
  if(u == 0) { // is nill
    return true;
  }
  if(U[u].neigh.size() > 0){
    for(std::vector<unsigned>::iterator v = U[u].neigh.begin(); v !=  U[u].neigh.end(); v++){
      if(U[V[*v].matched_to].distance ==  U[u].distance+1){
        if(DFS(V[*v].matched_to, U, V)){
          U[u].matched_to = *v;
          V[*v].matched_to = u;
          return true;
          }
        }
    }
  }
  U[u].distance = inf;
  return false;

}


int HPmatch::match(std::vector<Vertex> U, std::vector<Vertex> V, bool verbose)
{
  //MUST DO INITIAL MATCHING
  int matched = 0;
  int iteration = 0;
  while(breadth_search(U,V)== true){
      //std::cout<<"done breadth\n";
      iteration++;
      for(int u = 1; u < U.size(); u++){
        if(U[u].matched_to == 0) {
          if(DFS(u,U,V) == true)
            matched++;
        }
      }
    }
  if(verbose)
    std::cout<<"iterations="<< iteration<<",";
    return matched;
}
