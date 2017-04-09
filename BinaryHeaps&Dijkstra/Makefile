build/nheap.o: src/nheap/nheap.cpp
	g++ -o build/nheap.o -std=c++11 -c src/nheap/nheap.cpp


build/graph.o: src/graph/graph.cpp
	g++ -o build/graph.o -std=c++11 -c src/graph/graph.cpp


build/dijkstra.o: src/dijkstra/dijkstra.cpp
	g++ -o build/dijkstra.o -std=c++11 -c src/dijkstra/dijkstra.cpp


build/main.o: src/main.cpp
	g++ -o build/main.o -std=c++11 -c src/main.cpp

all:	build_folder build/nheap.o build/graph.o build/dijkstra.o build/main.o
	g++ -o build/run build/main.o  build/nheap.o build/graph.o build/dijkstra.o
#	g++ -o build/run -g -std=c++11 src/nheap/nheap.cpp src/graph/graph.cpp src/dijkstra/dijkstra.cpp src/main.cpp

build_folder:
	mkdir -p build

clean:
	rm -r build
