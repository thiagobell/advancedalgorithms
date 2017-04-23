build/hheap.o : src/hheap/hheap.cpp
	g++ -g -o build/hheap.o -std=c++11 -c src/hheap/hheap.cpp
build/dijkstra.o: src/dijkstra/dijkstra.cpp
	g++ -g -o build/dijkstra.o -std=c++11 -c src/dijkstra/dijkstra.cpp
build/graph.o: src/graph/graph.cpp
	g++ -g -o build/graph.o -std=c++11 -c src/graph/graph.cpp
build/main.o: src/main.cpp
	g++ -g -o build/main.o -std=c++11 -c src/main.cpp
build/dijkstra: build/main.o build/graph.o build/dijkstra.o build/hheap.o
	g++ -g -o build/dijkstra build/main.o  build/graph.o build/hheap.o build/dijkstra.o

buildfolder:
	mkdir -p build

all: buildfolder build/dijkstra 
