#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
class Dijkstra {
private:
std::vector<unsigned> distance;
std::vector<unsigned> previous_vertex;

public:

Dijkstra(unsigned s, unsigned t, Graph g, unsigned heap_arity);
bool found_path;
std::vector<unsigned> get_distances(){return distance;}
std::vector<unsigned> get_paths(){return previous_vertex;};

};
#endif
