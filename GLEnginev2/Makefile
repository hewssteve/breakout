
CC = g++
DEBUG = -g

CFLAGS = -ansi -Wall -pedantic $(DEBUG)
LDFLAGS = -lSDLmain -lSDL2 -lGL -lGLEW

CPP = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.h) 
OBJECTS =  $(patsubst src/%.cpp, obj/%.o, $(CPP))

EXE = gl_test

all: $(EXE)

$(EXE): $(OBJECTS) $(HEADERS)
	$(CC) $(OBJECTS) -o $(EXE) $(LDFLAGS) 

obj/%.o: src/%.cpp src%.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXE) $(OBJECTS)