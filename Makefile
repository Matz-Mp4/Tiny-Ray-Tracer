CXX = g++
CXXFLAGS = -std=c++20 #-Wall -Werror -Wextra -Wpedantic

BIN_PATH = bin
SRC_PATH = src/*.cpp
INCLUDE_PATH = -Isrc/math/*.cpp

EXECUTABLE = octracer

all: clean build

build:
	$(CXX) $(CXXFLAGS) $(SRC_PATH) $(INCLUDE_PATH) -o bin/$(EXECUTABLE)

clean:
	rm -rf bin/*

test:
	$(CXX) $(CXXFLAGS) tests/*.cpp src/math/*.cpp -Isrc/math -o bin/tests -fpermissive
	./bin/tests
