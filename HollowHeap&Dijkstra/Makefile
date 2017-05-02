build/hheap.o : src/hheap/hheap.cpp
	g++ -g -o build/hheap.o -std=c++11 -c src/hheap/hheap.cpp
build/dijkstra.o: src/dijkstra/dijkstra.cpp
	g++ -g -o build/dijkstra.o -std=c++11 -c src/dijkstra/dijkstra.cpp
build/graph.o: src/graph/graph.cpp
	g++ -g -o build/graph.o -std=c++11 -c src/graph/graph.cpp
build/generate_graph.o: src/graph/generate_graph.cpp
	g++ -g -o build/generate_graph.o -std=c++11 -c src/graph/generate_graph.cpp


build/main.o: src/main.cpp
	g++ -g -o build/main.o -std=c++11 -c src/main.cpp
build/heap_insert.o : src/experiments/heap_insert.cpp
	g++ -g -o build/heap_insert.o -std=c++11 -c src/experiments/heap_insert.cpp
build/heap_update.o : src/experiments/heap_update.cpp
	g++ -g -o build/heap_update.o -std=c++11 -c src/experiments/heap_update.cpp
build/heap_delete.o : src/experiments/heap_delete.cpp
	g++ -g -o build/heap_delete.o -std=c++11 -c src/experiments/heap_delete.cpp
build/dijkstra_fix_edges.o : src/experiments/dijkstra_fix_edges.cpp 
	g++ -g -o build/dijkstra_fix_edges.o -std=c++11 -c src/experiments/dijkstra_fix_edges.cpp
build/dijkstra_fix_vertex.o : src/experiments/dijkstra_fix_vertex.cpp
	g++ -g -o build/dijkstra_fix_vertex.o -std=c++11 -c src/experiments/dijkstra_fix_vertex.cpp


build/dijkstra: build/main.o build/graph.o build/dijkstra.o build/hheap.o
	g++ -g -o build/dijkstra build/main.o  build/graph.o build/hheap.o build/dijkstra.o

build/heap_insert : build/heap_insert.o build/graph.o build/dijkstra.o build/hheap.o
	g++ -g -o build/heap_insert build/graph.o build/dijkstra.o build/hheap.o build/heap_insert.o
build/heap_update : build/heap_update.o build/graph.o build/dijkstra.o build/hheap.o
	g++ -g -o build/heap_update build/graph.o build/dijkstra.o build/hheap.o build/heap_update.o
build/heap_delete : build/heap_delete.o build/graph.o build/dijkstra.o build/hheap.o
	g++ -g -o build/heap_delete build/graph.o build/dijkstra.o build/hheap.o build/heap_delete.o

build/dijkstra_fix_edges : build/dijkstra_fix_edges.o build/graph.o build/dijkstra.o build/hheap.o build/generate_graph.o
	g++ -g -o build/dijstra_fix_edges build/graph.o build/dijkstra.o build/hheap.o build/dijkstra_fix_edges.o build/generate_graph.o
build/dijkstra_fix_vertex : build/dijkstra_fix_vertex.o build/graph.o build/dijkstra.o build/hheap.o build/generate_graph.o
	g++ -g -o build/dijstra_fix_vertex build/graph.o build/dijkstra.o build/hheap.o build/dijkstra_fix_vertex.o build/generate_graph.o

buildfolder:
	mkdir -p build

all: buildfolder build/dijkstra build/heap_insert build/heap_update build/heap_delete build/dijkstra_fix_vertex build/dijkstra_fix_edges
