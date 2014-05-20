CXX = g++
DEBUG = -g

CXXFLAGS = -ansi -Wall -pedantic -O3 $(DEBUG) -I include/
LDFLAGS = -lSDL2 -lGL -lGLEW

TARGET = bin
OBJ = obj

SRC = src
INCLUDE = include/breakout

SOURCES = $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/**/*.cpp)
HEADERS = $(wildcard $(INCLUDE)/*.h) $(wildcard $(INCLUDE)/**/*.h)
OBJECTS = $(addprefix $(OBJ)/, $(notdir $(SOURCES:.cpp=.o)))

EXE = breakout

all: $(TARGET)/$(EXE)

$(TARGET)/$(EXE): $(OBJECTS) | $(TARGET)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(TARGET)/$(EXE)

$(OBJECTS): | $(OBJ)

$(OBJ)/%.o: $(SRC)/gl/%.cpp $(INCLUDE)/gl/%.h
	$(CXX) -c $< $(CXXFLAGS) -o $@
	
$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CXX) -c $< $(CXXFLAGS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

$(OBJ):
	mkdir $(OBJ)

$(TARGET):
	mkdir $(TARGET)

.PHONY : print
print:
	@echo "sources :" $(SOURCES)
	@echo "objects :" $(OBJECTS)
	@echo "headers :" $(HEADERS)

.PHONY : clean
clean:
	rm -f $(OBJECTS) $(TARGET)/$(EXE) 

.PHONY : remove
remove:
	rm -rf $(OBJ) $(TARGET) 

