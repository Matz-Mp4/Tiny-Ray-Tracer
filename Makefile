CXX = g++
CXXFLAGS = -std=c++20 #-Wall -Werror -Wextra -Wpedantic 
LIBS = -lSDL2

BIN_PATH = bin
SRC_PATH = src/*.cpp
INCLUDE_PATH = src/math/*.cpp src/utilities/*.cpp src/world/*.cpp src/geometric_objects/*.cpp src/tracers/*.cpp

EXECUTABLE = render_man 

all: clean build

build:
	$(CXX) $(CXXFLAGS) $(SRC_PATH) $(INCLUDE_PATH) $(LIBS) -o bin/$(EXECUTABLE) 

clean:
	rm -rf bin/*

test:
	$(CXX) $(CXXFLAGS) tests/*.cpp src/math/*.cpp -Isrc/math -o bin/tests 
	./bin/tests

run:
	./bin/render_man
