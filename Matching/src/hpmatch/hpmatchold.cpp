#include "hpmatch.h"
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <iterator>
int inf = std::numeric_limits<int>::max();


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
int breadth_search(std::vector<Vertex>& U, std::vector<Vertex>& V)
{
  std::queue<unsigned> q;
  for(int u = 1; u <= U.size(); u++){
    if(U[u].matched_to == 0){ //matched to nill
      U[u].distance = 0;
      q.push(u);
    } else {
      U[u].distance = inf;
    }
  }
  U[0].distance = inf;
  V[0].distance = inf;
  while(!q.empty()){
    unsigned u = q.front();
    q.pop();
    if(U[u].distance < U[0].distance) {
      for(std::vector<unsigned>::iterator v = U[u].neigh.begin(); v !=  U[u].neigh.end(); v++){
          if(U[V[*v].matched_to].distance == inf) {
            U[V[*v].matched_to].distance = U[u].distance+1;
            q.push(V[*v].matched_to);
          }
      }
    }

  }
  return U[0].distance != inf;
}

//id: of node. when none = -1
bool DFS(int u, std::vector<Vertex>& U, std::vector<Vertex>& V)
{
  if(u == 0) { // is nill
    return true;
  }
  for(std::vector<unsigned>::iterator v = U[u].neigh.begin(); v !=  U[u].neigh.end(); v++){
    if(U[V[*v].matched_to].distance ==  U[u].distance+1){
      if(DFS(V[*v].matched_to, U, V)){
        U[u].matched_to = *v;
        V[*v].matched_to = u;
        return true;
      }
    }
  }
  U[0].distance = inf;
  return false;

}


int HPmatch::match()
{
  std::vector<Vertex> U, V;
  std::vector<unsigned> nU1,nV1,nU2,nV2,nilladj;


  nU1.push_back(1);
  nU1.push_back(2);
  nU2.push_back(2);

  nV1.push_back(1);
  nV2.push_back(1);
  nV2.push_back(2);

  Vertex nill(nilladj, Vertex::NILL);
  Vertex v0(nU1, Vertex::U);
  Vertex v1(nU2, Vertex::V);
  Vertex v2(nV1, Vertex::U);
  Vertex v3(nV2, Vertex::V);
  U.push_back(nill);
  U.push_back(v0);
  U.push_back(v1);
  V.push_back(nill);
  V.push_back(v2);
  V.push_back(v3);

  for(int u = 1; u <= U.size(); u++){
    U[u].matched_to = 0;
  }
  for(int v = 1; v <= V.size(); v++){
    V[v].matched_to = 0;
  }




  //MUST DO INITIAL MATCHING
  int matched = 0;
  while(breadth_search(U,V)){
      std::cout<<"done breadth\n";
      for(int u = 1; u <= U.size(); u++){
        if(U[u].matched_to == 0) {
          if(DFS(u,U,V) == true)
            matched++;
        }
      }
    }
    std::cout << matched;

}
