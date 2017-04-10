build/nheap.o: src/nheap/nheap.cpp
	g++ -o build/nheap.o -std=c++11 -c src/nheap/nheap.cpp


build/graph.o: src/graph/graph.cpp
	g++ -o build/graph.o -std=c++11 -c src/graph/graph.cpp


build/dijkstra.o: src/dijkstra/dijkstra.cpp
	g++ -o build/dijkstra.o -std=c++11 -c src/dijkstra/dijkstra.cpp


build/main.o: src/main.cpp
	g++ -o build/main.o -std=c++11 -c src/main.cpp

build/narity.o : src/experiments/narity.cpp
	g++ -o build/narity.o -std=c++11 -c src/experiments/narity.cpp

build/heap_insert.o : src/experiments/heap_insert.cpp
	g++ -o build/heap_insert.o -std=c++11 -c src/experiments/heap_insert.cpp
build/heap_update.o : src/experiments/heap_update.cpp
	g++ -o build/heap_update.o -std=c++11 -c src/experiments/heap_update.cpp




all:	build_folder build/nheap.o build/graph.o build/dijkstra.o build/main.o build/narity.o build/heap_insert.o build/heap_update.o
	g++ -o build/run build/main.o  build/nheap.o build/graph.o build/dijkstra.o
	g++ -o build/narity build/narity.o  build/nheap.o build/graph.o build/dijkstra.o
	g++ -o build/heap_insert build/heap_insert.o  build/nheap.o build/graph.o build/dijkstra.o
	g++ -o build/heap_update build/heap_update.o  build/nheap.o build/graph.o build/dijkstra.o

#	g++ -o build/run -g -std=c++11 src/nheap/nheap.cpp src/graph/graph.cpp src/dijkstra/dijkstra.cpp src/main.cpp

build_folder:
	mkdir -p build

clean:
	rm -r build
