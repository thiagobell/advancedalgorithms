buildfolder:
	mkdir -p build
build/graph.o: src/graph/graph.cpp
	g++ -g -O3 -o build/graph.o -std=c++11 -c src/graph/graph.cpp
build/main.o: src/main.cpp
	g++ -g -O3 -std=c++11  -o build/main.o -c src/main.cpp

build/cristofides: build/main.o build/graph.o
		g++ -g -O3 -o build/cristofides -std=c++11 build/main.o  build/graph.o


all: buildfolder build/cristofides
