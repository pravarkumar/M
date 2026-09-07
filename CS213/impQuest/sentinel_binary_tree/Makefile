CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

all: bst

bst: main.o bst.o
	$(CXX) $(CXXFLAGS) -o bst main.o bst.o

main.o: main.cpp bst.h
	$(CXX) $(CXXFLAGS) -c main.cpp

bst.o: bst.cpp bst.h
	$(CXX) $(CXXFLAGS) -c bst.cpp

clean:
	rm -f bst main.o bst.o

build: bst

run: bst
	./bst

.PHONY: all clean build run
