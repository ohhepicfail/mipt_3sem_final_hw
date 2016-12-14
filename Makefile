CXX = g++
CXXFLAGS = -c -Wall -Wextra -pedantic -Werror -Wno-return-local-addr -std=c++14 -g3 -Wswitch-default -Wmaybe-uninitialized -Wredundant-decls -O2

all: build clean

build: compile_point compile_io compile_main
	$(CXX) point.o io.o main.o -o spheres

compile_main:  main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

compile_io:  io.cpp
	$(CXX) $(CXXFLAGS) io.cpp 


compile_point:  point.cpp
	$(CXX) $(CXXFLAGS) point.cpp


clean:
	rm -rf *.o
	
