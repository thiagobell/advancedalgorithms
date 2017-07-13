#include <iostream>
#include "graph/graph.h"
#include <string.h>
#include <cassert>
#include <algorithm>
#include "cristofides.h"
#include <chrono>


int main(int argc, char **argv)
{
  bool greedy = false;
  bool measure_time = false;
  unsigned repetitions = 1;
  if(argc > 1) {
    unsigned count = 1;
    while(count < argc){
      if(strncmp(argv[count],"-",1)==0) {
      char option = argv[count][1];
      switch(option) {
        case 'g':
          //must use a greedy strategy
          greedy = true;
          break;
        case 't':
          measure_time = true;
          break;
        case 'r': //repetitions
          repetitions = std::atoi(argv[count+1]);
          std::cout << "repetitions:" << repetitions<<"\n";
          count++;
          break;
      }
      }
      count++;
    }

  }

  Graph g(std::cin);
  std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
  double cost;
  for(unsigned iter=0; iter<repetitions;iter++){
    cost = cristofides(g, greedy);
    g.reset_selected();
  }
  if(measure_time)
    std::cout << "time:"<<  std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-t).count()<<"\n";
  std::cout << cost;
}
