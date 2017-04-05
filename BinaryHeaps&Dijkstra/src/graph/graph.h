class Graph {
  private:
  unsigned int n, m;
   struct Edge *edges;
   struct Vertex *vertexes;

  public:
   struct Edge {
    Vertex *source ,*destination;
    unsigned weight;
   }
   struct Vertex {
    unsigned num_neigh;
    Edge *first_neigh;
   }

   Graph(std::string input_file);



};
