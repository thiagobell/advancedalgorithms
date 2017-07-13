####cristofides package

DIRS := src/blossom5 src/blossom5/MinCost src/blossom5/GEOM

SOURCES := $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
OBJS := $(patsubst %.cpp, %.o, $(SOURCES))

CFLAGS := -O3 -D_NDEBUG -g
#CFLAGS :=  -g -ggdb
CXX ?= c++
LIBS :=
INCLUDES :=
LIBDIR :=

# Add librt if the target platform is not Darwin (OS X)
ifneq ($(shell uname -s),Darwin)
    LIBS += -lrt
endif


#build/blossom5: ${OBJS}
#	$(CXX) $(CFLAGS) ${LIBDIR} -o $@ ${OBJS} ${LIBS}

*.cpp.o:
	$(CXX) $(CFLAGS) ${INCLUDES} $(basename $<) -c -o $(@F)

#clean:
#	rm -f ${OBJS} blossom5

## own code
buildfolder:
	mkdir -p build
build/graph.o: src/graph/graph.cpp
	g++ -g -O3 -o build/graph.o -std=c++11 -c src/graph/graph.cpp
build/main.o: src/main.cpp
	g++ -g -O3 -std=c++11  -o build/main.o -c src/main.cpp
build/cristofides.o: src/cristofides.cpp
		g++ -g -O3 -o build/cristofides.o -std=c++11 -c src/cristofides.cpp
build/cristofides: build/main.o build/graph.o build/cristofides.o ${OBJS}
	g++ -g -O3 -o build/cristofides -std=c++11 build/main.o build/cristofides.o build/graph.o ${OBJS}

clean:
	rm -r build

all: buildfolder build/cristofides
