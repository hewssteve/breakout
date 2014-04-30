CXX = g++
DEBUG = -g

CXXFLAGS = -ansi -Wall -pedantic $(DEBUG) -I $(INCLUDE)
LDFLAGS = -lSDL2 -lGL -lGLEW

TARGET = bin/
OBJ = obj/

SRC = src/
INCLUDE = include/

SOURCES = $(wildcard $(SRC)*.cpp) $(wildcard $(SRC)**/*.cpp)
HEADERS = $(wildcard $(INCLUDE)*.h) $(wildcard $(INCLUDE)**/*.h)
OBJECTS = $(SOURCES:.cpp=.o) 

EXE = breakout

all: $(TARGET)$(EXE) | $(TARGET)

$(TARGET)$(EXE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(TARGET)$(EXE)

$(OBJECTS): | $(OBJ)

$(OBJ):
	mkdir $(OBJ)

$(TARGET):
	mkdir $(TARGET)

.PHONY : test
test:
	@echo $(SOURCES)
	@echo $(OBJECTS)
	@echo $(HEADERS)

.PHONY : clean
clean:
	rm -f $(OBJECTS) $(TARGET)$(EXE)

