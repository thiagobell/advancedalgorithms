#include "blossom5/GEOM/GeomPerfectMatching.h"
#include "blossom5/PerfectMatching.h"
#include "graph/graph.h"
#include "cristofides.h"
#include <algorithm>
#include <cassert>

double greedy_matching(Graph &g, std::vector<unsigned> &odd_vertices) {
  std::vector<Edge*> free_edges;
  for(unsigned inx_a=0;inx_a< odd_vertices.size();inx_a++){
    for(unsigned inx_b=inx_a+1;inx_b< odd_vertices.size();inx_b++) {
      unsigned n1 = odd_vertices[inx_a];
      unsigned n2 = odd_vertices[inx_b];
      assert(n1< n2);
        if(g.edges_vertex[n1][n2-n1-1]->selected == false)
            assert(g.edges_vertex[n1][n2-n1-1]->n1 == n1);
            assert(g.edges_vertex[n1][n2-n1-1]->n2 == n2);
            free_edges.push_back(g.edges_vertex[n1][n2-n1-1]);
        }
      }

  //sorts edges
  std::sort(free_edges.begin(), free_edges.end(), Edge::less_than_pointer);
  //picks greedily

  unsigned matches_to_make = odd_vertices.size()/2;
  unsigned matches_made = 0;
  unsigned edg_inx=0;
  unsigned weight_sum = 0;

  std::vector<bool> matched(g.n, false);

  while(edg_inx < free_edges.size() && matches_made < matches_to_make){
    if(free_edges[edg_inx]->selected == false){
      if(matched[free_edges[edg_inx]->n1]==false){
        if(matched[free_edges[edg_inx]->n2]==false){
          //edge can be matched
          matched[free_edges[edg_inx]->n1]=true;
          matched[free_edges[edg_inx]->n2]=true;
          free_edges[edg_inx]->selected = true;
          matches_made++;
          weight_sum += free_edges[edg_inx]->distance;
        }
      }
    }
    edg_inx++;
  }

  assert(matches_made == matches_to_make);

  return weight_sum;
}

//returns the sum of the weights of the matches
double perfect_matching(Graph &g, std::vector<unsigned> &odd_vertices)
{
  //based on example code from blossom5 project
  struct PerfectMatching::Options options;
  options.verbose = false;
	struct GeomPerfectMatching::GPMOptions gpm_options;
  unsigned node_num = odd_vertices.size();
  GeomPerfectMatching *gpm = new GeomPerfectMatching(node_num, 2);
  for(unsigned i = 0; i < odd_vertices.size();i++) {
    GeomPerfectMatching::REAL coord[2];
    coord[0] = g.vertex_coordinates[(odd_vertices[i])*2];
    coord[1] = g.vertex_coordinates[(odd_vertices[i])*2+1];
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



double cristofides(Graph &g, bool greedy)
{
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
  double weight_matches = 0;
  if(odd_vertices.size()>1) {
    if(greedy)
      weight_matches = greedy_matching(g,odd_vertices);
    else//calculates perfect matching using blossom5 package
      weight_matches = perfect_matching(g, odd_vertices);
  }
  return weight_matches + g.selected_edges_weight;
}
