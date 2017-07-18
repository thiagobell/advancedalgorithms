#include "blossom5/GEOM/GeomPerfectMatching.h"
#include "blossom5/PerfectMatching.h"
#include "graph/graph.h"
#include "cristofides.h"
#include <algorithm>
#include <cassert>

std::vector<Edge*> greedy_matching(Graph &g, std::vector<unsigned> &odd_vertices) {
  std::vector<Edge*> free_edges, selected_edges;
  for(unsigned inx_a=0;inx_a< odd_vertices.size();inx_a++){
    for(unsigned inx_b=inx_a+1;inx_b< odd_vertices.size();inx_b++) {
      unsigned n1 = odd_vertices[inx_a];
      unsigned n2 = odd_vertices[inx_b];
      free_edges.push_back(g.edges_vertex[n1][n2-n1-1]);
     }
  }

  //sorts edges
  std::sort(free_edges.begin(), free_edges.end(), Edge::less_than_pointer);
  //picks greedily

  unsigned matches_to_make = odd_vertices.size()/2;
  unsigned matches_made = 0;
  unsigned edg_inx=0;

  std::vector<bool> matched(g.n, false);

  while(edg_inx < free_edges.size() && matches_made < matches_to_make){
    //if(free_edges[edg_inx]->selected == false){
      if(matched[free_edges[edg_inx]->n1]==false){
        if(matched[free_edges[edg_inx]->n2]==false){
          //edge can be matched
          matched[free_edges[edg_inx]->n1]=true;
          matched[free_edges[edg_inx]->n2]=true;

          free_edges[edg_inx]->edge_count++;
          selected_edges.push_back(free_edges[edg_inx]);
          matches_made++;
        }
      }
    edg_inx++;
  }

  assert(matches_made == matches_to_make);

  return selected_edges;
}



//returns the set of matched edges
std::vector<Edge*> perfect_matching(Graph &g, std::vector<unsigned> &odd_vertices)
{
  //based on example code from blossom5 project
  struct PerfectMatching::Options options;
  options.verbose = false;
	struct GeomPerfectMatching::GPMOptions gpm_options;
  unsigned node_num = odd_vertices.size();
  GeomPerfectMatching *gpm = new GeomPerfectMatching(node_num, 2);
  for(unsigned i = 0; i < odd_vertices.size();i++) {
    GeomPerfectMatching::REAL coord[2];
    coord[0] = g.vertex_coordinates_x[odd_vertices[i]];
    coord[1] = g.vertex_coordinates_y[odd_vertices[i]];
    gpm->AddPoint(coord);
  }
  gpm->options = options;
  gpm->gpm_options = gpm_options;
  gpm->Solve();
  double sum_distance_matches = 0.0;
  unsigned j;
  std::vector<Edge*> matched_edges;
  for(unsigned i = 0; i < node_num;i++){
		j = gpm->GetMatch(i);
		if (i < j)
		{
      unsigned n1 = odd_vertices[i];
      unsigned n2 = odd_vertices[j];

      matched_edges.push_back(g.edges_vertex[n1][n2-n1-1]);

      g.edges_vertex[n1][n2-n1-1]->edge_count = g.edges_vertex[n1][n2-n1-1]->edge_count +1;
			//sum_distance_matches = sum_distance_matches + gpm->Dist(i, j);
    }
  }
  return matched_edges;
}

//returns ordered lists of edges in path
//Eulerian Path calculated using hierholzers algorithm
//implementation based on http://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/
unsigned hamiltonian_circuit(Graph &g, std::vector< std::vector<Edge*> > &adjacency_list , unsigned num_edges)
{

  unsigned start_node = 0;
  unsigned num_visited = 0; //source
  std::vector<unsigned> circuit;
  std::vector<unsigned> current_path;
  unsigned current_node = start_node;
  current_path.push_back(start_node);
  unsigned sum_edge_euler = 0;
  while(!current_path.empty()) {
    bool found_edge = false;
    //finds if there is a free edge
    unsigned edg_inx = 0;
    while(found_edge == false && edg_inx < adjacency_list[current_node].size()){
      Edge *edg = adjacency_list[current_node][edg_inx];
      assert(edg != NULL);
      if(edg->edge_count > 0){
        unsigned neigh;
        if(edg->n1 == current_node)
          neigh = edg->n2;
        else if(edg->n2 == current_node)
          neigh = edg->n1;
        current_path.push_back(current_node);
        sum_edge_euler += edg->distance;
        found_edge = true;
        edg->edge_count--;
        current_node = neigh;
      }
      edg_inx++;
    }
    if(!found_edge){
      //must backtrack

      circuit.push_back(current_node);
      current_node = current_path.back();
      current_path.pop_back();
    }
  }
  //skips repeated vertices
  std::vector<unsigned> h_circuit;
  std::vector<bool> visited(g.n, false);
  //for(auto vert: circuit) {
  for(unsigned inx = 0; inx < circuit.size(); inx++){
    unsigned vert = circuit[inx];
    if(vert!=start_node) {
      if(visited[vert] == false){
        h_circuit.push_back(vert);
        visited[vert]=true;
      }
    }
    else{
      visited[start_node] = true;
      h_circuit.push_back(vert);
    }
  }
  //calculates cost of circuit
  unsigned cost= 0;
  assert(h_circuit.size() > 0);
  assert(h_circuit[0] == h_circuit[h_circuit.size()-1]);
  for(unsigned inx = 0; inx < h_circuit.size()-1; inx++){

    unsigned smaller, larger;
    smaller = h_circuit[inx];
    larger = h_circuit[inx+1];

    assert(larger != smaller);
    if(larger < smaller) {
      unsigned temp;
      temp = larger;
      larger = smaller;
      smaller = temp;
    }
    assert(larger < g.n);
    assert(g.edges_vertex[smaller][larger-smaller-1]->n1 == smaller);
    assert(g.edges_vertex[smaller][larger-smaller-1]->n2 == larger);
    cost += g.edges_vertex[smaller][larger-smaller-1]->distance;
  }
  //must close the loop

  return cost;
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
  std::vector<Edge*> matched_edges;
  //there must be an even number of nodes with odd degree
  double weight_matches = 0;
  if(odd_vertices.size()>1) {
    if(greedy)
      greedy_matching(g,odd_vertices);
    else//calculates perfect matching using blossom5 package
      perfect_matching(g, odd_vertices);
  }
  //union of matched edges of matching and MST
  //adds edges from MST that have a count == 1 which means they were only matched
  //during MST
  //creates adjacency list with selected edges
  std::vector< std::vector<Edge*> > adjacency_list;
  adjacency_list.resize(g.n);
  unsigned num_edges = 0; //considering edge_count parameter
  for(unsigned edginx =0;edginx < g.edges_pt.size();edginx++){
    if(g.edges_pt[edginx]->edge_count > 0){
    num_edges += g.edges_pt[edginx]->edge_count;
    adjacency_list[g.edges_pt[edginx]->n1].push_back(g.edges_pt[edginx]);
    adjacency_list[g.edges_pt[edginx]->n2].push_back(g.edges_pt[edginx]);
  }
}

  unsigned cost = hamiltonian_circuit(g, adjacency_list,num_edges);
  return cost;

}
