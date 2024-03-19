CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror -Wextra -Wpedantic

EXECUTABLE = octracer

all: clean build

build:
	$(CXX) $(CXXFLAGS) src/*.cpp -o bin/$(EXECUTABLE)

clean:
	rm -rf bin/*
