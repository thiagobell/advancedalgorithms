#include "hpmatch.h"

int HPmatch::match()
{
  //points to the vertex the the given vertex is matched to
  std::vector<Vertex> U, V;

  std::vector<unsigned> nU1,nV1,nU2,nV2;
  nU1.push_back(1);
  nU1.push_back(2);
  nU2.push_back(2);

  nV1.push_back(1);
  nV2.push_back(1);
  nV2.push_back(2);


  Vertex v0(nU1, Vertex::U);
  Vertex v1(nU2, Vertex::V);
  Vertex v2(nV1, Vertex::U);
  Vertex v3(nV2, Vertex::V);

  U.push_back(v0);
  U.push_back(v1);
  V.push_back(v2);
  V.push_back(v3);


  //MUST DO INITIAL MATCHING
}

int b_search(std::vector<Vertex> U, std::vector<Vertex> V){
  bool m_u* =  new[U.size()];
  bool m_v* =  new[V.size()];
  unsigned d_u* = new[U.size()];
  unsigned d_v* = new[V.size()];
  bool found = false;

  for(int i=0;i<U.size();i++){
    m_u[i] = false;
    d_u[i] = 0;
  }
  for(int i=0;i<V.size();i++){
    m_v[i] = false;
  }
do{
  std::vector<unsigned> u2;
  for(unsigned u=1;u<=U.size();u++){
    m_u[u-1] = true;

    for(std::vector<unsigned>::iterator v = U[u-1].neigh.begin(); v !=  U[u-1].neigh.end(); v++){
      if(U[u-1].path_to != v*){
        if(!m_v[(v*)-1]){
          d_v[(v*)-1] = d_u[u-1]+1;
          u2.push_back(v*);
        }
      }
    }
  }

  found = false;
  std::vector<unsigned> u1;
  for(std::vector<unsigned>::iterator u = u2.begin(); u !=  u2.end(); u++){
    int u_inx = u* -1
    m_u[u_inx] = true;
    if(U[u_inx].path_to == -1){
      //u is free
      found = true;
    } else {
      int v_inx = U[u_inx].path_to -1;
      if(!m_v[v_inx]){
        d_v[v_inx] = d_u[u_inx] +1;
        u1.push_back(v_inx +1);
      }
    }
  }
}while(!found);
}
