#include "hpmatch.h"
#include <iostream>
#include <vector>
#include <limits>
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
int breadth_search(std::vector<Vertex>& vertices)
{
  std::vector<unsigned> vec_inxs;
  //analyses edges from set U
  for(unsigned inx = 0; inx < vertices.size(); inx++){
    if(vertices[inx].group == Vertex::U)  {
      if(vertices[inx].matched_to == -1) {//vertex is free
	        vertices[inx].distance = 0;
	        vec_inxs.push_back(inx);
      } else { //vertex not free
	       vertices[inx].distance = inf;
      }
    } else {
    //  std::cout <<" not v "<<inx<<"\n";
    }
  }
  bool found = false;
  while(!vec_inxs.empty()) {
    unsigned inx = vec_inxs.front();
    vec_inxs.erase(vec_inxs.begin());
    //for(unsigned v_inx = vertices[inx].neigh
    for(std::vector<unsigned>::iterator v_inx = vertices[inx].neigh.begin(); v_inx != vertices[inx].neigh.end(); v_inx++){
      if(vertices[*v_inx].matched_to ==-1) { //vertex is free
	       found = true;
      } else {
      	//test if node was already added
      	if(vertices[vertices[*v_inx].matched_to].distance == inf) {///problema e se o V nao tiver match?
      	  //not visited yet
      	  vertices[vertices[*v_inx].matched_to].distance = vertices[inx].distance + 1;
      	  //add u matched with v
      	  vec_inxs.push_back(vertices[*v_inx].matched_to);
      	}
      }
    }

  }

  for(unsigned inx = 0; inx < vertices.size(); inx++){
    //std::cout << "id"<<inx << " distance:"<<vertices[inx].distance << std::endl;
  }
  return found;
}

//id: of node. when none = -1
bool DFS(int id, std::vector<Vertex>& vertices)
{
  if(id == -1)
    return true;
  for(std::vector<unsigned>::iterator v_inx = vertices[id].neigh.begin(); v_inx != vertices[id].neigh.end(); v_inx++) {
    if(vertices[vertices[*v_inx].matched_to].distance == vertices[id].distance){
      if(DFS(vertices[*v_inx].matched_to, vertices) == true){
        vertices[id].matched_to = *v_inx;
        vertices[*v_inx].matched_to = id;
        return true;
      }
    }
  }
  vertices[id].distance = inf;
  return false;
}


int HPmatch::match()
{
  //points to the vertex the the given vertex is matched to
  std::vector<Vertex> vex;

  std::vector<unsigned> n0,n1,n2,n3;
  n0.push_back(1);
  n0.push_back(3);
  n1.push_back(0);
  n2.push_back(3);
  n3.push_back(2);
  n3.push_back(0);
  Vertex v0(n0, Vertex::U);
  Vertex v1(n1, Vertex::V);
  Vertex v2(n2, Vertex::U);
  Vertex v3(n3, Vertex::V);

  vex.push_back(v0);
  vex.push_back(v1);
  vex.push_back(v2);
  vex.push_back(v3);
  //MUST DO INITIAL MATCHING
  int matched = 0;
  while(breadth_search(vex)){
    std::cout<<"done breadth\n";
    for(unsigned inx = 0; inx < vex.size(); inx++){
      if(vex[inx].group == Vertex::U)  {
        if(vex[inx].matched_to == -1){
          if(DFS(inx,vex)){
            matched++;
          }
        }
      }
    }
  }
  std::cout<<matched;
}
