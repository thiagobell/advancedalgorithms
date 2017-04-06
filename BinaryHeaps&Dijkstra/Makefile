

nheap.o:
	g++ -o build/nheap.o -std=c++11 -c src/nheap/nheap.cpp


graph.o:
	g++ -o build/graph.o -std=c++11 -c src/graph/graph.cpp


dijkstra.o:
	g++ -o build/dijkstra.o -std=c++11 -c src/dijkstra/dijkstra.cpp


main.o:
	g++ -o build/main.o -std=c++11 -c src/main.cpp

all:	build 
	g++ -o build/run -g -std=c++11 src/nheap/nheap.cpp src/graph/graph.cpp src/dijkstra/dijkstra.cpp src/main.cpp

build:
	mkdir build

clean:
	rm -r build
