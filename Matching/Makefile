build/graph.o: src/graph/graph.cpp
	g++ -g -O -o build/graph.o -std=c++11 -c src/graph/graph.cpp
build/main.o: src/main.cpp
	g++ -g -O -o build/main.o -std=c++11 -c src/main.cpp
build/hpmatch.o: src/hpmatch/hpmatch.cpp
	g++ -g -O -o build/hpmatch.o -std=c++11 -c src/hpmatch/hpmatch.cpp
build/matching: build/main.o build/graph.o build/hpmatch.o
	g++ -g -O -o build/matching build/main.o  build/graph.o build/hpmatch.o

buildfolder:
	mkdir -p build

all: buildfolder build/matching

clean:
	rm -r build
