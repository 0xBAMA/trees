CC = g++

MAKE_EXE = -o exe -time -std=c++11

GL_FLAGS = -lglut -lGLEW -lGL -lGLU

# LODEPNG_FLAGS = resources/LodePNG/lodepng.cpp -ansi -O3 -std=c++11

#UNNECCESARY_DEBUG = -Wall -Wextra -pedantic

all: build

build: main.cc
	# $(CC) main.cc $(GL_FLAGS) $(LODEPNG_FLAGS) $(MAKE_EXE)
	$(CC) main.cc $(MAKE_EXE)
	./exe
