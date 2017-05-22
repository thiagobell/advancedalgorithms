build/nheap.o : src/nheap/nheap.cpp
	g++ -g -O -o build/nheap.o -std=c++11 -c src/nheap/nheap.cpp
build/dijkstra.o: src/dijkstra/dijkstra.cpp
	g++ -g -O -o build/dijkstra.o -std=c++11 -c src/dijkstra/dijkstra.cpp
build/graph.o: src/graph/graph.cpp
	g++ -g -O -o build/graph.o -std=c++11 -c src/graph/graph.cpp
build/generate_graph.o: src/graph/generate_graph.cpp
	g++ -g -O -o build/generate_graph.o -std=c++11 -c src/graph/generate_graph.cpp
build/maxflow.o: src/maxflow/maxflow.cpp
	g++ -g -O -o build/maxflow.o -std=c++11 -c src/maxflow/maxflow.cpp
build/main.o: src/main.cpp
	g++ -g -O -o build/main.o -std=c++11 -c src/main.cpp
build/benchmark.o: src/experiment/benchmark.cpp
	g++ -g -O -o build/benchmark.o -std=c++11 -c src/experiment/benchmark.cpp
build/maxflow: build/main.o build/graph.o build/dijkstra.o build/nheap.o build/maxflow.o
	g++ -g -O -o build/maxflow build/main.o  build/graph.o build/nheap.o build/dijkstra.o build/maxflow.o

build/benchmark: build/benchmark.o build/graph.o build/dijkstra.o build/nheap.o build/maxflow.o build/generate_graph.o
	g++ -g -O -o build/benchmark build/benchmark.o  build/graph.o build/nheap.o build/dijkstra.o build/maxflow.o build/generate_graph.o

buildfolder:
	mkdir -p build

all: buildfolder build/maxflow build/benchmark

clean:
	rm -r build
